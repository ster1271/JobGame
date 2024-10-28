#include "Base.h"

//コンストラクタ
CBase::CBase()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
	memset(&AnimData, 0, sizeof(ANIME_DATA));

	AnimData.m_iHndl = -1;
	AnimData.m_AnimID = -1;
}

//デストラクタ
CBase::~CBase()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
	memset(&AnimData, 0, sizeof(ANIME_DATA));

	AnimData.m_iHndl = -1;
	AnimData.m_AnimID = -1;
}

//初期化
void CBase::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
	memset(&AnimData, 0, sizeof(ANIME_DATA));

	AnimData.m_iHndl = -1;
	AnimData.m_AnimID = -1;

}

//読み込み関連
bool CBase::Load(const char FILEPATH[])
{
	//モデルの読み込み
	iHndl = MV1LoadModel(FILEPATH);

	/*読み込み成功 = true, 読み込み失敗 = false*/	
	if (iHndl != -1)
		return true;
	else
		return false;
}

//描画
void CBase::Draw()
{
	//モデルの描画
	MV1DrawModel(iHndl);
}

//更新処理
void CBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//後処理
void CBase::Exit()
{
	//ハンドルの削除
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
}


//リクエスト
void CBase::Reqest(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	//前のアニメーションとo同じだったら処理しない
	if (AnimData.m_OldAnimID == iAnimID)
		return;

	//アニメ消失
	DetachAnim();

	//アニメ再生&各種データをセット
	AnimData.m_iHndl = MV1AttachAnim(iHndl, iAnimID, iAnimHndl, NameCheck);
	AnimData.m_AnimID = iAnimID;
	AnimData.m_OldAnimID = AnimData.m_AnimID;
	AnimData.m_EndFrame = MV1GetAnimTotalTime(iHndl, iAnimID);
	AnimData.m_Frame = 0.0f;
	AnimData.m_Speed = iAnimSpd;
	AnimData.m_State = ANIMESTATE_NORMAL;

}

//ループアニメリクエスト(アニメが最終フレームになったら最初に戻る)
void CBase::ReqestLoop(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	
	Reqest(iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//アニメ再生状態をループに変える
	AnimData.m_State = ANIMESTATE_LOOP;
}

//エンドループアニメリクエスト(アニメが最終フレームになったら止まる)
void CBase::ReqestEndLoop(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	Reqest(iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//アニメ再生状態をエンドループに変える
	AnimData.m_State = ANIMESTATE_END;
}

//アニメをデタッチ
void CBase::DetachAnim()
{
	if (AnimData.m_iHndl != -1)
	{
		MV1DetachAnim(iHndl, AnimData.m_iHndl);
		AnimData.m_iHndl = -1;
	}
}

//アニメアップデート
void CBase::UpdateAnim()
{
	if (AnimData.m_iHndl == -1)return;	//アニメーションが再生されていない

	//アニメーション速度更新
	AnimData.m_Frame += AnimData.m_Speed;

	if (AnimData.m_Frame >= AnimData.m_EndFrame)
	{
		//最終フレームになったら、状態にあわせて動作を変える
		switch (AnimData.m_State)
		{
		case ANIMESTATE_NORMAL:	//通常終了
			DetachAnim();
			AnimData.m_EndFrame = 0.0f;
			AnimData.m_Frame = 0.0f;
			AnimData.m_Speed = 0.0f;
			return;

		case ANIMESTATE_LOOP:	//ループを最初に戻す
			AnimData.m_Frame = 0.0f;
			break;

		case ANIMESTATE_END:
			AnimData.m_State = AnimData.m_EndFrame;
			break;

		default:
			break;
		}
	}

	//再生時間設定
	MV1SetAttachAnimTime(iHndl, AnimData.m_iHndl, AnimData.m_Frame);
}

