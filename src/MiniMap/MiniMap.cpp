#include "MiniMap.h"

#define PLAYER_MINI_PATH	"data/MiniMap/Mini_Player.png"
#define WALL_MINI_PATH		"data/MiniMap/Wall.png"

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
	WallHndl = LoadGraph(WALL_MINI_PATH);
}

//�`��
void CMiniMap::Draw()
{
	DrawRotaGraph(PlayerPos.x / 2, PlayerPos.z / 2, 0.3f, PlayerRot.y, PlayerHndl, true);
	DrawCircle(1150, 600, 100, GetColor(255, 255, 255), false);

	for (int WallIndex = 0; WallIndex < WallInfoList.size(); WallIndex++)
	{
		if (WallInfoList[WallIndex].IsMap)
		{
			DrawRotaGraph(WallInfoList[WallIndex].vPos.x / 2/* + 1100*/, WallInfoList[WallIndex].vPos.z / 2/* + 500*/, 0.25f, 0.0f, WallHndl, false, false);
		}
	
	}
}

//���t���[���s������
void CMiniMap::Step(VECTOR vPos, VECTOR vSpd, VECTOR vRot, CMapManager& cMapManager)
{
	//�v���C���[�����擾
	VECTOR OldPos = PlayerPos;
	PlayerPos = vPos;
	PlayerRot = vRot;
	PlayerSpd = vSpd;

	MoveVec = VSub(PlayerPos, OldPos);

	//�}�b�v�̕ǂƏ������擾
	WallInfoList = cMapManager.GetMap().GetWallList();	
	FloarInfoList = cMapManager.GetMap().GetFloarList();

	VECTOR A = VECTOR_ZERO;
	for (int WallIndex = 0; WallIndex < WallInfoList.size(); WallIndex++)
	{
		A = VGet(WallInfoList[WallIndex].vPos.x / 50, 0.0f, WallInfoList[WallIndex].vPos.z / 50);
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