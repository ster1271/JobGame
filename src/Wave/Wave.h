#pragma once
#include <DxLib.h>

//ウェーブの状態
enum WAVE_STATE
{
	STATE_WAVE_NONE,		//何もしてない
	STATE_WAVE_PREPAR,		//ウェーブ準備中
	STATE_WAVE_NORMAL,		//ノーマルウェーブ中
	STATE_WAVE_BOTMOVE,		//ボット移動ウェーブ中
	STATE_WAVE_END,			//ウェーブ終了
};

//ウェーブクラス
class CWave
{
private:
	//CWaveクラスのポインタ変数
	static CWave* cInstance;

	WAVE_STATE Wave_ID;		//ウェーブの状態
	bool IsWave;			//ウェーブフラグ
	int Cnt;				//時間カウント
	
	int hnd;

public:
	//コンストラクタ・デストラクタ
	CWave();
	~CWave();

	//CGameDataを取得
	static CWave* GetInstance();

	//CGameDataを削除
	static void DeleteInstance();


	bool GetIsWave() { return IsWave; }				//フラグの取得
	WAVE_STATE GetWaveState() { return Wave_ID; }	//ウェーブの状態取得

	void WaveStateChange(WAVE_STATE id);	//ウェーブ状態変更

	void Step();					

	void Draw();

};