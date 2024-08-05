#pragma once
#include <DxLib.h>

//�I�u�W�F�N�g�N���X
class CBase
{

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBase();
	~CBase();

	//������
	void Init();

	//�ǂݍ��݊֘A
	bool Load(const char FILEPATH[]);

	//�`��
	void Draw();

	//���t���[���s������
	virtual void Step() = 0;

	//�X�V����
	void Update();

	//�㏈��
	void Exit();

protected:
	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l

	int iHndl;			//�n���h��
};
