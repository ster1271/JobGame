#include "DrawFont.h"

//コンストラクタ
CDrawFont::CDrawFont(){}

//デストラクタ
CDrawFont::~CDrawFont(){}

//初期化
void CDrawFont::Init()
{
	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		FontHndl[FontIndex] = -1;
	}
}

//終了処理
void CDrawFont::Exit()
{
	//ロードしたフォントを解放する
	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		RemoveFontResourceEx(FontFilePath[FontIndex], FR_PRIVATE, NULL);
		FontHndl[FontIndex] = -1;
	}
}

//データの読み込み
bool CDrawFont::LoadAllFontData()
{
	bool IsLoadFont = true;

	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		//新しくフォントデータを読み込む
		int a = AddFontResourceEx(FontFilePath[FontIndex], FR_PRIVATE, NULL);
		if (a == 0)
		{
			return false;
		}

		//読み込んだフォントデータをハンドルに保存
		//引数1：読み込むフォントデータパス
		//引数2：フォントのサイズ
		//引数2：フォントの縁の太さ(0なら縁なし)
		FontHndl[FontIndex] = CreateFontToHandle(FontName[FontIndex], 20, 1, DX_FONTTYPE_NORMAL);

		//1つでもロード失敗があればフラグをオフに
		if (FontHndl[FontIndex] == -1)
		{
			IsLoadFont = false;
		}
	}
	return IsLoadFont;
}

//描画
void CDrawFont::Draw(int PosX, int PosY, FontID Id,
	const TCHAR* String, unsigned int Color)
{
	DrawFormatStringToHandle(PosX, PosY, Color, FontHndl[Id], String);
}