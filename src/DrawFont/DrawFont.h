#pragma once
#include "DxLib.h"

enum FontID
{
	FONT_ID_CP,			//チェックポイントフォント

	FONTID_NUM			//総番号
};

static const char FontFilePath[FONTID_NUM][128]
{
	"data/FontData/CPFont.otf",
};

static const char FontName[FONTID_NUM][128]
{
	"チェックポイントフォント",
};

static int FontHndl[FONTID_NUM];

class CDrawFont
{
private:

public:
	//コンストラクタ・デストラクタ
	CDrawFont();
	~CDrawFont();

	//初期化
	static void Init();

	//終了処理
	static void Exit();

	//データの読み込み
	static bool LoadAllFontData();

	//描画
	static void Draw(int PosX, int PosY, FontID Id,
		const TCHAR *String, unsigned int Color = GetColor(255, 255, 255));

};
