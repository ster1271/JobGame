#pragma once

//UI�}�l�[�W���[
class CUIManager
{
private:


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CUIManager();
	~CUIManager();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//���X�V
	void Updata();

	//�㏈��
	void Exit();
};
