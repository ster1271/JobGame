#pragma once
#include "../Common.h"
#include "Map.h"
#include "Goal/Goal.h"

class CMapManager
{
private:
	CMap cMap;
	CGoal cGoal;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CMapManager();
	~CMapManager();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//���X�V
	void Updata();

	//�㏈��
	void Exit();

	//�}�b�v�N���X�擾
	CMap GetMap() { return cMap; }

	//�S�[���N���X�擾
	CGoal GetGoal() { return cGoal; }

};
