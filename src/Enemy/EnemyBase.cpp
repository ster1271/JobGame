#include"EnemyBase.h"


const float NEMY_RADIUS	(5.0f);		//モデルの半径
const int MAX_LIFE		(3);		//最大体力
const float SPEED		(1.0f);		//移動速度

//--------------------------------------
//コンストラクタ
//--------------------------------------
CEnemyBase::CEnemyBase()
{
	//ひとまず初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	State_Id = STATE_NUM;
	Radius = NEMY_RADIUS;
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
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	State_Id = STATE_MOVE;
	Life = 0;;			//ライフ
	HitCount = 0;;		//弾の当たった回数
	iHndl = -1;			//ハンドル
	ListCnt = 0;

	IsActive = false;	//生存フラグ
}

//--------------------------------------
//終了処理
//--------------------------------------
void CEnemyBase::Exit()
{
	//モデルハンドル解放
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	//ひとまず初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
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
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}


//移動処理
void CEnemyBase::Enemy_Move(vector<VECTOR> List, int& Cnt)
{

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
		//NUM = 1;
		cRotate.y += 0.05f;
	}
	else if (Dir < 0.0f)
	{
		//NUM = 2;
		cRotate.y -= 0.05f;
	}

	//座標に速度を加算する
	cPos.x += sinf(cRotate.y) * -0.2f;
	cPos.z += cosf(cRotate.y) * -0.2f;

	//プレイヤーとの距離を計算
	float Range = (List[Cnt].x - cPos.x) * (List[Cnt].x - cPos.x) + (List[Cnt].z - cPos.z) * (List[Cnt].z - cPos.z);
	Range = sqrt(Range);

	//距離が一定値に達したらIdを変更する
	if (Range < 0.5f)
	{
		Cnt++;

		if (Cnt == List.size())
		{
			State_Id = STATE_ATTACK;
		}
	}
	
}

