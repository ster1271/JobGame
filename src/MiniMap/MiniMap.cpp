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
	DrawRotaGraph(PlayerPos.x / 2, PlayerPos.z / 2, 0.3f, PlayerRot.y, PlayerHndl, true);
	DrawCircle(1150, 600, 100, GetColor(255, 255, 255), false);

	/*int Size = WallInfoList.size();*/
	for (int WallIndex = 0; WallIndex < WallInfoList.size(); WallIndex++)
	{
		if (WallInfoList[WallIndex].IsMap)
		{
			/*DrawBox(WallInfoList[WallIndex].MiniMapPos.x + 1150, WallInfoList[WallIndex].MiniMapPos.y + 600,
				WallInfoList[WallIndex].MiniMapPos.x + 10 + 1150, WallInfoList[WallIndex].MiniMapPos.y + 10 + 600,
				GetColor(0, 255, 0), false);*/

			DrawBox(WallInfoList[WallIndex].vPos.x / 2/* + 1100*/, WallInfoList[WallIndex].vPos.z / 2/* + 500*/,
				WallInfoList[WallIndex].vPos.x / 2 + /*11*/25, WallInfoList[WallIndex].vPos.z / 2 + /*5*/25,
				GetColor(0, 255, 0), false);
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