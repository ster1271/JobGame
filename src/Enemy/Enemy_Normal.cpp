#include "Enemy_Normal.h"

const float SPEED = 5.0f;		//移動速度
const int RESEARCH_MAX_TIME = 3000;	//経路探索し直し時間

//コンストラクタ
CEnemy_Normal::CEnemy_Normal()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
	ReSeachTime = 0;
}
//デストラクタ
CEnemy_Normal::~CEnemy_Normal() {}

//初期化
void CEnemy_Normal::Init()
{
	//ひとまず初期化
	cScale = VGet(0.1f, 0.1f, 0.1f);
	cSize = ENEMY_NORMAL_SIZE;
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);


	Life = 0;			//ライフ
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
void CEnemy_Normal::Step(VECTOR vPos, CMapManager& cMapManager, vector<VECTOR> NormalWaveList)
{
	if (!IsActive)
		return;

	float Range = 0.0f;
	vector <VECTOR> tmp;

	switch (State_Id)
	{
	case CEnemyBase::STATE_SEARCH:
		tmp = CRoute_Search::GetInstance()->Route_Search(cPos, vPos, cMapManager);

		ListCnt = 0;

		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:

		//プレイヤーとの距離を計算
		VECTOR v_tmp;
		v_tmp.x = vPos.x - cPos.x;
		v_tmp.y = 0.0f;
		v_tmp.z = vPos.z - cPos.z;

		Range = VSize(v_tmp);

		//ボットの移動ウェーブ時のみ経路探索をしなおす
		if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_BOTMOVE)
		{
			ReSeachTime++;

			//時間経過で経路探索し直し
			if (ReSeachTime >= RESEARCH_MAX_TIME)
			{
				ReSeachTime = 0;
				ListCnt = 0;
				State_Id = STATE_SEARCH;

				return;
			}
		}
		

		if (Range >= 50.0f)
		{
			if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_NORMAL)
			{
				//経路移動処理
				Enemy_Move(NormalWaveList, ListCnt);
			}
			else
			{
				//経路移動処理
				Enemy_Move(tmp, ListCnt);
			}
		}
		else
		{
			//追尾移動
			Out_Move(vPos);
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
bool CEnemy_Normal::RequestEnemy(VECTOR vPos, VECTOR vSpeed)
{
	//すでに出現している
	if (IsActive)
		return false;
	
	cPos = vPos;
	cNextPos = cPos;
	Respown_Pos = vPos;
	cSpeed = vSpeed;
	Life = ENEMY_MAX_LIFE;

	//情報を更新する
	Update();

	State_Id = STATE_SEARCH;
	IsActive = true;

	return true;
}

