#include "DrawNumberFont.h"

//コンストラクタ
CNumber::CNumber()
{
	for (int i = 0; i < 13; i++)
	{
		Hundl[i] = 0;
	}

	/*
	NumberPos = { 0.0f, 0.0f, 0.0f };
	NumberPosX = 0;
	NumberPosY = 0;
	*/
}
//デストラクタ
CNumber::~CNumber()
{
	for (int i = 0; i < 13; i++)
	{
		DeleteGraph(Hundl[i]);
	}

	/*
	NumberPos = { 0.0f, 0.0f, 0.0f };
	NumberPosX = 0;
	NumberPosY = 0;
	*/
}


//初期化
void CNumber::Init()
{
	for (int i = 0; i < 13; i++)
	{
		Hundl[i] = 0;
	}

	/*
	NumberPos = { 0.0f, 0.0f, 0.0f };
	NumberPosX = 0;
	NumberPosY = 0;
	*/
}

//後処理
void CNumber::Fin()
{
	for (int i = 0; i < 13; i++)
	{
		DeleteGraph(Hundl[i]);
	}

	/*
	NumberPos = { 0.0f, 0.0f, 0.0f };
	NumberPosX = 0;
	NumberPosY = 0;
	*/
}

//ナンバーフォント読み込み
//第一引数	フォントデータのパス
//第二引数	縦幅
//第三引数	横幅
void CNumber::SetNumber(const char FontDataPath[128], int SizeX, int SizeY)
{
	//保険で初期化しておく
	for (int i = 0; i < 13; i++)
	{
		if (Hundl[i] != 0)
		{
			Hundl[i] = 0;
		}
	}

	//読み込み
	LoadDivGraph(FontDataPath, 13, 13, 1, SizeX, SizeY, Hundl);
}


//ナンバーフォント描画
//*等倍のみ有効(16*32)
//第一引数	入れたい数字
//第二引数	表示したい座標
void CNumber::DrawNumber_Normal(int Number, VECTOR Pos)
{
	//ポイント描画
	int DrawScore = Number;

	int count = 0;

	//DrawScoreが0になったとき
	if (DrawScore == 0) {
		DrawGraph((int)Pos.x - count * 20, (int)Pos.y, Hundl[0], true);
	}
	//DrawScoreが0以外の時
	while (DrawScore > 0)
	{
		int num = DrawScore % 10;
		DrawScore = DrawScore / 10;
		DrawGraph((int)Pos.x - count * 20, (int)Pos.y, Hundl[num], true);
		count++;
	}
}

//ナンバーフォント描画(VECTOR型)
// //*2倍のみ有効(16*32)
//第一引数	入れたい数字
//第二引数	表示したい座標(VECTOR型)
void CNumber::DrawNumber_Double(int Number, VECTOR Pos)
{
	//ポイント描画
	int DrawScore = Number;

	int count = 0;

	//DrawScoreが0になったとき
	if (DrawScore == 0) {
		DrawRotaGraph((int)Pos.x - count * 35, (int)Pos.y, 2.0f, 0.0f, Hundl[0], true);
	}
	//DrawScoreが0以外の時
	while (DrawScore > 0)
	{
		int num = DrawScore % 10;
		DrawScore = DrawScore / 10;
		DrawRotaGraph((int)Pos.x - count * 35, (int)Pos.y, 2.0f, 0.0f, Hundl[num], true);
		count++;
	}
}