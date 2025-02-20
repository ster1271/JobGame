#include "ButtonUI.h"

const char GAUGE_FLAME_PATH[] = { "data/UI/button/gauge_frame.png" };
const char GAUGE_PATH[] = { "data/UI/button/gauge.png" };

//コンストラクタ・デストラクタ
CButtonUI::CButtonUI()
{
	for (int i = 0; i < BUTTONID_NUM; i++)
	{
		ButtonHndl[i] = -1;
	}
	GaugeFlameHndl = -1;
	GaugeHndl = -1;

	Cnt = 0;
}

CButtonUI::~CButtonUI(){}

//初期化
void CButtonUI::Init()
{
	GaugeFlameHndl = -1;
	GaugeHndl = -1;
	Cnt = 0.0f;

	for (int i = 0; i < BUTTONID_NUM; i++)
	{
		ButtonHndl[i] = -1;
	}
}

//読み込み
bool CButtonUI::Load()
{
	GaugeFlameHndl = LoadGraph(GAUGE_FLAME_PATH);
	GaugeHndl = LoadGraph(GAUGE_PATH);	

	//ボタン全ての画像ハンドルの読み込み
	bool IsLoaded = true;
	for (int i = 0; i < BUTTONID_NUM; i++)
	{
		ButtonHndl[i] = LoadGraph(ButtonFileName[i]);
		//1つでもロード失敗があればフラグをオフに
		if (ButtonHndl[i] == -1)
		{
			IsLoaded = false;
		}
	}

	return IsLoaded;
}

//毎フレーム行う処理
void CButtonUI::Step(const int Count)
{
	Cnt = Count * 2;
}

//描画
void CButtonUI::Draw()
{
	DrawCircleGauge(300, 300, Cnt, GaugeHndl, 0.0f);
	DrawBillboard3D(VGet(1250.0f, 20.0f, 1150.0f), 0.5, 0.5f, 15, 0.0f, GaugeFlameHndl, true, false, false);
	DrawBillboard3D(VGet(1250.0f, 20.0f, 1150.0f), 0.5, 0.5f, 15, 0.0f, ButtonHndl[BUTTONID_A], true, false, false);
}

//後処理
void CButtonUI::Exit()
{
	GaugeFlameHndl = -1;
	GaugeHndl = -1;
}