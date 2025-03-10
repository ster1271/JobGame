#pragma once
#include <DxLib.h>
#include "../SoundManager/SoundManager.h"

//ウェーブの状態
enum WAVE_STATE
{
	STATE_WAVE_NONE = 0,	//何もしてない
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
	bool IsNormal;			//ノーマルウェーブフラグ
	bool IsBotMove;			//ボット移動ウェーブフラグ
	int WaveTime;			//ウェーブ発生時間

	int StartWaveTime;		//ウェーブ開始までの時間
	
public:
	//コンストラクタ・デストラクタ
	CWave();
	~CWave();

	//CGameDataを取得
	static CWave* GetInstance();

	//CGameDataを削除
	static void DeleteInstance();


	bool GetIsWave() { return IsWave; }					//フラグの取得
	bool GetIsNormal() { return IsNormal; }				//フラグの取得
	bool GetIsBotMove() { return IsBotMove; }			//フラグの取得
	int GetWaveTime() { return WaveTime; }				//時間の取得
	void SetIsWave(bool Flag) { IsWave = Flag;}			//フラグの設定
	void SetIsNormal(bool Flag) { IsNormal = Flag; }	//フラグの設定
	void SetIsBotMove(bool Flag) { IsBotMove = Flag; }	//フラグの設定
	void SetWaveTime(int time) { WaveTime = time; }		//時間設定

	WAVE_STATE GetWaveState() { return Wave_ID; }	//ウェーブの状態取得
	int GetTime() { return StartWaveTime / 60; }	//時間取得

	void WaveStateChange(WAVE_STATE id);	//ウェーブ状態変更

	void Step();					

	void Draw();

};