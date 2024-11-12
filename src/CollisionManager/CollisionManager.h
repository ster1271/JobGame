#pragma once
#include "Collision/Collision.h"
#include "../Player/Player.h"
#include "../Enemy/EnemyManager.h"
#include "../Shot/ShotManager.h"
#include "../Map/MapManager.h"



//コリジョンマネージャークラス
class CCollisionManager
{
public:
	//プレイヤーとマップの当たり判定
	void PlayerToMap(CPlayer& cPlayer, CMap& cMap);

	//敵とマップの当たり判定
	void EnemyToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager);

	//タレットの弾と敵の当たり判定
	void TurretShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//プレイヤーの弾と敵の当たり判定
	void PlayerShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

};
