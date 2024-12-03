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
	vector<WallInfo> MapInfoList = cMapManager.GetMap().GetWallList();	//���X�g�����炤

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
			PlayerPos.x = NextPlayerPos.x;
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
			PlayerPos.y = NextPlayerPos.y;
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


//�G1�ƃ}�b�v�̓����蔻��
void CCollisionManager::Enemy1ToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager)
{
	//�}�b�v�̏����i�[����
	vector<WallInfo> MapInfoList = cMapManager.GetMap().GetWallList();	//���X�g�����炤
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
	vector<WallInfo> MapInfoList = cMapManager.GetMap().GetWallList();	//���X�g�����炤
	VECTOR Map_Size = MAP_SIZE;						//1�u���b�N�̃T�C�Y
	VECTOR Map_Harf_Size = VScale(Map_Size, 0.5f);	//1�u���b�N�̃n�[�t�T�C�Y
}


//�G1���m�̓����蔻��
void CCollisionManager::CheckEnemy1(CEnemyManager& cEnemyManager)
{
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAXNUM; enemyIndex++)
	{
		//�߂荞�ݗʂ��i�[����ϐ��𐶐�
		float OverRap = 0.0f;

		//�G�����i�[����
		CEnemy_Normal& cENormal01 = cEnemyManager.GetEnemy(enemyIndex);	//�������炤
		VECTOR EnemyPos01 = cENormal01.GetPosition();					//���W
		VECTOR NextEnemyPos01 = cENormal01.GetNextPosision();			//1�t���[����̍��W
		VECTOR EnemySize01 = ENEMY_NORMAL_SIZE;							//�T�C�Y
		VECTOR Enemy_Harf_Size01 = VScale(EnemySize01, 0.5f);			//�n�[�t�T�C�Y
		bool Dir01[DIR_NUM] = { false };								//�����t���O
		for (int Index = 0; Index < DIR_NUM; Index++)
		{
			//�����t���O���擾���Ă���
			Dir01[Index] = cENormal01.GetDir(Index);
		}

		//�t���O��false�Ȃ�for�������ɕύX����
		if (!cENormal01.GetActive())
			continue;


		for (int enemyIndex = 0; enemyIndex < ENEMY_MAXNUM; enemyIndex++)
		{
			//�G�����i�[����
			CEnemy_Normal& cENormal02 = cEnemyManager.GetEnemy(enemyIndex);	//�������炤
			VECTOR EnemyPos02 = cENormal02.GetPosition();						//���W
			VECTOR NextEnemyPos02 = cENormal02.GetNextPosision();				//1�t���[����̍��W
			VECTOR EnemySize02 = ENEMY_NORMAL_SIZE;							//�T�C�Y
			VECTOR Enemy_Harf_Size02 = VScale(EnemySize02, 0.5f);				//�n�[�t�T�C�Y
			bool Dir02[DIR_NUM] = { false };									//�����t���O
			for (int Index = 0; Index < DIR_NUM; Index++)
			{
				//�����t���O���擾���Ă���
				Dir02[Index] = cENormal02.GetDir(Index);
			}

			//�t���O��false�Ȃ�for�������ɕύX����
			if (!cENormal02.GetActive())
				continue;


		}

	}
}

//�G2���m�̓����蔻��
void CCollisionManager::CheckEnemy2(CEnemyManager& cEnemyManager)
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


//�v���C���[�̒e�ƃ}�b�v�̓����蔻��
void CCollisionManager::PlayerShotToMap(CShotManager& cShotManager, CMapManager& cMapManager)
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


		//�}�b�v�̏����i�[����
		vector<WallInfo> MapInfoList = cMapManager.GetMap().GetWallList();	//���X�g�����炤

		VECTOR Map_Size = MAP_SIZE;						//1�u���b�N�̃T�C�Y
		VECTOR Map_Harf_Size = VScale(Map_Size, 0.5f);	//1�u���b�N�̃n�[�t�T�C�Y

		//���X�g�̃T�C�Y����
		for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
		{
			//�����t���O��false�Ȃ�v�Z���Ȃ�
			if (!MapInfoList[MapIndex].IsMap)
				continue;

			if (CCollision::CheckHitSphereToSphere(cPShot.GetPos(), SHOT_RADIUS, MapInfoList[MapIndex].vPos, MAP_R))
			{
				cPShot.HitCalc();
			}
		}
	}
}

