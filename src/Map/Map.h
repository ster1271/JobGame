#pragma once
#include "../Object/Object.h"

const VECTOR MAP_SIZE = VGet(50.0f, 50.0f, 50.0f);
const float MAP_R = 30.0f;

enum MapID
{
	MAPID_01,


	MAPID_NUM
};

//�}�b�v�̃t�@�C���p�X
static const char MapFilePath[MAPID_NUM][128]
{
	"Data/Map/map01.txt",
};


struct WallInfo
{
	VECTOR vPos;
	VECTOR MiniMapPos;
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

	//�}�b�v�̓ǂݍ���1
	void LoadMap1(MapID id);

	//�}�b�v�̓ǂݍ���2
	void LoadMap2(MapID id);
};



