#include "CollisionManager.h"

void CCollisionManager::Draw()
{
	if (IsCheck == true)
	{
		DrawString(0, 285, "��������", GetColor(255, 0, 0));
	}

	DrawFormatString(0, 300, GetColor(255, 0, 0), "�߂荞�ݗʁF%f", Tmp_OverRap);
}

//�v���C���[�ƃ}�b�v�̓����蔻��
void CCollisionManager::PlayerToMap(CPlayer& cPlayer, CMapManager& cMapManager)
{
	const int MAP_DIR = 6;

	//�߂荞�ݗʂ��i�[����ϐ��𐶐�
	float OverRap = 0.0f;

	//�v���C���[�̏����i�[����
	VECTOR PlayerPos = cPlayer.GetPos();
	VECTOR NextPlayerPos = cPlayer.GetNextPos();
	VECTOR Player_Size = VGet(15.0f, 50.0f, 15.0f);
	VECTOR Player_Harf_Size = VScale(Player_Size, 0.5f);

	bool Dir[MAP_DIR] = { false };
	if (NextPlayerPos.x > PlayerPos.x)
	{
		//�E�ɓ����Ă���
		Dir[0] = true;
	}
	if (NextPlayerPos.x < PlayerPos.x)
	{
		//���ɓ����Ă���
		Dir[1] = true;
	}
	if (NextPlayerPos.y > PlayerPos.y)
	{
		//��ɓ����Ă���
		Dir[2] = true;
	}
	if (NextPlayerPos.y < PlayerPos.y)
	{
		//���ɓ����Ă���
		Dir[3] = true;
	}
	if (NextPlayerPos.z > PlayerPos.z)
	{
		//���ɓ����Ă���
		Dir[4] = true;
	}
	if (NextPlayerPos.z < PlayerPos.z)
	{
		//��O�ɓ����Ă���
		Dir[5] = true;
	}


	//�}�b�v�̏����i�[����
	vector<MapInfo> MapInfoList = cMapManager.GetMap().GetMapInfo();
	VECTOR Map_Size = VGet(50.0f, 50.0f, 50.0f);
	VECTOR Map_Harf_Size = VScale(Map_Size, 0.5f);

	//���X�g�̃T�C�Y����
	for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
	{
		//�����t���O��false�Ȃ�v�Z���Ȃ�
		if (!MapInfoList[MapIndex].IsMap)
			continue;

		//X���݂̂Ōv�Z����
		PlayerPos.x = NextPlayerPos.x;
		if (CCollision::CheckHitBoxToBox(PlayerPos, Player_Size, MapInfoList[MapIndex].vPos, Map_Size))
		{
			IsCheck = true;
			
			//���������Ă���
			OverRap = 0.0f;

			/*�ǂ��瑤���瓖���������𔻒肷��*/
			//�E���瓖�������ꍇ
			if (Dir[0] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.x + Map_Harf_Size.x) - (PlayerPos.x - Player_Harf_Size.x);
				Tmp_OverRap = OverRap;
			}
			//�����瓖�������ꍇ
			if(Dir[1] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.x - Map_Harf_Size.x) - (PlayerPos.x + Player_Harf_Size.x);
				Tmp_OverRap = OverRap;
			}

			NextPlayerPos.x -= OverRap;
			
		}
		else
		{
			IsCheck = false;
		}

		cPlayer.SetNextPos(NextPlayerPos);
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




