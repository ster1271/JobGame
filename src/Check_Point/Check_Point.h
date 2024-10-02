#pragma once
#include <DxLib.h>
#include "BaseCheck.h"

class CCheck_Point : public CBase_Check
{
private:
	int tmp_Hndl;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CCheck_Point();
	~CCheck_Point();

	//������
	void Init();

	//���f���ǂݍ���
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//�㏈��
	void Exit();

	//�ݒu����
	void Set_Point(const VECTOR vPos);

};
