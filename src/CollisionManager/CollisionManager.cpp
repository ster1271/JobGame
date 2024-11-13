#include "CollisionManager.h"

//�v���C���[�ƃ}�b�v�̓����蔻��
void CCollisionManager::PlayerToMap(CPlayer& cPlayer, CMapManager& cMapManager)
{
	VECTOR PlayerPos = cPlayer.GetPos();
	VECTOR PlayerNextPos = cPlayer.GetNextPos();
	VECTOR PlayerSize = cPlayer.GetSize();
	VECTOR PlayerHarfSize = VScale(PlayerSize, 0.5f);

	vector<MapInfo>MapList = cMapManager.GetMap().GetMapInfo();
	VECTOR MapSize = cMapManager.GetMap().GetMapSize();
	VECTOR MapHarfSize = VScale(cMapManager.GetMap().GetMapSize(), 0.5f);

	//�߂荞�ݗʂ��i�[����ϐ��𐶐�
	float Overlap;

	//X�����̂ݒ��ׂ�
	PlayerPos.x = PlayerNextPos.x;
	for (int MapIndex = 0; MapIndex < MapList.size(); MapIndex)
	{
		//�I�u�W�F�N�g���u����ĂȂ��ꍇ�͌v�Z���Ȃ�
		if (MapList[MapIndex].IsMap == false)
			continue;

		if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, MapList[MapIndex].vPos, MapSize))
		{
			Overlap = 0.0f;

			//�����瓖��������
			if (PlayerPos.x < MapList[MapIndex].vPos.x)
			{
				Overlap = (PlayerPos.x + PlayerHarfSize.x) - (MapList[MapIndex].vPos.x - MapHarfSize.x);
			}
			//�E���瓖��������
			else
			{
				Overlap = (MapList[MapIndex].vPos.x + MapHarfSize.x) - (PlayerPos.x - PlayerHarfSize.x);
			}

			PlayerNextPos.x += Overlap;
		}
	}

	//Y�����̂ݒ��ׂ�
	PlayerPos.y = cPlayer.GetNextPos().y;
	for (int MapIndex = 0; MapIndex < MapList.size(); MapIndex)
	{
		//�I�u�W�F�N�g���u����ĂȂ��ꍇ�͌v�Z���Ȃ�
		if (MapList[MapIndex].IsMap == false)
			continue;

		if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, MapList[MapIndex].vPos, MapSize))
		{
			Overlap = 0.0f;

			//�����瓖��������
			if (PlayerPos.y < MapList[MapIndex].vPos.y)
			{
				Overlap = (PlayerPos.y + PlayerHarfSize.y) - (MapList[MapIndex].vPos.y - MapHarfSize.y);
			}
			//�E���瓖��������
			else
			{
				Overlap = (MapList[MapIndex].vPos.y + MapHarfSize.y) - (PlayerPos.y - PlayerHarfSize.y);
			}

			PlayerNextPos.y += Overlap;
		}
	}

	//Z�����̂ݒ��ׂ�
	PlayerPos.z = cPlayer.GetNextPos().z;
	for (int MapIndex = 0; MapIndex < MapList.size(); MapIndex)
	{
		//�I�u�W�F�N�g���u����ĂȂ��ꍇ�͌v�Z���Ȃ�
		if (MapList[MapIndex].IsMap == false)
			continue;

		if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, MapList[MapIndex].vPos, MapSize))
		{
			Overlap = 0.0f;

			//�����瓖��������
			if (PlayerPos.z < MapList[MapIndex].vPos.z)
			{
				Overlap = (PlayerPos.z + PlayerHarfSize.z) - (MapList[MapIndex].vPos.z - MapHarfSize.z);
			}
			//�E���瓖��������
			else
			{
				Overlap = (MapList[MapIndex].vPos.z + MapHarfSize.z) - (PlayerPos.z - PlayerHarfSize.z);
			}

			PlayerNextPos.z += Overlap;
		}
	}

	cPlayer.SetNextPos(PlayerNextPos);
}


//�G�ƃ}�b�v�̓����蔻��
void CCollisionManager::EnemyToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager)
{

}


//�^���b�g�̒e�ƓG�̓����蔻��
void CCollisionManager::TurretShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	//�e�̐�����
	for (int shotIndex = 0; shotIndex < TURRET_SHOT_NUM; shotIndex++)
	{
		//�e�����i�[����
		CTurretShot& cTShot = cShotManager.GetTurretShotInfo(shotIndex);
		float ShotRadius = cTShot.GetRadius();

		//�t���O��false�Ȃ�for�������ɕύX����
		if (!cTShot.GetIsActive())
			continue;


		//�G�̐�����
		for (int enemyIndex = 0; enemyIndex < ENEMY_NUM; enemyIndex++)
		{
			//�G�����i�[����
			CEnemy_Normal& cENormal = cEnemyManager.GetEnemy(enemyIndex);
			float EnemyRadius = cENormal.GetRadius();

			//�t���O��false�Ȃ�for�������ɕύX����
			if (!cENormal.GetActive())
				continue;

			//�����蔻��
			if (CCollision::CheckHitSphereToSphere(cTShot.GetPos(), ShotRadius, cENormal.GetPosition(), EnemyRadius))
			{
				cTShot.HitCalc();	//�e�̃t���O������
				cENormal.HitCalc();	//�G��HP�����炷
			}
		}
	}
}


//�v���C���[�̒e�ƓG�̓����蔻��
void CCollisionManager::PlayerShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	//�e�̐�����
	for (int shotIndex = 0; shotIndex < PL_SHOT_NUM; shotIndex++)
	{
		//�e�����i�[����
		CPlayerShot& cPShot = cShotManager.GetPlayerShotInfo(shotIndex);
		float ShotRadius = cPShot.GetRadius();

		//�t���O��false�Ȃ�for�������ɕύX����
		if (!cPShot.GetIsActive())
			continue;


		//�G�̐�����
		for (int enemyIndex = 0; enemyIndex < ENEMY_NUM; enemyIndex++)
		{
			//�G�����i�[����
			CEnemy_Normal& cENormal = cEnemyManager.GetEnemy(enemyIndex);
			float EnemyRadius = cENormal.GetRadius();

			//�t���O��false�Ȃ�for�������ɕύX����
			if (!cENormal.GetActive())
				continue;

			//�����蔻��
			if (CCollision::CheckHitSphereToSphere(cPShot.GetPos(), ShotRadius, cENormal.GetPosition(), EnemyRadius))
			{
				cPShot.HitCalc();	//�e�̃t���O������
				cENormal.HitCalc();	//�G��HP�����炷
			}
		}
	}
}




