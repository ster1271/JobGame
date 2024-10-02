#include "ObjectManager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };



//�R���X�g���N�^
CObjectManager::CObjectManager()
{
	Point_Hndl = -1;
}

//�f�X�g���N�^
CObjectManager::~CObjectManager()
{
}

//������
void CObjectManager::Init()
{
	cSky.Init();
	cGround.Init();
}

//�ǂݍ��݊֘A
void CObjectManager::Load()
{
	cSky.Load();
	cGround.Load();
	Point_Hndl = MV1LoadModel(POINT_PATH);
}

//�`��
void CObjectManager::Draw()
{
	cSky.Draw();
	cGround.Draw();

	for (int Point_Index = 0; Point_Index < Point_List.size(); Point_Index++)
	{
		Point_List[Point_Index]->Draw();
	}
}

//���t���[���s������
void CObjectManager::Step()
{
	cSky.Step();
	cGround.Step();

	for (int Point_Index = 0; Point_Index < Point_List.size(); Point_Index++)
	{
		Point_List[Point_Index]->Step();
	}

	Update();
}

//�X�V����
void CObjectManager::Update()
{
	cSky.Update();
	cGround.Update();

	for (int Point_Index = 0; Point_Index < Point_List.size(); Point_Index++)
	{
		Point_List[Point_Index]->Update();
	}
}

//�㏈��
void CObjectManager::Exit()
{
	cSky.Exit();
	cGround.Exit();

	for (int Point_Index = 0; Point_Index < Point_List.size(); Point_Index++)
	{
		Point_List[Point_Index]->Exit();
	}

	if (Point_Hndl != -1)
	{
		MV1DeleteModel(Point_Hndl);
		Point_Hndl = -1;
	}
}

//�ݒu����
void CObjectManager::Set_Point(const VECTOR& vPos)
{
	//�ϐ�����p�N���X
	CObject* cObject = new CRoute_Point;
	cObject->Init();
	cObject->Load(Point_Hndl);
	cObject->Set_Point(vPos);

	//���X�g�ɒǉ�
	Point_List.push_back(cObject);
}
