#pragma once
#include "Collision/Collision.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"



//�R���W�����}�l�[�W���[�N���X
class CCollisionManager
{
public:
	//�^���b�g�̒e�ƓG�̓����蔻��
	void TurretToEnemy(CEnemyManager& cEnemyManager, CShotManager& cShotManager);

	
};
