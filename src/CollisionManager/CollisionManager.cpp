#include "CollisionManager.h"

void CCollisionManager::Draw()
{
	if (IsCheck == true)
	{
		DrawString(0, 285, "当たった", GetColor(255, 0, 0));
	}

	DrawFormatString(0, 300, GetColor(255, 0, 0), "めり込み量：%f", Tmp_OverRap);
	
}

//プレイヤーとマップの当たり判定
void CCollisionManager::PlayerToMap(CPlayer& cPlayer, CMapManager& cMapManager)
{
	//めり込み量を格納する変数を生成
	float OverRap = 0.0f;

	//プレイヤーの情報を格納する
	VECTOR PlayerPos = cPlayer.GetPos();					//座標
	VECTOR NextPlayerPos = cPlayer.GetNextPos();			//1フレーム後の座標
	VECTOR Player_Size = VGet(15.0f, 30.0f, 15.0f);			//プレイヤーのサイズ
	VECTOR Player_Harf_Size = VScale(Player_Size, 0.5f);	//プレイヤーのハーフサイズ

	bool Dir[DIR_NUM] = { false };
	for (int Index = 0; Index < DIR_NUM; Index++)
	{
		//方向フラグを取得してくる
		Dir[Index] = cPlayer.GetDir(Index);
	}

	//マップの情報を格納する
	vector<MapInfo> MapInfoList = cMapManager.GetMap().GetMapInfo();	//リストをもらう

	VECTOR Map_Size = VGet(50.0f, 50.0f, 50.0f);	//1ブロックのサイズ
	VECTOR Map_Harf_Size = VScale(Map_Size, 0.5f);	//1ブロックのハーフサイズ

	//リストのサイズ分回す
	for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
	{
		//もしフラグがfalseなら計算しない
		if (!MapInfoList[MapIndex].IsMap)
			continue;

		//X軸のみで計算する
		PlayerPos.x = NextPlayerPos.x;

		if (CCollision::CheckHitBoxToBox(PlayerPos, Player_Size, MapInfoList[MapIndex].vPos, Map_Size))
		{
			IsCheck = true;
			
			//初期化しておく
			OverRap = 0.0f;

			/*どちら側から当たったかを判定する*/
			//右から当たった場合
			if (Dir[DIR_RIGHT] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.x - Map_Harf_Size.x) - (PlayerPos.x + Player_Harf_Size.x);
			}
			//左から当たった場合
			if(Dir[DIR_LEFT] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.x + Map_Harf_Size.x) - (PlayerPos.x - Player_Harf_Size.x);
			}

			NextPlayerPos.x += OverRap;	
		}
	}


	//リストのサイズ分回す
	for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
	{
		//もしフラグがfalseなら計算しない
		if (!MapInfoList[MapIndex].IsMap)
			continue;

		//Y軸のみで計算する
		PlayerPos.y = NextPlayerPos.y;

		if (CCollision::CheckHitBoxToBox(PlayerPos, Player_Size, MapInfoList[MapIndex].vPos, Map_Size))
		{
			IsCheck = true;

			//初期化しておく
			OverRap = 0.0f;

			/*どちら側から当たったかを判定する*/
			//上から当たった場合
			if (Dir[DIR_UP] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.y - Map_Harf_Size.y) - (PlayerPos.y + Player_Harf_Size.y);
			}
			//下から当たった場合
			if (Dir[DIR_DOWN] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.y + Map_Harf_Size.y) - (PlayerPos.y - Player_Harf_Size.y);
			}

			NextPlayerPos.y += OverRap;
		}
	}


	//リストのサイズ分回す
	for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
	{
		//もしフラグがfalseなら計算しない
		if (!MapInfoList[MapIndex].IsMap)
			continue;

		//Z軸のみで計算する
		PlayerPos.z = NextPlayerPos.z;

		if (CCollision::CheckHitBoxToBox(PlayerPos, Player_Size, MapInfoList[MapIndex].vPos, Map_Size))
		{
			IsCheck = true;

			//初期化しておく
			OverRap = 0.0f;

			/*どちら側から当たったかを判定する*/
			//奥から当たった場合
			if (Dir[DIR_BACK] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.z - Map_Harf_Size.z) - (PlayerPos.z + Player_Harf_Size.z);
			}
			//手前から当たった場合
			if (Dir[DIR_NEAR] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.z + Map_Harf_Size.z) - (PlayerPos.z - Player_Harf_Size.z);
			}

			NextPlayerPos.z += OverRap;
		}
	}
	cPlayer.SetNextPos(NextPlayerPos);
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




