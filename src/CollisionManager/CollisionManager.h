#pragma once
#include "Collision/Collision.h"

//コリジョンマネージャークラス
class CCollisionManager
{
public:

	void TurretToEnemy();

	//経路探索時のマップとの当たり判定
	bool BoxToMap();
};
