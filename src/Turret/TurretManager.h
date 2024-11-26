#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include <list>
#include "../CollisionManager/Collision/Collision.h"
#include "../Turret/TurretBase.h"
#include "../Turret/Turret_Normal.h"


using namespace std;

//�^���b�g�}�l�[�W���[�N���X
class CTurretManager
{
private:
	
	int Turret_Normal_Hndl;				//�m�[�}���^���b�g���f���̃R�s�[��
	
	vector<CTurretBase*> Turret_List;	//CTurretBase�^��List�z��


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
	void Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();

	//�^���b�g�ݒu����
	void TurretSpawn(const VECTOR& vPos);
};