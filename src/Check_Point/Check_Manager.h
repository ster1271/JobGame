#pragma once
#include "Check_Point.h"
#include "../Input/Input.h"

#define MAX_NUM	(5)

class CChecck_Manager
{
private:
	enum Check_ID
	{
		ID_CHECK_POINT = 0,	//�`�F�b�N�|�C���g
		ID_ENEMY_SPAWN,		//�G�̕����|�C���g

		ID_NUM
	};

	Check_ID check_id;
	int check_Hndl;
	CCheck_Point cCheck_Point[MAX_NUM];

	vector<VECTOR> Point_info_List;
	FILE* fp;


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CChecck_Manager();
	~CChecck_Manager();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load();

	//�㏈��
	void Exit();

	//���X�V
	void Updata();

	//�`��
	void Draw();

	//�v���C���̏���
	void Step();

	//�f�o�b�N���̏���
	void DebugStep(VECTOR vPos);

	//�f�o�b�N���̕`��
	void DebugDraw();

	//���X�g���擾
	vector<VECTOR> Get_List()
	{
		return Point_info_List;
	}
};
