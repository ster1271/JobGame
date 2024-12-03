#pragma once
#include "../../Common.h"

const VECTOR GOAL_SIZE = VGet(70.0f, 50.0f, 50.0f);


class CGoal
{
private:
	VECTOR cPos;		//���W
	VECTOR cRotate;		//��]�l
	VECTOR cSize;		//�T�C�Y

	int iHndl;			//���f���n���h��
	bool IsActive;		//�t���O

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CGoal();
	~CGoal();

	//������
	void Init();

	//�ǂݍ��݊֘A
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	virtual void Step();

	//�X�V����
	void Update();

	//�㏈��
	void Exit();

	//���W�擾
	VECTOR GetPos() { return cPos; }

	//�T�C�Y�擾
	VECTOR GetSize() { return cSize; }

	//��]�n�擾
	VECTOR GetRotate() { return cRotate; }
};
