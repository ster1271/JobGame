#include "HumanBase.h"


//コンストラクタ
CHumanBase::CHumanBase()
{
	memset(&AnimDataInfo, 0, sizeof(ANIME_DATA));
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cMoveRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	IsActive = false;

	Life = -1;
	iHndl = -1;
	PushCnt = 0;
	ReturnCnt = 0;
}

//デストラクタ
CHumanBase::~CHumanBase(){}


//初期化
void CHumanBase::Init()
{
	memset(&AnimDataInfo, 0, sizeof(ANIME_DATA));

	//変数の初期化
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	IsActive = false;

	Life = 0;
	iHndl = 0;
	PushCnt = 0;
	ReturnCnt = 0;
}

//データ読み込み
void CHumanBase::Load(const char FILEPATH[])
{
	iHndl = MV1LoadModel(FILEPATH);
}

//描画
void CHumanBase::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		CDraw3D::DrawBox3D(cPos, cSize);
	}

}

//毎フレーム行う処理
void CHumanBase::Step(){}

//情報更新
void CHumanBase::UpData()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cScale);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新

	UpdateAnim();						//アニメーションの情報更新
}

//後処理
void CHumanBase::Exit()
{
	memset(&AnimDataInfo, 0, sizeof(ANIME_DATA));
	//変数の初期化
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	IsActive = false;

	Life = -1;
	iHndl = -1;
	PushCnt = 0;
	ReturnCnt = 0;
}


//リクエスト
void CHumanBase::Reqest(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	//前のアニメーションとo同じだったら処理しない
	if (AnimDataInfo.m_OldAnimID == iAnimID)
		return;

	//アニメ消失
	DetachAnim();

	//アニメ再生&各種データをセット
	AnimDataInfo.m_iHndl = MV1AttachAnim(iHndl, iAnimID, iAnimHndl, NameCheck);
	AnimDataInfo.m_AnimID = iAnimID;
	AnimDataInfo.m_OldAnimID = AnimDataInfo.m_AnimID;
	AnimDataInfo.m_EndFrame = MV1GetAnimTotalTime(iHndl, iAnimID);
	AnimDataInfo.m_Frame = 0.0f;
	AnimDataInfo.m_Speed = iAnimSpd;
	AnimDataInfo.m_State = ANIMESTATE_NORMAL;

}

//ループアニメリクエスト(アニメが最終フレームになったら最初に戻る)
void CHumanBase::ReqestLoop(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{

	Reqest(iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//アニメ再生状態をループに変える
	AnimDataInfo.m_State = ANIMESTATE_LOOP;
}

//エンドループアニメリクエスト(アニメが最終フレームになったら止まる)
void CHumanBase::ReqestEndLoop(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	Reqest(iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//アニメ再生状態をエンドループに変える
	AnimDataInfo.m_State = ANIMESTATE_END;
}

//アニメをデタッチ
void CHumanBase::DetachAnim()
{
	if (AnimDataInfo.m_iHndl != -1)
	{
		MV1DetachAnim(iHndl, AnimDataInfo.m_iHndl);
		AnimDataInfo.m_iHndl = -1;
	}
}

//アニメアップデート
void CHumanBase::UpdateAnim()
{
	if (AnimDataInfo.m_iHndl == -1)return;	//アニメーションが再生されていない

	//アニメーション速度更新
	AnimDataInfo.m_Frame += AnimDataInfo.m_Speed;

	if (AnimDataInfo.m_Frame >= AnimDataInfo.m_EndFrame)
	{
		//最終フレームになったら、状態にあわせて動作を変える
		switch (AnimDataInfo.m_State)
		{
		case ANIMESTATE_NORMAL:	//通常終了
			DetachAnim();
			AnimDataInfo.m_EndFrame = 0.0f;
			AnimDataInfo.m_Frame = 0.0f;
			AnimDataInfo.m_Speed = 0.0f;
			return;

		case ANIMESTATE_LOOP:	//ループを最初に戻す
			AnimDataInfo.m_Frame = 0.0f;
			break;

		case ANIMESTATE_END:
			AnimDataInfo.m_State = AnimDataInfo.m_EndFrame;
			break;

		default:
			break;
		}
	}

	//再生時間設定
	MV1SetAttachAnimTime(iHndl, AnimDataInfo.m_iHndl, AnimDataInfo.m_Frame);
}


//キャラクター回転処理
void CHumanBase::Player_Rotation()
{
	if (CGamePad::Stick(STICK_RX_POS))
	{
		cRotate.y -= 0.03f;
	}
	else if (CGamePad::Stick(STICK_RX_NEG))
	{
		cRotate.y += 0.03f;
	}

	
}

//方向フラグ設定
void CHumanBase::SetDir()
{
	if (cNextPos.x > cPos.x)
	{
		//右に動いている
		IsDir[DIR_RIGHT] = true;
	}
	else
	{
		IsDir[DIR_RIGHT] = false;
	}

	if (cNextPos.x < cPos.x)
	{
		//左に動いている
		IsDir[DIR_LEFT] = true;
	}
	else
	{
		IsDir[DIR_LEFT] = false;
	}

	if (cNextPos.y > cPos.y)
	{
		//上に動いている
		IsDir[DIR_UP] = true;
	}
	else
	{
		IsDir[DIR_UP] = false;
	}

	if (cNextPos.y < cPos.y)
	{
		//下に動いている
		IsDir[DIR_DOWN] = true;
	}
	else
	{
		IsDir[DIR_DOWN] = false;
	}

	if (cNextPos.z > cPos.z)
	{
		//奥に動いている
		IsDir[DIR_BACK] = true;
	}
	else
	{
		IsDir[DIR_BACK] = false;
	}

	if (cNextPos.z < cPos.z)
	{
		//手前に動いている
		IsDir[DIR_NEAR] = true;
	}
	else
	{
		IsDir[DIR_NEAR] = false;
	}
}

