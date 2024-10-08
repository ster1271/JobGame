#include "GamePointer.h"

#define MOVE_SPEED	(1.0f)

//コンストラクタ・デストラクタ
CGame_Pointer::CGame_Pointer()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cBoxSize, 0, sizeof(VECTOR));
	iHndl = -1;
	
}

CGame_Pointer::~CGame_Pointer() {};

//初期化
void CGame_Pointer::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	cBoxSize = VGet(20.0f, 20.0f, 20.0f);
	iHndl = -1;
}

//読み込み
void CGame_Pointer::Load()
{

}

//毎フレーム行う処理
void CGame_Pointer::Step()
{
	
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		cPos.z += MOVE_SPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		cPos.z -= MOVE_SPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_A)) {
		cPos.x -= MOVE_SPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_D)) {
		cPos.x += MOVE_SPEED;
	}

}

//描画
void CGame_Pointer::Draw()
{
	CDraw3D::DrawBox3D(cPos, cBoxSize);
}

//後処理
void CGame_Pointer::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	cBoxSize = VGet(5.0f, 5.0f, 5.0f);
	iHndl = -1;
}