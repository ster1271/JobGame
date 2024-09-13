#pragma once
#include <DxLib.h>
#include "../Turret/Turret_Normal.h"

//�^���b�g�}�l�[�W���[�N���X
class CTurretManager
{
private:
	CTurret_Normal cTurret_Normal;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CTurretManager();
	~CTurretManager();


	//������
	void Init();
	//�f�[�^���[�h
	void Load();
	//�I������
	void Exit();
	//�J��Ԃ��s������
	void Step(VECTOR Pos);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();

	//�^���b�g�ݒu����
	void TurretSpawn(const VECTOR& vPos);
};