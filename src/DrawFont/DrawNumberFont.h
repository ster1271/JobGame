#pragma once
#include "DxLib.h"

//ナンバーフォントクラス
class CNumber
{
private:
	int Hundl[13];			//格納

	/*
	int NumberPosX;			//座標
	int NumberPosY;			//座標			
	VECTOR NumberPos;		//座標(VECTOR型)
	*/

public:
	CNumber();
	~CNumber();

	//初期化
	void Init();

	//後処理
	void Fin();

	//ナンバーフォント読み込み
	void SetNumber(const char FontDataPath[128], int SizeX, int SizeY);

	//ナンバーフォント描画(等倍描画, 16*32のみ有効)
	void DrawNumber_Normal(int Number, VECTOR Pos);

	//ナンバーフォント描画(2倍描画, 16*32のみ有効)
	void DrawNumber_Double(int Number, VECTOR Pos);

};
