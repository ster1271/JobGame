#pragma once
#include "../Object/Object.h"

#define MAX_NUM		(10)

class CMap :public CObject
{
	struct MapInfo
	{
		VECTOR vPos;
		bool IsMap;
	};


private:

	MapInfo Mapinfo;
	int tmp[MAX_NUM][MAX_NUM];
	FILE* fp_;

	vector<MapInfo>MapList;

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

};



