#pragma once
#include "../Base/Base.h"


//�A�^�b�J�[�N���X
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
	void Step(CShotManager &cShotManager);

	//�X�V����
	void Update();

	//�`��
	void Draw();

	//�I������
	void Exit();
};
