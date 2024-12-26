#include "MiniMap.h"

//�R���X�g���N�^
CMiniMap::CMiniMap() {};

//�f�X�g���N�^
CMiniMap::~CMiniMap() {};

//������
void CMiniMap::Init()
{
	PlayerPos = VECTOR_ZERO;
}

//�f�[�^�ǂݍ���
void CMiniMap::Load()
{

}

//�`��
void CMiniMap::Draw()
{
	

	DrawCircle(1150, 600, 100, GetColor(255, 255, 255), false);
}

//���t���[���s������
void CMiniMap::Step(VECTOR vPos, VECTOR vRot, CMapManager& cMapManager)
{
	//�v���C���[�����擾
	PlayerPos = vPos;
	PlayerRot = vRot;

	//�}�b�v�̕ǂƏ������擾
	WallInfoList = cMapManager.GetMap().GetWallList();	
	FloarInfoList = cMapManager.GetMap().GetFloarList();
}

//���X�V
void CMiniMap::UpData()
{

}

//�㏈��
void CMiniMap::Exit()
{

}