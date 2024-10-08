#include "Check_Point.h"

//コンストラクタ
CCheck_Point::CCheck_Point()
{
	memset(&Point_info_List, 0, sizeof(VECTOR));
	tmp_Hndl = -1;
	tmp = -1;
}

//デストラクタ
CCheck_Point::~CCheck_Point()
{
	Exit();
}

//初期化
void CCheck_Point::Init(FILE* fp)
{
	CCheck_Base::Init();

	tmp = 0;
	tmp_Hndl = -1;

	VECTOR vPos = VGet(0.0f, 0.0f, 0.0f);
	
	//読み込み
	//ファイルを開く
	fopen_s(&fp, "Data/ObjectFile/Object_file.txt", "r");

	if (fp != nullptr)
	{
		while (fscanf_s(fp, "%f, %f, %f", &vPos.x, &vPos.y, &vPos.z) != EOF)
		{
			Set_Point(vPos);
		}
	}

	fclose(fp);
	
}

//モデル読み込み
void CCheck_Point::Load(int Hndl)
{
	//モデルのコピー
	iHndl = MV1DuplicateModel(Hndl);
}


//描画
void CCheck_Point::Draw()
{
	if (!IsActive)
		return;

	MV1DrawModel(iHndl);
}

//毎フレーム行う処理
void CCheck_Point::Step()
{
	if (!IsActive)
		return;

}

//後処理
void CCheck_Point::Exit()
{
	CCheck_Base::Exit();

	if (tmp_Hndl != -1)
	{
		MV1DeleteModel(tmp_Hndl);
		tmp_Hndl = -1;
	}
}

//設置処理
void CCheck_Point::Set_Point(const VECTOR vPos)
{
	cPos = vPos;
	cSize= VGet(0.1f, 0.1f, 0.1f);
	IsActive = true;

	Point_info_List.push_back(cPos);
}





