#pragma once
#include "../Common.h"

//プレイヤー方向
enum PLAYER_DIR
{
	DIR_RIGHT = 0,	//右
	DIR_LEFT,		//左
	DIR_UP,			//上
	DIR_DOWN,		//下
	DIR_BACK,		//奥
	DIR_NEAR,		//手前

	DIR_NUM,		//総番号
};

class CHumanBase
{
protected:
	//アニメ再生状態
	enum ANIME_STATE
	{
		ANIMESTATE_NORMAL = 0,
		ANIMESTATE_LOOP,
		ANIMESTATE_END,
	};

	//アニメ関連のデータをまとめた構造体
	struct ANIME_DATA
	{
		float m_EndFrame;
		float m_Frame;
		float m_Speed;
		int m_iHndl;
		int m_AnimID;
		int m_OldAnimID;
		int m_State;
	};
	ANIME_DATA AnimDataInfo;	//アニメ再生データ

	VECTOR cPos;				//座標
	VECTOR cNextPos;			//1フレーム後の座標
	VECTOR cRotate;				//キャラクターの向きの回転軸
	VECTOR cMoveRotate;			//キャラクターの方向指定の回転軸
	VECTOR cSpeed;				//キャラクター速度
	VECTOR cScale;				//サイズ
	VECTOR cSize;				//モデルの幅

	bool IsActive;				//生存フラグ
	int iHndl;					//ハンドル
	float Life;					//ライフ
	int PushCnt;				//ボタン押している時間
	int ReturnCnt;				//ボットに戻るための時間
	float StoreRot;			//角度保存

	bool IsDir[DIR_NUM];	//方向フラグ


public:

	VECTOR GetPos() { return cPos; }						//座標取得
	VECTOR GetNextPos() { return cNextPos; }				//座標取得
	void SetNextPos(VECTOR NewPos) { cNextPos = NewPos; }	//座標設定
	VECTOR GetRotate() { return cRotate; }					//回転値取得
	VECTOR GetSpeed() { return cSpeed; }					//速度取得
	VECTOR GetSize() { return cSize; }						//サイズ取得
	bool GetIsActive() { return IsActive; }					//フラグ取得
	bool GetDir(int dir) { return IsDir[dir]; }				//方向フラグ取得


	//コンストラクタ・デストラクタ
	CHumanBase();
	~CHumanBase();

	//初期化
	void Init();

	//データ読み込み
	void Load(const char FILEPATH[]);

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//情報更新
	void UpData();

	//後処理
	void Exit();

	//アニメアップデート
	void UpdateAnim();

	//リクエスト
	void Reqest(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//ループアニメリクエスト(アニメが最終フレームになったら最初に戻る)
	void ReqestLoop(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//エンドループアニメリクエスト(アニメが最終フレームになったら止まる)
	void ReqestEndLoop(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//アニメをデタッチ
	void DetachAnim();

	//キャラクター回転処理
	void Player_Rotation();

	//方向フラグ設定
	void SetDir();											


};
