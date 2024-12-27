#include "MiniMap.h"

#define PLAYER_MINI_PATH	"data/MiniMap/Mini_Player.png"

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
	PlayerHndl = LoadGraph(PLAYER_MINI_PATH);
}

//描画
void CMiniMap::Draw()
{
	DrawRotaGraph(1150, 600, 0.3f, PlayerRot.y, PlayerHndl, true);
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

	for (int WallIndex = 0; WallIndex < WallInfoList.size(); WallIndex++)
	{
		
	}

	for (int FloarIndex = 0; FloarIndex < FloarInfoList.size(); FloarIndex++)
	{

	}
}

//情報更新
void CMiniMap::UpData()
{

}

//後処理
void CMiniMap::Exit()
{

}