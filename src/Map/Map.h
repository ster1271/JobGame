#pragma once
#include "../Object/Object.h"

class CMap :public CObject
{
	//�}�b�v���
	struct MapInfo
	{
		VECTOR vPos;
		bool IsMap;
	};


private:

	MapInfo Mapinfo;
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

	//��������

	//�}�b�v���擾
	vector<MapInfo> GetMapInfo() { return MapList; }
};



