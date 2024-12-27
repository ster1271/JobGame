#pragma once
#include "../Common.h"
#include "../Player/Player.h"
#include "../Enemy/EnemyManager.h"
#include "../Map/MapManager.h"



//�~�j�}�b�v�N���X
class CMiniMap
{
private:
	VECTOR PlayerPos;
	VECTOR PlayerRot;
	vector<WallInfo> WallInfoList;
	vector<FloarInfo> FloarInfoList;

	int PlayerHndl;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CMiniMap();
	~CMiniMap();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step(VECTOR vPos, VECTOR vRot, CMapManager& cMapManager);

	//���X�V
	void UpData();

	//�㏈��
	void Exit();
};

