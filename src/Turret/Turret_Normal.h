#pragma once
#include "TurretBase.h"

//�^���b�g�N���X(�ʏ�)
class CTurret_Normal: public CTurretBase
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
	void Load(int Hndl);

	//�`��
	void Draw();

	//���t���[���s������
	void Step(const VECTOR vPos);

	//�㏈��
	void Exit();

	//�^���b�g�ݒu����
	void TurretSpawn(const VECTOR &vPos);

	//�^���b�g�e���ˏ���


	//�^���b�g����
	void Turret_Power_Up();

};
