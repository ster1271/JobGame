#pragma once
#include "../Object/Object.h"
#include "block/block.h"

const VECTOR MAP_SIZE = VGet(50.0f, 50.0f, 50.0f);

//�}�b�v���
struct MapInfo
{
	VECTOR vPos;
	bool IsMap;
	int iHndl;
};

class CMap :public CObject
{

private:
	
	FILE* fp_;				//�t�@�C���p
	vector<MapInfo>MapList;	//�}�b�v���i�[���X�g

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

	//CSV�ǂݍ���
	void MapLoad();

	//�}�b�v���擾
	vector<MapInfo> GetMapInfo() { return MapList; }
};



