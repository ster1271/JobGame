#pragma once
#include "../object.h"

#define MAX_NUM		(10)

class CGround :public CObject
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
	CGround();
	~CGround();
	

	//������
	void Init();

	//���f���ǂݍ���
	void Load();

	//�`��
	void Draw();

};
