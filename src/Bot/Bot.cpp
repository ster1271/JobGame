#include "Bot.h"

const char BOT_FILE_PATH[] = { "" };
const float SPERE_R = 3.0f;

//コンストラクタ
CBot::CBot()
{
}

//デストラクタ
CBot::~CBot()
{
}

//初期化
void CBot::Init()
{
	CObject::Init();
}

//読み込み
bool CBot::Load()
{
	iHndl = MV1LoadModel(BOT_FILE_PATH);

	if (iHndl != -1)
		return true;
	else
		return false;
}

//描画
void CBot::Draw()
{
	//条件式がtrueならモデルをfalseなら球を表示
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		DrawSphere3D(cPos, SPERE_R, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
	}
}

//マイフレーム行う処理
void CBot::Step()
{
	

	//更新処理
	Update();
}


//指定の場所に動く処理
void CBot::Move_Bot()
{

}

