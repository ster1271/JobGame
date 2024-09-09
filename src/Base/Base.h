#pragma once
#include <DxLib.h>
#include "math.h"
#include "../Input/Input.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"

//�q���[�}���x�[�X�N���X
class CBase
{
protected:
	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l

	float Life;			//���C�t
	int iHndl;			//�n���h��

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBase();
	~CBase();

	//������
	void Init();

	//�ǂݍ��݊֘A
	bool Load(const char FILEPATH[]);

	//�`��
	void Draw();

	//���t���[���s������
	virtual void Step(CShotManager& cShotManager, CTurretManager& cTurretManager) = 0;

	//�X�V����
	void Update();

	//�㏈��
	void Exit();

	//���W�擾
	VECTOR GetPos() { return cPos; }

	//�T�C�Y�擾
	VECTOR GetSize() { return cSize; }

	//��]�n�擾
	VECTOR GetRotate() { return cRotate; }

};
