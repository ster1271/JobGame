#include "MiniMap.h"

#define PLAYER_MINI_PATH	"data/MiniMap/Mini_Player.png"
#define WALL_MINI_PATH		"data/MiniMap/Wall.png"

//コンストラクタ
CMiniMap::CMiniMap() {};

//デストラクタ
CMiniMap::~CMiniMap() {};

//初期化
void CMiniMap::Init()
{
	PlayerPos = VECTOR_ZERO;
	IsOpen = false;
}

//データ読み込み
void CMiniMap::Load()
{
	PlayerHndl = LoadGraph(PLAYER_MINI_PATH);
	WallHndl = LoadGraph(WALL_MINI_PATH);
}

//描画
void CMiniMap::Draw()
{
	if (IsOpen)
	{
		DrawRotaGraph(-PlayerPos.x / 2 + 335 + 935, PlayerPos.z / 2, 0.3f, PlayerRot.y, PlayerHndl, true);
		//DrawCircle(1150, 600, 100, GetColor(255, 255, 255), false);

		for (int WallIndex = 0; WallIndex < WallInfoList.size(); WallIndex++)
		{
			if (WallInfoList[WallIndex].IsMap)
			{
				DrawRotaGraph(-WallInfoList[WallIndex].vPos.x / 2 + 335 + 935, WallInfoList[WallIndex].vPos.z / 2/* + 500*/, 0.25f, 0.0f, WallHndl, true, false, false);
			}
		}

	}
}

//毎フレーム行う処理
void CMiniMap::Step(VECTOR vPos, VECTOR vSpd, VECTOR vRot, CMapManager& cMapManager)
{
	//プレイヤー情報を取得
	VECTOR OldPos = PlayerPos;
	PlayerPos = vPos;
	PlayerRot = vRot;
	PlayerSpd = vSpd;

	MoveVec = VSub(PlayerPos, OldPos);

	//マップの壁と床情報を取得
	WallInfoList = cMapManager.GetMap().GetWallList();	
	FloarInfoList = cMapManager.GetMap().GetFloarList();

	if (CInput::IsKeyPush(KEY_INPUT_TAB) || CGamePad::IsPadPush(DX_INPUT_PAD1,BUTTON_X))
	{
		//表示中にもう一度押したら閉じるようにする
		if (IsOpen)
		{
			IsOpen = false;
			return;
		}

		//表示中に変更する
		IsOpen = true;
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