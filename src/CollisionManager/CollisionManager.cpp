#include "CollisionManager.h"

//�v���C���[�ƃ}�b�v�̓����蔻��
void CCollisionManager::PlayerToMap(CPlayer& cPlayer, CMap& cMap)
{
	VECTOR PlayerPos = cPlayer.GetPos();
	VECTOR PlayerSize = cPlayer.GetSize();
	VECTOR PlayerHarfSize = VScale(PlayerSize, 0.5f);

	vector<MapInfo>MapList = cMap.GetMapInfo();


	for (int MapIndex = 0; MapIndex < MapList.size(); MapIndex)
	{
		if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, MapList[MapIndex].vPos, cMap.GetMapSize()))
		{

		}
	}
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




