#include "MiniMap.h"

#define PLAYER_MINI_PATH	"data/MiniMap/Mini_Player.png"

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
	PlayerHndl = LoadGraph(PLAYER_MINI_PATH);
}

//�`��
void CMiniMap::Draw()
{
	DrawRotaGraph(1150, 600, 0.3f, PlayerRot.y, PlayerHndl, true);
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

	for (int WallIndex = 0; WallIndex < WallInfoList.size(); WallIndex++)
	{
		
	}

	for (int FloarIndex = 0; FloarIndex < FloarInfoList.size(); FloarIndex++)
	{

	}
}

//���X�V
void CMiniMap::UpData()
{

}

//�㏈��
void CMiniMap::Exit()
{

}