#include "Character.h"

//コンストラクタ・デストラクタ
CCharacter::CCharacter()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

CCharacter::~CCharacter()
{
	//ハンドルの削除
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
	}

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//初期化
void CCharacter::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//読み込み関連
void CCharacter::Load(){}

//毎フレーム行う処理()
void CCharacter::Step(){}

//更新処理
void CCharacter::Updata()
{

}

//後処理
void CCharacter::Exit()
{
	//ハンドルの削除
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
	}
}