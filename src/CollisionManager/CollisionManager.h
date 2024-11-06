#pragma once
#include "Collision/Collision.h"
#include "../Character/CharacterManager.h"
#include "../Enemy/EnemyManager.h"
#include "../Shot/ShotManager.h"
#include "../Map/MapManager.h"



//�R���W�����}�l�[�W���[�N���X
class CCollisionManager
{
public:
	//�v���C���[�ƃ}�b�v�̓����蔻��
	void PlayerToMap(CCharacterManager& cCharaManager, CMapManager& cMapManager);

	//�G�ƃ}�b�v�̓����蔻��
	void EnemyToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager);

	//�^���b�g�̒e�ƓG�̓����蔻��
	void TurretToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//�v���C���[�̒e�ƓG�̓����蔻��
	void PlayerToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

};
