#include"EnemyBase.h"


const int MAX_LIFE		(3);		//最大体力
const float SPEED		(1.0f);		//移動速度

//--------------------------------------
//コンストラクタ
//--------------------------------------
CEnemyBase::CEnemyBase()
{
	//ひとまず初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	State_Id = STATE_NUM;
	Radius = ENEMY_RADIUS;
	Life = 0;			//ライフ
	HitCount = 0;		//弾の当たった回数
	iHndl = -1;			//ハンドル

	IsActive = false;	//生存フラグ

}

//--------------------------------------
//デストラクタ
//--------------------------------------
CEnemyBase::~CEnemyBase()
{
	//本来は必要ないが念のため
	Exit();
}

//--------------------------------------
//初期化
//--------------------------------------
void CEnemyBase::Init()
{
	//ひとまず初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	State_Id = STATE_MOVE;
	Life = 0;;			//ライフ
	HitCount = 0;;		//弾の当たった回数
	iHndl = -1;			//ハンドル
	ListCnt = 0;
	DeathCnt = 0;

	IsActive = false;	//生存フラグ
}

//--------------------------------------
//終了処理
//--------------------------------------
void CEnemyBase::Exit()
{
	//モデルハンドル解放
	/*if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}*/

	//ひとまず初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	Life = 0;;			//ライフ
	HitCount = 0;;		//弾の当たった回数


	IsActive = false;	//生存フラグ
}

//--------------------------------------
//データロード
//--------------------------------------

void CEnemyBase::Load(int iMdlHndl)
{
	if (iHndl == -1)
	{
		iHndl = MV1DuplicateModel(iMdlHndl);
	}
}


//--------------------------------------
//描画処理
//--------------------------------------
void CEnemyBase::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		//デバック用---------------------------------------------------------------------
		/*
		int R, G, B;
		B = 255;
		R = G = 0;


		switch (HitCount)
		{
		//一回も当たってないとき
		case 0:
			break;
			B = 255;
			R = G = 0;
		//一回当たったとき
		case 1:
			G = 255;
			R = B = 0;

			break;
		//二回当たったとき
		case 2:
			R = 255;
			G = B = 0;

			break;

		default:
			break;
		}
		DrawSphere3D(cPos, Radius, 16, GetColor(R, G, B), GetColor(R, G, B), false);
		*/
		//デバック用---------------------------------------------------------------------
	}

}


//--------------------------------------
//リクエスト
//--------------------------------------
bool CEnemyBase::RequestEnemy(const VECTOR &vPos, const VECTOR &vSpeed)
{
	//すでに出現している
	if (IsActive)
	{
		return false;
	}

	cPos = vPos;
	cNextPos = cPos;
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}

//--------------------------------------
//毎フレーム呼ぶ処理
//--------------------------------------
void CEnemyBase::Step()
{
}

//更新処理
void CEnemyBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cScale);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}


//移動処理
void CEnemyBase::Enemy_Move(vector<VECTOR> List, int& Cnt)
{
	cPos = cNextPos;
	//進行方向のどちら側にいるのかを調べる
	float Dir = 0.0f;

	//ボットから指定の地点へ行くベクトルを計算
	VECTOR Vtmp;
	Vtmp.x = List[Cnt].x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = List[Cnt].z - cPos.z;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//ボットの移動ベクトル
	vSpd.x = sinf(cRotate.y) * -SPEED;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -SPEED;

	//外積計算
	Dir = (Vtmp.x * vSpd.z) - (vSpd.x * Vtmp.z);

	if (fabsf(Dir) < 1.0f)
	{
		float X = Vtmp.x = cPos.x - List[Cnt].x;
		float Z = Vtmp.x = cPos.z - List[Cnt].z;

		//指定の位置へ角度を変える
		float NextRotY = atan2f(X, Z);

		cRotate.y = NextRotY;
	}
	else if (Dir >= 0.0f)//それ以外は角度を変える
	{
		cRotate.y += 0.08f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.08f;
	}


	//座標に速度を加算する
	cNextPos.x += sinf(cRotate.y) * -0.2f;
	cNextPos.z += cosf(cRotate.y) * -0.2f;

	//プレイヤーとの距離を計算
	VECTOR v_tmp;
	v_tmp.x = List[Cnt].x - cPos.x;
	v_tmp.y = 0.0f;
	v_tmp.z = List[Cnt].z - cPos.z;

	float Range = VSize(v_tmp);

	//距離が一定値に達したらIdを変更する
	if (Range < 0.5f)
	{
		Cnt++;

		if (Cnt == List.size())
		{
			State_Id = STATE_SEARCH;
		}
	}
	
}

//自動追尾処理
void CEnemyBase::Out_Move(VECTOR vPos)
{
	//進行方向のどちら側にいるのかを調べる
	float Dir = 0.0f;

	//ボットから指定の地点へ行くベクトルを計算
	VECTOR Vtmp;
	Vtmp.x = vPos.x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = vPos.z - cPos.z;

	float Speed = 1.0f;
	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//ボットの移動ベクトル
	vSpd.x = sinf(cRotate.y) * -Speed;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -Speed;

	//外積計算
	Dir = (Vtmp.x * vSpd.z) - (vSpd.x * Vtmp.z);

	if (fabsf(Dir) < 1.0f)
	{
		float X = cPos.x - vPos.x;
		float Z = cPos.z - vPos.z;

		//指定の位置へ角度を変える
		float NextRotY = atan2f(X, Z);

		cRotate.y = NextRotY;
	}
	else if (Dir >= 0.0f)//それ以外は角度を変える
	{
		cRotate.y += 0.05f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.05f;
	}

	//座標に速度を加算する
	cPos.x += sinf(cRotate.y) * -0.2f;
	cPos.z += cosf(cRotate.y) * -0.2f;
}


//方向フラグ設定
void CEnemyBase::SetDir()
{
	if (cNextPos.x > cPos.x)
	{
		//右に動いている
		IsDir[ENEMY_DIR_RIGHT] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_RIGHT] = false;
	}

	if (cNextPos.x < cPos.x)
	{
		//左に動いている
		IsDir[ENEMY_DIR_LEFT] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_LEFT] = false;
	}

	if (cNextPos.y > cPos.y)
	{
		//上に動いている
		IsDir[ENEMY_DIR_UP] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_UP] = false;
	}

	if (cNextPos.y < cPos.y)
	{
		//下に動いている
		IsDir[ENEMY_DIR_DOWN] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_DOWN] = false;
	}

	if (cNextPos.z > cPos.z)
	{
		//奥に動いている
		IsDir[ENEMY_DIR_BACK] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_BACK] = false;
	}

	if (cNextPos.z < cPos.z)
	{
		//手前に動いている
		IsDir[ENEMY_DIR_NEAR] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_NEAR] = false;
	}
}


