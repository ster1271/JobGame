#include "CollisionManager.h"

//プレイヤーとマップの当たり判定
void CCollisionManager::PlayerToMap(CPlayer& cPlayer, CMapManager& cMapManager)
{
	VECTOR PlayerPos = cPlayer.GetPos();
	VECTOR PlayerNextPos = cPlayer.GetNextPos();
	VECTOR PlayerSize = cPlayer.GetSize();
	VECTOR PlayerHarfSize = VScale(PlayerSize, 0.5f);

	vector<MapInfo>MapList = cMapManager.GetMap().GetMapInfo();
	VECTOR MapSize = cMapManager.GetMap().GetMapSize();
	VECTOR MapHarfSize = VScale(cMapManager.GetMap().GetMapSize(), 0.5f);

	//めり込み量を格納する変数を生成
	float Overlap;

	//X方向のみ調べる
	PlayerPos.x = PlayerNextPos.x;
	for (int MapIndex = 0; MapIndex < MapList.size(); MapIndex)
	{
		//オブジェクトが置かれてない場合は計算しない
		if (MapList[MapIndex].IsMap == false)
			continue;

		if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, MapList[MapIndex].vPos, MapSize))
		{
			Overlap = 0.0f;

			//左から当たった時
			if (PlayerPos.x < MapList[MapIndex].vPos.x)
			{
				Overlap = (PlayerPos.x + PlayerHarfSize.x) - (MapList[MapIndex].vPos.x - MapHarfSize.x);
			}
			//右から当たった時
			else
			{
				Overlap = (MapList[MapIndex].vPos.x + MapHarfSize.x) - (PlayerPos.x - PlayerHarfSize.x);
			}

			PlayerNextPos.x += Overlap;
		}
	}

	//Y方向のみ調べる
	PlayerPos.y = cPlayer.GetNextPos().y;
	for (int MapIndex = 0; MapIndex < MapList.size(); MapIndex)
	{
		//オブジェクトが置かれてない場合は計算しない
		if (MapList[MapIndex].IsMap == false)
			continue;

		if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, MapList[MapIndex].vPos, MapSize))
		{
			Overlap = 0.0f;

			//左から当たった時
			if (PlayerPos.y < MapList[MapIndex].vPos.y)
			{
				Overlap = (PlayerPos.y + PlayerHarfSize.y) - (MapList[MapIndex].vPos.y - MapHarfSize.y);
			}
			//右から当たった時
			else
			{
				Overlap = (MapList[MapIndex].vPos.y + MapHarfSize.y) - (PlayerPos.y - PlayerHarfSize.y);
			}

			PlayerNextPos.y += Overlap;
		}
	}

	//Z方向のみ調べる
	PlayerPos.z = cPlayer.GetNextPos().z;
	for (int MapIndex = 0; MapIndex < MapList.size(); MapIndex)
	{
		//オブジェクトが置かれてない場合は計算しない
		if (MapList[MapIndex].IsMap == false)
			continue;

		if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, MapList[MapIndex].vPos, MapSize))
		{
			Overlap = 0.0f;

			//左から当たった時
			if (PlayerPos.z < MapList[MapIndex].vPos.z)
			{
				Overlap = (PlayerPos.z + PlayerHarfSize.z) - (MapList[MapIndex].vPos.z - MapHarfSize.z);
			}
			//右から当たった時
			else
			{
				Overlap = (MapList[MapIndex].vPos.z + MapHarfSize.z) - (PlayerPos.z - PlayerHarfSize.z);
			}

			PlayerNextPos.z += Overlap;
		}
	}

	cPlayer.SetNextPos(PlayerNextPos);
}


//敵とマップの当たり判定
void CCollisionManager::EnemyToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager)
{

}


//タレットの弾と敵の当たり判定
void CCollisionManager::TurretShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	//弾の数分回す
	for (int shotIndex = 0; shotIndex < TURRET_SHOT_NUM; shotIndex++)
	{
		//弾情報を格納する
		CTurretShot& cTShot = cShotManager.GetTurretShotInfo(shotIndex);
		float ShotRadius = cTShot.GetRadius();

		//フラグがfalseならfor文を次に変更する
		if (!cTShot.GetIsActive())
			continue;


		//敵の数分回す
		for (int enemyIndex = 0; enemyIndex < ENEMY_NUM; enemyIndex++)
		{
			//敵情報を格納する
			CEnemy_Normal& cENormal = cEnemyManager.GetEnemy(enemyIndex);
			float EnemyRadius = cENormal.GetRadius();

			//フラグがfalseならfor文を次に変更する
			if (!cENormal.GetActive())
				continue;

			//当たり判定
			if (CCollision::CheckHitSphereToSphere(cTShot.GetPos(), ShotRadius, cENormal.GetPosition(), EnemyRadius))
			{
				cTShot.HitCalc();	//弾のフラグをおる
				cENormal.HitCalc();	//敵のHPを減らす
			}
		}
	}
}


//プレイヤーの弾と敵の当たり判定
void CCollisionManager::PlayerShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	//弾の数分回す
	for (int shotIndex = 0; shotIndex < PL_SHOT_NUM; shotIndex++)
	{
		//弾情報を格納する
		CPlayerShot& cPShot = cShotManager.GetPlayerShotInfo(shotIndex);
		float ShotRadius = cPShot.GetRadius();

		//フラグがfalseならfor文を次に変更する
		if (!cPShot.GetIsActive())
			continue;


		//敵の数分回す
		for (int enemyIndex = 0; enemyIndex < ENEMY_NUM; enemyIndex++)
		{
			//敵情報を格納する
			CEnemy_Normal& cENormal = cEnemyManager.GetEnemy(enemyIndex);
			float EnemyRadius = cENormal.GetRadius();

			//フラグがfalseならfor文を次に変更する
			if (!cENormal.GetActive())
				continue;

			//当たり判定
			if (CCollision::CheckHitSphereToSphere(cPShot.GetPos(), ShotRadius, cENormal.GetPosition(), EnemyRadius))
			{
				cPShot.HitCalc();	//弾のフラグをおる
				cENormal.HitCalc();	//敵のHPを減らす
			}
		}
	}
}




