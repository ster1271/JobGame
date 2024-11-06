#pragma once
#include "Collision/Collision.h"
#include "../Character/CharacterManager.h"
#include "../Enemy/EnemyManager.h"
#include "../Shot/ShotManager.h"
#include "../Map/MapManager.h"



//コリジョンマネージャークラス
class CCollisionManager
{
public:
	//プレイヤーとマップの当たり判定
	void PlayerToMap(CCharacterManager& cCharaManager, CMapManager& cMapManager);

	//敵とマップの当たり判定
	void EnemyToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager);

	//タレットの弾と敵の当たり判定
	void TurretToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//プレイヤーの弾と敵の当たり判定
	void PlayerToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

};
