#pragma once
#include "DxLib.h"

class CUIBase
{
private:
	VECTOR cPos;
	VECTOR cRotate;
	VECTOR cSize;

public:
	//初期化
	void Init();

	//後処理
	void Exit();

};