//�^���b�g�̒e�ƃ}�b�v�̓����蔻��
void CCollisionManager::TurretShotToMap(CShotManager& cShotManager, CMapManager& cMapManager)
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

		//�}�b�v�̏����i�[����
		vector<WallInfo> MapInfoList = cMapManager.GetMap().GetWallList();	//���X�g�����炤

		VECTOR Map_Size = MAP_SIZE;						//1�u���b�N�̃T�C�Y
		VECTOR Map_Harf_Size = VScale(Map_Size, 0.5f);	//1�u���b�N�̃n�[�t�T�C�Y

		//���X�g�̃T�C�Y����
		for (int MapIndex = 0; MapIndex < MapInfoList.size(); MapIndex++)
		{
			//�����t���O��false�Ȃ�v�Z���Ȃ�
			if (!MapInfoList[MapIndex].IsMap)
				continue;

			if (CCollision::CheckHitSphereToSphere(cTShot.GetPos(), SHOT_RADIUS, MapInfoList[MapIndex].vPos, MAP_R))
			{
				cTShot.HitCalc();	//�e�̃t���O������
			}
		}
	}
}


//�S�[���ƃv���C���[�̓����蔻��
void CCollisionManager::PlayerToGoal(CPlayer& cPlayer, CMapManager& cMapManager)
{
	//�߂荞�ݗʂ��i�[����ϐ��𐶐�
	float OverRap = 0.0f;

	//�v���C���[�̏����i�[����
	VECTOR PlayerPos = cPlayer.GetPos();					//���W
	VECTOR NextPlayerPos = cPlayer.GetNextPos();			//1�t���[����̍��W
	VECTOR PlayerSize = PLAYER_SIZE;						//�v���C���[�̃T�C�Y
	VECTOR PlayerHarfSize = VScale(PlayerSize, 0.5f);		//�v���C���[�̃n�[�t�T�C�Y

	bool Dir[DIR_NUM] = { false };
	for (int Index = 0; Index < DIR_NUM; Index++)
	{
		//�����t���O���擾���Ă���
		Dir[Index] = cPlayer.GetDir(Index);
	}

	VECTOR GoalPos = cMapManager.GetGoal().GetPos();		//�S�[���̍��W
	VECTOR GoalSize = GOAL_SIZE;							//�S�[���̃T�C�Y
	VECTOR GoalHarfSize = VScale(GoalSize, 0.5f);			//�S�[���̃n�[�t�T�C�Y

	//X���݂̂Ōv�Z����
	PlayerPos.x = NextPlayerPos.x;
	if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, GoalPos, GoalSize))
	{
		//���������Ă���
		OverRap = 0.0f;

		/*�ǂ��瑤���瓖���������𔻒肷��*/
		//�E���瓖�������ꍇ
		if (Dir[DIR_RIGHT] == true)
		{
			OverRap = (GoalPos.x - GoalHarfSize.x) - (PlayerPos.x + PlayerHarfSize.x);
		}
		//�����瓖�������ꍇ
		if (Dir[DIR_LEFT] == true)
		{
			OverRap = (GoalPos.x + GoalHarfSize.x) - (PlayerPos.x - PlayerHarfSize.x);
		}

		NextPlayerPos.x += OverRap;
		PlayerPos.x = NextPlayerPos.x;
	}

	
	//Y���݂̂Ōv�Z����
	PlayerPos.y = NextPlayerPos.y;
	if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, GoalPos, GoalSize))
	{
		//���������Ă���
		OverRap = 0.0f;

		/*�ǂ��瑤���瓖���������𔻒肷��*/
		//�ォ�瓖�������ꍇ
		if (Dir[DIR_UP] == true)
		{
			OverRap = (GoalPos.y - GoalHarfSize.y) - (PlayerPos.y + PlayerHarfSize.y);
		}
		//�����瓖�������ꍇ
		if (Dir[DIR_DOWN] == true)
		{
			OverRap = (GoalPos.y + GoalHarfSize.y) - (PlayerPos.y - PlayerHarfSize.y);
		}

		NextPlayerPos.y += OverRap;
		PlayerPos.y = NextPlayerPos.y;
	}

	//Z���݂̂Ōv�Z����
	PlayerPos.z = NextPlayerPos.z;
	if (CCollision::CheckHitBoxToBox(PlayerPos, PlayerSize, GoalPos, GoalSize))
	{
		//���������Ă���
		OverRap = 0.0f;

		/*�ǂ��瑤���瓖���������𔻒肷��*/
		//�����瓖�������ꍇ
		if (Dir[DIR_BACK] == true)
		{
			OverRap = (GoalPos.z - GoalHarfSize.z) - (PlayerPos.z + PlayerHarfSize.z);
		}
		//��O���瓖�������ꍇ
		if (Dir[DIR_NEAR] == true)
		{
			OverRap = (GoalPos.z + GoalHarfSize.z) - (PlayerPos.z - PlayerHarfSize.z);
		}

		NextPlayerPos.z += OverRap;
	}

	cPlayer.SetNextPos(NextPlayerPos);

}


