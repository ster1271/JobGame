#pragma once
#include "../Base/Base.h"

//�T�|�[�g�N���X
class CSupport : public CBase
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CSupport();
	~CSupport();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load();

	//���t���[���s������
	void Step(CShotManager& cShotManager);

	//�X�V����
	void Update();

	//�`��
	void Draw();

	//�I������
	void Exit();
};