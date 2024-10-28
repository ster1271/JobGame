#pragma once
#include "../Common.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"
#include "../Object/ObjectManager.h"

//ヒューマンベースクラス
class CBase
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
		int m_State;
	};

	VECTOR cPos;			//座標
	VECTOR cSize;			//サイズ
	VECTOR cRotate;			//回転値
	ANIME_DATA AnimData;	//アニメ再生データ

	float Life;			//ライフ
	int iHndl;			//ハンドル

public:
	//コンストラクタ・デストラクタ
	CBase();
	~CBase();

	//初期化
	void Init();

	//読み込み関連
	bool Load(const char FILEPATH[]);

	//描画
	void Draw();

	//毎フレーム行う処理
	virtual void Step(CShotManager& cShotManager, CTurretManager& cTurretManager) = 0;

	//更新処理
	void Update();

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

	//座標取得
	VECTOR GetPos() { return cPos; }

	//サイズ取得
	VECTOR GetSize() { return cSize; }

	//回転地取得
	VECTOR GetRotate() { return cRotate; }

};
