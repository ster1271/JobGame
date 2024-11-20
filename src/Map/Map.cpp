#pragma once
#include "Map.h"

#define MAP_SIZE		50	//�}�b�v�̃T�C�Y
#define MAP_MAX_NUM		10	//�}�b�v�̏c��

const char BLOCK_MODEL_PATH[] = "data/Map/block.x";
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
		MV1SetPosition(WallList[i].iHndl, WallList[i].vPos);		//���W�̍X�V
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
	int WallHndl = MV1LoadModel(BLOCK_MODEL_PATH);
	int FloarHndl = MV1LoadModel(FLOAR_MODEL_PATH);

	WallInfo Walltmp;
	FloarInfo Floartmp;

	int cnt = 0;
	int num[MAP_MAX_NUM] = { 0 };
	fopen_s(&fp_, "Data/Map/Maptest.csv", "r");
	if (fp_ != nullptr)
	{
	
		while (fscanf_s(fp_, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
			&num[0], &num[1], &num[2], &num[3], &num[4],
			&num[5], &num[6], &num[7], &num[8], &num[9]) != EOF)
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
	fclose(fp_);
}


void CMap::Draw()
{
	cSize = VGet(50.0f, 50.0f, 50.0f);
	for (int i = 0; i < WallList.size(); i++)
	{
		MV1DrawModel(WallList[i].iHndl);
	}

	for (int i = 0; i < FloarList.size(); i++)
	{
		MV1DrawModel(FloarList[i].iHndl);
	}
}
