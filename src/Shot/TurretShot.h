#pragma once
#include "../Shot/ShotBase.h"

class CTurretShot:public CShotBase
{
private:


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CTurretShot();
	~CTurretShot();

	//������
	void Init();

	//�ǂݍ���
	void Load(int iMdlHndl);

	//�`��
	void Draw();

	//���t���[���s������
	void Step(VECTOR TurretPos);

	//���N�G�X�g
	bool RequestShot(const VECTOR& vPos, const VECTOR& vSpeed);
};
