#pragma once
#include "../Shot/ShotBase.h"

const int SHOTRADIUS	(1);
const float GRAVITY		(0.01f);

class CShot:public CShotBase
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CShot();
	~CShot();

	//������
	void Init();

	//�f�[�^���[�h
	void Load(int iMdlHndl);

	//�I������
	void Exit();

	//���t���[���Ăԏ���
	void Step(VECTOR Pos);

	//�`�揈��
	void Draw();

	//���N�G�X�g
	bool RequestShot(const VECTOR& vPos, const VECTOR& vSpeed);

	//�����蔻��̏���
	void HitCalc()
	{
		//����������t���O������
		IsActive = false;
	}
};