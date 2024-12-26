#include "MiniMap.h"

//コンストラクタ
CMiniMap::CMiniMap() {};

//デストラクタ
CMiniMap::~CMiniMap() {};

//初期化
void CMiniMap::Init()
{
	PlayerPos = VECTOR_ZERO;
}

//データ読み込み
void CMiniMap::Load()
{

}

//描画
void CMiniMap::Draw()
{
	

	DrawCircle(1150, 600, 100, GetColor(255, 255, 255), false);
}

//毎フレーム行う処理
void CMiniMap::Step(VECTOR vPos, VECTOR vRot, CMapManager& cMapManager)
{
	//プレイヤー情報を取得
	PlayerPos = vPos;
	PlayerRot = vRot;

	//マップの壁と床情報を取得
	WallInfoList = cMapManager.GetMap().GetWallList();	
	FloarInfoList = cMapManager.GetMap().GetFloarList();
}

//情報更新
void CMiniMap::UpData()
{

}

//後処理
void CMiniMap::Exit()
{

}