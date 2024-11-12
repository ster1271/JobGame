#pragma once
#include "../Object/Object.h"

//�}�b�v���
struct MapInfo
{
	VECTOR vPos;
	bool IsMap;
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

	//�}�b�v�T�C�Y�擾
	VECTOR GetMapSize() { return cSize; }
};



