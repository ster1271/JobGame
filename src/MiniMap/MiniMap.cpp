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
	IsOpen = false;
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
	if (IsOpen)
	{
		DrawRotaGraph(-PlayerPos.x / 2 + 335 + 935, PlayerPos.z / 2, 0.3f, PlayerRot.y, PlayerHndl, true);
		//DrawCircle(1150, 600, 100, GetColor(255, 255, 255), false);

		for (int WallIndex = 0; WallIndex < WallInfoList.size(); WallIndex++)
		{
			if (WallInfoList[WallIndex].IsMap)
			{
				DrawRotaGraph(-WallInfoList[WallIndex].vPos.x / 2 + 335 + 935, WallInfoList[WallIndex].vPos.z / 2/* + 500*/, 0.25f, 0.0f, WallHndl, true, false, false);
			}
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

	if (CInput::IsKeyPush(KEY_INPUT_TAB) || CGamePad::IsPadPush(DX_INPUT_PAD1,BUTTON_X))
	{
		//�\�����ɂ�����x�����������悤�ɂ���
		if (IsOpen)
		{
			IsOpen = false;
			return;
		}

		//�\�����ɕύX����
		IsOpen = true;
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