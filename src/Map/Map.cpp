#pragma once
#include "Map.h"

#define MAP_SIZE		50	//�}�b�v�̃T�C�Y
#define MAP_MAX_NUM		14	//�}�b�v�̏c��

const char WALL_MODEL_PATH[] = "data/Map/wall.x";
const char FLOAR_MODEL_PATH[] = "data/Map/floar.x";

//�R���X�g���N�^
CMap::CMap()
{
}

//�f�X�g���N�^
CMap::~CMap()
{
}

//������
void CMap::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	//�e�ϐ��̏�����
	cPos = VECTOR_ZERO;
	cScale = VGet(2.5f, 2.5f, 2.5f);
	cRotate = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	WallList.clear();
	FloarList.clear();
}

//���f���ǂݍ���
void CMap::Load()
{
	//�t�@�C���ǂݍ���
	MapLoad();
}

//�X�V
void CMap::Updata()
{
	for (int i = 0; i < WallList.size(); i++)
	{
		MV1SetPosition(WallList[i].iHndl, WallList[i].vPos);	//���W�̍X�V
		MV1SetScale(WallList[i].iHndl, cScale);					//�T�C�Y�̍X�V
		MV1SetRotationXYZ(WallList[i].iHndl, cRotate);			//��]�l�̍X�V
	}

	for (int i = 0; i < FloarList.size(); i++)
	{
		MV1SetPosition(FloarList[i].iHndl, FloarList[i].vPos);		//���W�̍X�V
		MV1SetScale(FloarList[i].iHndl, cScale);					//�T�C�Y�̍X�V
		MV1SetRotationXYZ(FloarList[i].iHndl, cRotate);				//��]�l�̍X�V
	}
}

//CSV�ǂݍ���
void CMap::MapLoad()
{
	//���@1(1�����ǂݍ���)
	LoadMap1(MAPID_01);

	//���@2(1�s�ǂݍ���)
	//LoadMap2();		
}


void CMap::Draw()
{
	for (int i = 0; i < WallList.size(); i++)
	{
		MV1DrawModel(WallList[i].iHndl);
	}

	for (int i = 0; i < FloarList.size(); i++)
	{
		MV1DrawModel(FloarList[i].iHndl);
	}
}

//�}�b�v�̓ǂݍ���1
void CMap::LoadMap1(MapID id)
{
	int WallHndl = MV1LoadModel(WALL_MODEL_PATH);
	int FloarHndl = MV1LoadModel(FLOAR_MODEL_PATH);

	WallInfo Walltmp;
	FloarInfo Floartmp;

	fopen_s(&fp_, MapFilePath[id], "r");		//CSV�t�@�C���ǂݍ���

	if (fp_ != nullptr)
	{
		int FileIndexX = 0;
		int FileIndexY = 0;
		int cnt = 0;

		while (true) {
			// ���l������ǂݍ���
			char FileNum = fgetc(fp_);
			cnt++;

			if (FileNum == '0')
			{
				//��
				Floartmp.vPos = VGet(FileIndexX * MAP_SIZE, -40.0f, FileIndexY * MAP_SIZE);
				Floartmp.IsMap = false;
				Floartmp.iHndl = MV1DuplicateModel(FloarHndl);
				FloarList.push_back(Floartmp);
			}
			else if (FileNum == '1')
			{
				//��
				Walltmp.vPos = VGet(FileIndexX * MAP_SIZE, 5.0f, FileIndexY * MAP_SIZE);
				Walltmp.MiniMapPos = VGet(FileIndexX * 10.0f, FileIndexY * 10.0f, 0.0f);
				Walltmp.IsMap = true;
				Walltmp.iHndl = MV1DuplicateModel(WallHndl);
				WallList.push_back(Walltmp);
			}

			FileIndexX++;

			// �u,�v���΂����߂ɓǂݍ��݂����s
			FileNum = fgetc(fp_);

			// EOF�̏ꍇ�͓ǂݍ��ݏI��
			if (FileNum == EOF)
			{
				break;
			}

			// ���s�R�[�h�̏ꍇ�͕ۑ����ύX����
			if (FileNum == '\n')
			{
				FileIndexY++;
				FileIndexX = 0;
			}
		}
	}
	fclose(fp_);
}

//�}�b�v�̓ǂݍ���2
void CMap::LoadMap2(MapID id)
{
	int WallHndl = MV1LoadModel(WALL_MODEL_PATH);
	int FloarHndl = MV1LoadModel(FLOAR_MODEL_PATH);

	WallInfo Walltmp;
	FloarInfo Floartmp;

	int cnt = 0;
	int num[MAP_MAX_NUM] = { 0 };
	fopen_s(&fp_, MapFilePath[id], "r");		//�t�@�C���ǂݍ���

	//���@1
	if (fp_ != nullptr)
	{

		while (fscanf_s(fp_, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
			&num[0], &num[1], &num[2], &num[3], &num[4],
			&num[5], &num[6], &num[7], &num[8], &num[9],
			&num[10], &num[11], &num[12], &num[13]) != EOF)
		{
			for (int i = 0; i < MAP_MAX_NUM; i++)
			{
				if (num[i] == 1)
				{
					Walltmp.vPos = VGet(i * MAP_SIZE, 5.0f, cnt * MAP_SIZE);
					Walltmp.IsMap = true;
					Walltmp.iHndl = MV1DuplicateModel(WallHndl);	//��
					WallList.push_back(Walltmp);
				}
				else if (num[i] == 0)
				{
					Floartmp.vPos = VGet(i * MAP_SIZE, -40.0f, cnt * MAP_SIZE);
					Floartmp.IsMap = false;
					Floartmp.iHndl = MV1DuplicateModel(FloarHndl);	//��
					FloarList.push_back(Floartmp);
				}
			}
			cnt++;
		}
	}
}
