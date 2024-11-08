#include "CollisionManager.h"

//ƒvƒŒƒCƒ„[‚Æƒ}ƒbƒv‚Ì“–‚½‚è”»’è
void CCollisionManager::PlayerToMap(CCharacterManager& cCharaManager, CMapManager& cMapManager)
{
	/*CAttacker cPlayer = cCharaManager.*/
}


//“G‚Æƒ}ƒbƒv‚Ì“–‚½‚è”»’è
void CCollisionManager::EnemyToMap(CEnemyManager& cEnemyManager, CMapManager& cMapManager)
{

}


//ƒ^ƒŒƒbƒg‚Ì’e‚Æ“G‚Ì“–‚½‚è”»’è
void CCollisionManager::TurretToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	//’e‚Ì”•ª‰ñ‚·
	for (int shotIndex = 0; shotIndex < TURRET_SHOT_NUM; shotIndex++)
	{
		//’eî•ñ‚ğŠi”[‚·‚é
		CTurretShot& cTShot = cShotManager.GetTurretShotInfo(shotIndex);
		float ShotRadius = cTShot.GetRadius();

		//ƒtƒ‰ƒO‚ªfalse‚È‚çfor•¶‚ğŸ‚É•ÏX‚·‚é
		if (!cTShot.GetIsActive())
			continue;


		//“G‚Ì”•ª‰ñ‚·
		for (int enemyIndex = 0; enemyIndex < ENEMY_NUM; enemyIndex++)
		{
			//“Gî•ñ‚ğŠi”[‚·‚é
			CEnemy_Normal& cENormal = cEnemyManager.GetEnemy(enemyIndex);
			float EnemyRadius = cENormal.GetRadius();

			//ƒtƒ‰ƒO‚ªfalse‚È‚çfor•¶‚ğŸ‚É•ÏX‚·‚é
			if (!cENormal.GetActive())
				continue;

			//“–‚½‚è”»’è
			if (CCollision::CheckHitSphereToSphere(cTShot.GetPos(), ShotRadius, cENormal.GetPosition(), EnemyRadius))
			{
				cTShot.HitCalc();	//’e‚Ìƒtƒ‰ƒO‚ğ‚¨‚é
				cENormal.HitCalc();	//“G‚ÌHP‚ğŒ¸‚ç‚·
			}
		}
	}
}


//ƒvƒŒƒCƒ„[‚Ì’e‚Æ“G‚Ì“–‚½‚è”»’è
void CCollisionManager::PlayerToEnemy(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	//’e‚Ì”•ª‰ñ‚·
	for (int shotIndex = 0; shotIndex < PL_SHOT_NUM; shotIndex++)
	{
		//’eî•ñ‚ğŠi”[‚·‚é
		CPlayerShot& cPShot = cShotManager.GetPlayerShotInfo(shotIndex);
		float ShotRadius = cPShot.GetRadius();

		//ƒtƒ‰ƒO‚ªfalse‚È‚çfor•¶‚ğŸ‚É•ÏX‚·‚é
		if (!cPShot.GetIsActive())
			continue;


		//“G‚Ì”•ª‰ñ‚·
		for (int enemyIndex = 0; enemyIndex < ENEMY_NUM; enemyIndex++)
		{
			//“Gî•ñ‚ğŠi”[‚·‚é
			CEnemy_Normal& cENormal = cEnemyManager.GetEnemy(enemyIndex);
			float EnemyRadius = cENormal.GetRadius();

			//ƒtƒ‰ƒO‚ªfalse‚È‚çfor•¶‚ğŸ‚É•ÏX‚·‚é
			if (!cENormal.GetActive())
				continue;

			//“–‚½‚è”»’è
			if (CCollision::CheckHitSphereToSphere(cPShot.GetPos(), ShotRadius, cENormal.GetPosition(), EnemyRadius))
			{
				cPShot.HitCalc();	//’e‚Ìƒtƒ‰ƒO‚ğ‚¨‚é
				cENormal.HitCalc();	//“G‚ÌHP‚ğŒ¸‚ç‚·
			}
		}
	}
}




