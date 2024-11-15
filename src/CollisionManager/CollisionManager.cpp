#include "CollisionManager.h"

void CCollisionManager::Draw()
{
}

//�v���C���[�ƃ}�b�v�̓����蔻��
void CCollisionManager::PlayerToMap(CPlayer& cPlayer, CMapManager& cMapManager)
{
	//�߂荞�ݗʂ��i�[����ϐ��𐶐�
	float OverRap = 0.0f;

	//�v���C���[�̏����i�[����
	VECTOR PlayerPos = cPlayer.GetPos();					//���W
	VECTOR NextPlayerPos = cPlayer.GetNextPos();			//1�t���[����̍��W
	VECTOR Player_Size = PLAYER_SIZE;						//�v���C���[�̃T�C�Y
	VECTOR Player_Harf_Size = VScale(Player_Size, 0.5f);	//�v���C���[�̃n�[�t�T�C�Y

	bool Dir[DIR_NUM] = { false };
	for (int Index = 0; Index < DIR_NUM; Index++)
	{
		//�����t���O���擾���Ă���
		Dir[Index] = cPlayer.GetDir(Index);
	}

	//�}�b�v�̏����i�[����
	vector<MapInfo> MapInfoList = cMapManager.GetMap().GetMapInfo();	//���X�g�����炤

	VECTOR Map_Size = MAP_SIZE;						//1�u���b�N�̃T�C�Y
	VECTOR Map_Harf_Size = VScale(Map_Size, 0.5f);	//1�u���b�N�̃n�[�t�T�C�Y

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
			//���������Ă���
			OverRap = 0.0f;

			/*�ǂ��瑤���瓖���������𔻒肷��*/
			//�E���瓖�������ꍇ
			if (Dir[DIR_RIGHT] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.x - Map_Harf_Size.x) - (PlayerPos.x + Player_Harf_Size.x);
			}
			//�����瓖�������ꍇ
			if(Dir[DIR_LEFT] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.x + Map_Harf_Size.x) - (PlayerPos.x - Player_Harf_Size.x);
			}

			NextPlayerPos.x += OverRap;	
		}
	}


	//���X�g�̃T�C�Y����
	for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
	{
		//�����t���O��false�Ȃ�v�Z���Ȃ�
		if (!MapInfoList[MapIndex].IsMap)
			continue;

		//Y���݂̂Ōv�Z����
		PlayerPos.y = NextPlayerPos.y;

		if (CCollision::CheckHitBoxToBox(PlayerPos, Player_Size, MapInfoList[MapIndex].vPos, Map_Size))
		{
			//���������Ă���
			OverRap = 0.0f;

			/*�ǂ��瑤���瓖���������𔻒肷��*/
			//�ォ�瓖�������ꍇ
			if (Dir[DIR_UP] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.y - Map_Harf_Size.y) - (PlayerPos.y + Player_Harf_Size.y);
			}
			//�����瓖�������ꍇ
			if (Dir[DIR_DOWN] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.y + Map_Harf_Size.y) - (PlayerPos.y - Player_Harf_Size.y);
			}

			NextPlayerPos.y += OverRap;
		}
	}


	//���X�g�̃T�C�Y����
	for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
	{
		//�����t���O��false�Ȃ�v�Z���Ȃ�
		if (!MapInfoList[MapIndex].IsMap)
			continue;

		//Z���݂̂Ōv�Z����
		PlayerPos.z = NextPlayerPos.z;

		if (CCollision::CheckHitBoxToBox(PlayerPos, Player_Size, MapInfoList[MapIndex].vPos, Map_Size))
		{
			//���������Ă���
			OverRap = 0.0f;

			/*�ǂ��瑤���瓖���������𔻒肷��*/
			//�����瓖�������ꍇ
			if (Dir[DIR_BACK] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.z - Map_Harf_Size.z) - (PlayerPos.z + Player_Harf_Size.z);
			}
			//��O���瓖�������ꍇ
			if (Dir[DIR_NEAR] == true)
			{
				OverRap = (MapInfoList[MapIndex].vPos.z + Map_Harf_Size.z) - (PlayerPos.z - Player_Harf_Size.z);
			}

			NextPlayerPos.z += OverRap;
		}
	}
	cPlayer.SetNextPos(NextPlayerPos);
}


