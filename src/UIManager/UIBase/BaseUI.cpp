#include "BaseUI.h"

//初期化
void CUIBase::Init()
{
	memset(&cPos, -1, sizeof(VECTOR));
	memset(&cRotate, -1, sizeof(VECTOR));
	memset(&cSize, -1, sizeof(VECTOR));
}

//後処理
void CUIBase::Exit()
{
	memset(&cPos, -1, sizeof(VECTOR));
	memset(&cRotate, -1, sizeof(VECTOR));
	memset(&cSize, -1, sizeof(VECTOR));
}