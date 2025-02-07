#include "Enemy_Normal.h"

const float SPEED = 5.0f;		//移動速度
const int RESEARCH_TIME = 1000;	//経路探索し直し時間

//コンストラクタ
CEnemy_Normal::CEnemy_Normal()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}
//デストラクタ
CEnemy_Normal::~CEnemy_Normal() {}

//初期化
void CEnemy_Normal::Init()
{
	//ひとまず初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	Life = 0;;			//ライフ
	iHndl = -1;			//ハンドル

	IsActive = false;	//生存フラグ

	List.clear();
	ReSeachTime = 0;
	ListCnt = 0;
	State_Id = STATE_SEARCH;
}

//データロード
void CEnemy_Normal::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//描画
void CEnemy_Normal::Draw()
{
	if (!IsActive)
		return;

	MV1DrawModel(iHndl);

	if (IS_DEBUG)
	{
		CRoute_Search::GetInstance()->Draw(GetColor(0, 0, 255));
	}
}

//毎フレーム行う処理
void CEnemy_Normal::Step(CBot& cBot, CMapManager& cMapManager)
{
	if (!IsActive)
		return;

	float Range = 0.0f;

	switch (State_Id)
	{
	case CEnemyBase::STATE_SEARCH:
		List = CRoute_Search::GetInstance()->Route_Search(cPos, cBot.GetPos(), cMapManager);
		
		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:

		//プレイヤーとの距離を計算
		VECTOR v_tmp;
		v_tmp.x = cBot.GetPos().x - cPos.x;
		v_tmp.y = 0.0f;
		v_tmp.z = cBot.GetPos().z - cPos.z;

		Range = VSize(v_tmp);

		if (Range >= 50.0f)
		{
			ReSeachTime++;

			//時間経過で経路探索し直し
			/*if (ReSeachTime >= RESEARCH_TIME)
			{
				List.clear();
				ReSeachTime = 0;
				ListCnt = 0;
				State_Id = STATE_SEARCH;

				break;
			}*/

			//経路移動処理
			Enemy_Move(List, ListCnt);
		}
		else
		{
			//追尾移動
			Out_Move(cBot.GetPos());
		}


		break;
	case CEnemyBase::STATE_ATTACK:
		


		break;
	
	default:
		break;
	}

	//方向設定
	SetDir();

}

//後処理
void CEnemy_Normal::Exit()
{
	CEnemyBase::Exit();
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}

//リクエスト
bool CEnemy_Normal::RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//すでに出現している
	if (IsActive)
	{
		return false;
	}
	
	cPos = vPos;
	cNextPos = cPos;
	Respown_Pos = vPos;
	cScale = VGet(0.1f, 0.1f, 0.1f);
	cSize = ENEMY_NORMAL_SIZE;
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = ENEMY_MAX_LIFE;

	//情報を更新する
	Update();

	List.clear();
	ListCnt = 0;

	State_Id = STATE_SEARCH;
	IsActive = true;

	return true;
}

