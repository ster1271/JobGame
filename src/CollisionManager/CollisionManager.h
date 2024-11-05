#pragma once
#include "Collision/Collision.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"



//コリジョンマネージャークラス
class CCollisionManager
{
public:
	//タレットの弾と敵の当たり判定
	void TurretToEnemy(CEnemyManager& cEnemyManager, CShotManager& cShotManager);

	
};
