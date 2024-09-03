#include "ObjectManager.h"


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
	cGround.Init();
}

//�ǂݍ��݊֘A
void CObjectManager::Load()
{
	cSky.Load();
	cGround.Load();
}

//�`��
void CObjectManager::Draw()
{
	cSky.Draw();
	cGround.Draw();
}

//���t���[���s������
void CObjectManager::Step()
{
	cSky.Step();
	cGround.Step();

	Update();
}

//�X�V����
void CObjectManager::Update()
{
	cSky.Update();
	cGround.Update();
}

//�㏈��
void CObjectManager::Exit()
{
	cSky.Exit();
	cSky.Exit();
}