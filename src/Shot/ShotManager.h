#pragma once
#include "Shot.h"


#define PL_SHOT_NUM	(3)

class CShotManager
{
private:
	//�v���C���[�̃V���b�g
	//�������̓��I�m�ۂ��]�܂���
	CShot cPlayerShot[PL_SHOT_NUM];

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CShotManager();
	~CShotManager();

	//������
	void Init();
	//�f�[�^���[�h
	void Load();
	//�I������
	void Exit();
	//�J��Ԃ��s������
	void Step(VECTOR Pos);
	//�`�揈��
	void Draw();

	//�v���C���[�̃V���b�g���擾
	inline CShot& GetPlayerShot(int iID) { return cPlayerShot[iID]; }

	//�v���C���[�̃V���b�g���N�G�X�g
	void RequestPlayerShot(const VECTOR& vPos, const VECTOR& vSpeed, const float& YSpeed);
};