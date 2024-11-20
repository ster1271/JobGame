#pragma once
#include "../Object/Object.h"
#include "block/block.h"

const VECTOR MAP_SIZE = VGet(50.0f, 50.0f, 50.0f);


struct WallInfo
{
	VECTOR vPos;
	bool IsMap;
	int iHndl;
};

struct FloarInfo
{
	VECTOR vPos;
	bool IsMap;
	int iHndl;
};

class CMap :public CObject
{

private:
	
	FILE* fp_;				//�t�@�C���p
	vector<WallInfo>WallList;	//�Ǐ��i�[���X�g
	vector<FloarInfo>FloarList;	//�����i�[���X�g

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CMap();
	~CMap();


	//������
	void Init();

	//���f���ǂݍ���
	void Load();

	//�`��
	void Draw();

	//�X�V
	void Updata();

	//CSV�ǂݍ���
	void MapLoad();

	//�Ǐ��擾
	vector<WallInfo> GetWallList() { return WallList; }
	
	//�����擾
	vector<FloarInfo> GetFloarList() { return FloarList; }
};



