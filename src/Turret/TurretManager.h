#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include <list>
#include "../Turret/TurretBase.h"
#include "../Turret/Turret_Normal.h"

//static const int TURRET_MAX = 30;	//�^���b�g�̍ő吔

using namespace std;

//�^���b�g�}�l�[�W���[�N���X
class CTurretManager
{
private:
	//���f���̃R�s�[��
	int Org_Hndl;
	
	//CTurretBase�^��List�z��
	vector<CTurretBase*> Turret_List;

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