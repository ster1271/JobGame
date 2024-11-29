#pragma once
#include "Collision/Collision.h"
#include "../Player/Player.h"
#include "../Enemy/EnemyManager.h"
#include "../Shot/ShotManager.h"
#include "../Map/MapManager.h"

#include "../Debug/DebugString.h"

//コリジョンマネージャークラス
class CCollisionManager
{
private:

public:
	//プレイヤーとマップの当たり判定
	void PlayerToMap(CPlayer& cPlayer, CMapManager& cMapManager);

	//敵1とマップの当たり判定
	void Enemy1ToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager);

	//敵2とマップの当たり判定
	void Enemy2ToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager);

	//敵1同士の当たり判定
	void CheckEnemy1(CEnemyManager& cEnemyManager);

	//敵2同士の当たり判定
	void CheckEnemy2(CEnemyManager& cEnemyManager);

	//プレイヤーの弾と敵の当たり判定
	void PlayerShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//タレットの弾と敵の当たり判定
	void TurretShotToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//プレイヤーの弾とマップの当たり判定
	void PlayerShotToMap(CShotManager& cShotManager, CMapManager& cMapManager);

	//タレットの弾とマップの当たり判定
	void TurretShotToMap(CShotManager& cShotManager, CMapManager& cMapManager);

	//描画
	void Draw();

};