//�G�ƃ}�b�v�̓����蔻��
void CCollisionManager::Enemy1ToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager)
{
	//�}�b�v�̏����i�[����
	vector<MapInfo> MapInfoList = cMapManager.GetMap().GetMapInfo();	//���X�g�����炤
	VECTOR Map_Size = MAP_SIZE;						//1�u���b�N�̃T�C�Y
	VECTOR Map_Harf_Size = VScale(Map_Size, 0.5f);	//1�u���b�N�̃n�[�t�T�C�Y

	for (int enemyIndex = 0; enemyIndex < ENEMY_MAXNUM; enemyIndex++)
	{
		//�߂荞�ݗʂ��i�[����ϐ��𐶐�
		float OverRap = 0.0f;

		//�G�����i�[����
		CEnemy_Normal& cENormal = cEnemyManager.GetEnemy(enemyIndex);	//�������炤
		VECTOR EnemyPos = cENormal.GetPosition();						//���W
		VECTOR NextEnemyPos = cENormal.GetNextPosision();				//1�t���[����̍��W
		VECTOR EnemySize = ENEMY_NORMAL_SIZE;							//�T�C�Y
		VECTOR Enemy_Harf_Size = VScale(EnemySize, 0.5f);				//�n�[�t�T�C�Y
		bool Dir[DIR_NUM] = { false };									//�����t���O
		for (int Index = 0; Index < DIR_NUM; Index++)
		{
			//�����t���O���擾���Ă���
			Dir[Index] = cENormal.GetDir(Index);
		}


		//�t���O��false�Ȃ�for�������ɕύX����
		if (!cENormal.GetActive())
			continue;

		//���X�g�̃T�C�Y����
		for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
		{
			//�����t���O��false�Ȃ�v�Z���Ȃ�
			if (!MapInfoList[MapIndex].IsMap)
				continue;

			//X���݂̂Ōv�Z����
			EnemyPos.x = NextEnemyPos.x;
			if (CCollision::CheckHitBoxToBox(EnemyPos, EnemySize, MapInfoList[MapIndex].vPos, Map_Size))
			{

				//���������Ă���
				OverRap = 0.0f;

				/*�ǂ��瑤���瓖���������𔻒肷��*/
				//�E���瓖�������ꍇ
				if (Dir[ENEMY_DIR_RIGHT] == true)
				{
					OverRap = (MapInfoList[MapIndex].vPos.x - Map_Harf_Size.x) - (EnemyPos.x + Enemy_Harf_Size.x);
				}
				//�����瓖�������ꍇ
				if (Dir[ENEMY_DIR_LEFT] == true)
				{
					OverRap = (MapInfoList[MapIndex].vPos.x + Map_Harf_Size.x) - (EnemyPos.x - Enemy_Harf_Size.x);
				}

				NextEnemyPos.x += OverRap;
			}
		}

		//���X�g�̃T�C�Y����
		for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
		{
			//�����t���O��false�Ȃ�v�Z���Ȃ�
			if (!MapInfoList[MapIndex].IsMap)
				continue;

			//X���݂̂Ōv�Z����
			EnemyPos.y = NextEnemyPos.y;
			if (CCollision::CheckHitBoxToBox(EnemyPos, EnemySize, MapInfoList[MapIndex].vPos, Map_Size))
			{

				//���������Ă���
				OverRap = 0.0f;

				/*�ǂ��瑤���瓖���������𔻒肷��*/
				//�E���瓖�������ꍇ
				if (Dir[ENEMY_DIR_UP] == true)
				{
					OverRap = (MapInfoList[MapIndex].vPos.y - Map_Harf_Size.y) - (EnemyPos.y + Enemy_Harf_Size.y);
				}
				//�����瓖�������ꍇ
				if (Dir[ENEMY_DIR_DOWN] == true)
				{
					OverRap = (MapInfoList[MapIndex].vPos.y + Map_Harf_Size.y) - (EnemyPos.y - Enemy_Harf_Size.y);
				}

				NextEnemyPos.y += OverRap;
			}
		}

		//���X�g�̃T�C�Y����
		for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
		{
			//�����t���O��false�Ȃ�v�Z���Ȃ�
			if (!MapInfoList[MapIndex].IsMap)
				continue;

			//X���݂̂Ōv�Z����
			EnemyPos.z = NextEnemyPos.z;
			if (CCollision::CheckHitBoxToBox(EnemyPos, EnemySize, MapInfoList[MapIndex].vPos, Map_Size))
			{

				//���������Ă���
				OverRap = 0.0f;

				/*�ǂ��瑤���瓖���������𔻒肷��*/
				//�E���瓖�������ꍇ
				if (Dir[ENEMY_DIR_BACK] == true)
				{
					OverRap = (MapInfoList[MapIndex].vPos.z - Map_Harf_Size.z) - (EnemyPos.z + Enemy_Harf_Size.z);
				}
				//�����瓖�������ꍇ
				if (Dir[ENEMY_DIR_NEAR] == true)
				{
					OverRap = (MapInfoList[MapIndex].vPos.z + Map_Harf_Size.z) - (EnemyPos.z - Enemy_Harf_Size.z);
				}

				NextEnemyPos.z += OverRap;
			}
		}
		
		//Next���W�̍X�V
		cENormal.SetNextPosision(NextEnemyPos);
	}
}


//�G2�ƃ}�b�v�̓����蔻��
void CCollisionManager::Enemy2ToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager)
{
	//�G�̏����i�[����


	//�}�b�v�̏����i�[����
	vector<MapInfo> MapInfoList = cMapManager.GetMap().GetMapInfo();	//���X�g�����炤
	VECTOR Map_Size = MAP_SIZE;						//1�u���b�N�̃T�C�Y
	VECTOR Map_Harf_Size = VScale(Map_Size, 0.5f);	//1�u���b�N�̃n�[�t�T�C�Y
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
		for (int enemyIndex = 0; enemyIndex < ENEMY_MAXNUM; enemyIndex++)
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
		for (int enemyIndex = 0; enemyIndex < ENEMY_MAXNUM; enemyIndex++)
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




