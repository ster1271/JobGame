#pragma once
#include "Collision/Collision.h"
#include "../Player/Player.h"
#include "../Enemy/EnemyManager.h"
#include "../Shot/ShotManager.h"
#include "../Map/MapManager.h"

#include "../Debug/DebugString.h"

//�R���W�����}�l�[�W���[�N���X
class CCollisionManager
{
private:

public:
	//�v���C���[�ƃ}�b�v�̓����蔻��
	void PlayerToMap(CPlayer& cPlayer, CMapManager& cMapManager);

	//�G1�ƃ}�b�v�̓����蔻��
	void Enemy1ToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager);

	//�G2�ƃ}�b�v�̓����蔻��
	void Enemy2ToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager);

	//�^���b�g�̒e�ƓG�̓����蔻��
	void TurretShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//�v���C���[�̒e�ƓG�̓����蔻��
	void PlayerShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//�`��
	void Draw();

};
