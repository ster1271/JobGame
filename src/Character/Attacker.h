#pragma once
#include "../Base/Base.h"
#include "../Input/Input.h"

class CAttacker : public CBase
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CAttacker();
	~CAttacker();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load();

	//���t���[���s������
	void Step();

	//�X�V����
	void Update();

	//�`��
	void Draw();

	//�I������
	void Exit();
};
