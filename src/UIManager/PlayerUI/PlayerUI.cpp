#include "PlayerUI.h"

const char PLAYER_HP_PATH[] = { "data/UI/player/PlayerHP.png" };

//�R���X�g���N�^
CPlayerUI::CPlayerUI(){}

//�f�X�g���N�^
CPlayerUI::~CPlayerUI(){}

//������
void CPlayerUI::Init()
{
	HPHndl = -1;
}

//�ǂݍ���
void CPlayerUI::Load()
{
	HPHndl = LoadGraph(PLAYER_HP_PATH);
}

//���t���[���s������
void CPlayerUI::Step()
{
	
}

//�`��
void CPlayerUI::Draw()
{
	int DrawX = 590;
	int DrawY = 290;

	//�v���C���[�̃��C�t���擾
	float LIFE = CPlayer::GetInstance()->GetPlayerLife();

	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 100);
	DrawRectGraph(DrawX, DrawY, 0, 0, LIFE, 30, HPHndl, true, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//�㏈��
void CPlayerUI::Exit()
{
	HPHndl = -1;
}