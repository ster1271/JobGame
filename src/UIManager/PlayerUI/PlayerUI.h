#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Player/Player.h"

class CPlayerUI :public CUIBase
{
private:
	int LifeHndl;
	int BgHndl;
	float CurrentLife;	//���݃��C�t�i�[
	float PreLife;		//�ߋ����C�t�i�[
	int Alpha;			//�����x
	int Count;		

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CPlayerUI();
	~CPlayerUI();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//���t���[���s������
	void Step();

	//�`��
	void Draw();

	//�㏈��
	void Exit();

	//�����x�ύX
	void Alpha_Change();
};
