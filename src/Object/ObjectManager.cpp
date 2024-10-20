#include "ObjectManager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };



//�R���X�g���N�^
CObjectManager::CObjectManager()
{
}

//�f�X�g���N�^
CObjectManager::~CObjectManager()
{
}

//������
void CObjectManager::Init()
{
	cSky.Init();
}

//�ǂݍ��݊֘A
void CObjectManager::Load()
{
	cSky.Load();
}

//�`��
void CObjectManager::Draw()
{
	cSky.Draw();
}

//���t���[���s������
void CObjectManager::Step()
{
	cSky.Step();

	Update();
}

//�X�V����
void CObjectManager::Update()
{
	cSky.Update();
}

//�㏈��
void CObjectManager::Exit()
{
	cSky.Exit();
}


