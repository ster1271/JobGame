#pragma once
#include "../Base/Base.h"


//�^���N�N���X
class CTank : public CBase
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CTank();
	~CTank();

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