#pragma once
#include "TurretBase.h"

//�^���b�g�N���X(�ʏ�)
class CTurret_Normal: public TurretBase
{
private:
	float Attack;
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CTurret_Normal();
	~CTurret_Normal();

	//������
	void Init();

	//�f�[�^���[�h
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//�㏈��
	void Exit();

	//�^���b�g�ݒu����
	bool TurretSpawn(const VECTOR &vPos);
};
