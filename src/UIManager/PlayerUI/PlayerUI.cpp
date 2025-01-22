#include "PlayerUI.h"

const char PLAYER_LIFE_PATH[] = { "data/UI/player/PlayerLife.png" };
const char PLAYER_LIFEBACK_PATH[] = { "data/UI/player/LifeBack.png" };

const int DRAW_X = 590;
const int DRAW_Y = 290;

//�R���X�g���N�^
CPlayerUI::CPlayerUI(){}

//�f�X�g���N�^
CPlayerUI::~CPlayerUI(){}

//������
void CPlayerUI::Init()
{
	LifeHndl = -1;
	BgHndl = -1;
	CurrentLife = 0;
	PreLife = 0;
	Alpha = 0;
	Count = 0;
}

//�ǂݍ���
void CPlayerUI::Load()
{
	LifeHndl = LoadGraph(PLAYER_LIFE_PATH);
	BgHndl = LoadGraph(PLAYER_LIFEBACK_PATH);
}

//���t���[���s������
void CPlayerUI::Step()
{
	//�ߋ����C�t�Ɋi�[
	PreLife = CurrentLife;
	//�v���C���[�̌��݃��C�t���擾
	CurrentLife = CPlayer::GetInstance()->GetPlayerLife();

	//�����x�ύX
	Alpha_Change();
}

//�`��
void CPlayerUI::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, Alpha);
	DrawRectGraph(DRAW_X, DRAW_Y, 0, 0, PLAYER_MAX_LIFE, 30, BgHndl, true, false);
	DrawRectGraph(DRAW_X, DRAW_Y, 0, 0, CurrentLife, 30, LifeHndl, true, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//�㏈��
void CPlayerUI::Exit()
{
	LifeHndl = -1;
	CurrentLife = 0;
	PreLife = 0;
	Alpha = 0;
	Count = 0;
}


//�����x�ύX
void CPlayerUI::Alpha_Change()
{
	//���C�t�������Ȃ�
	if (CurrentLife == PreLife)
	{
		//�J�E���g����
		Count++;
	}
	else
	{
		Alpha = 200;
		Count = 0;
	}

	if (Count > 100)
	{
		//�����x��������
		Alpha -= 2;
		if (Alpha < 0)
		{
			Alpha = 0;
			Count = 0;
		}
	}
}