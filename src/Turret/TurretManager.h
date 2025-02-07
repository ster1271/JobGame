#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include <list>
#include "../CollisionManager/Collision/Collision.h"
#include "../Turret/TurretBase.h"
#include "../Turret/Turret_Normal.h"

#include "../Wave/Wave.h"

using namespace std;

const char TURRETPLACEPATH[3][128]
{
	"data/Turret/TurretPlace.txt",
};


//�^���b�g�}�l�[�W���[�N���X
class CTurretManager
{
private:
	
	//�^���b�g�ݒu�ꏊ���
	struct TurretPlaceInfo
	{
		VECTOR vPos;		//���W
		VECTOR vSize;		//�T�C�Y
		int iHndl;			//���f���n���h��(�R�s�[)
		bool IsInstall;		//�ݒu�ł��邩�ǂ���
	};

	int Turret_Normal_Hndl;				//�m�[�}���^���b�g���f���̃R�s�[��
	
	vector<CTurretBase*> Turret_List;	//CTurretBase�^��List�z��
	vector<TurretPlaceInfo> PlaceList;


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
	void TurretSpawn(VECTOR vPos);

	//�^���b�g�ݒu�ꏊ�ǂݍ��ݏ���
	void LoadTurretSpawn();
};