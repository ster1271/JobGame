#pragma once
#include "../Wave/Wave.h"

//UI�}�l�[�W���[
class CUIManager
{
private:
	static CUIManager* cInstance;		//�C���X�^���X

	//�R���X�g���N�^�E�f�X�g���N�^
	CUIManager();
	~CUIManager();

	int hnd;

public:

	static void Create();				//�C���X�^���X�̐���

	static void Destroy();				//�C���X�^���X�̍폜

	static CUIManager* GetInstance();	//�C���X�^���X�̎擾

	//�`��
	void Draw();
};
