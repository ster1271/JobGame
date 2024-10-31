#include "MapManager.h"

//�R���X�g���N�^
CMapManager::CMapManager()
{

}

//�f�X�g���N�^
CMapManager::~CMapManager()
{

}

//������
void CMapManager::Init()
{
	cMap.Init();
	cGoal.Init();
}

//�ǂݍ���
void CMapManager::Load()
{
	cMap.Load();
	cGoal.Load();
}

//�`��
void CMapManager::Draw()
{
	cMap.Draw();
	cGoal.Draw();
}

//���t���[���s������
void CMapManager::Step()
{
	cMap.Step();
	cGoal.Step();

	Updata();
}

//���X�V
void CMapManager::Updata()
{
	cMap.Update();
	cGoal.Update();
}

//�㏈��
void CMapManager::Exit()
{
	cMap.Exit();
	cGoal.Exit();
}