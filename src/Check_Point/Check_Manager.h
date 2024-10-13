#pragma once
#include "Check_Base.h"
#include "Check_Point.h"
#include "../Input/Input.h"

#define MAX_NUM	(5)

enum CHECK_ID
{
	ID_CHECK_POINT = 0,	//�`�F�b�N�|�C���g
	ID_ENEMY_SPAWN,		//�G�̕����|�C���g

	ID_NUM
};

class CChecck_Manager
{
private:
	

	vector<VECTOR> Point_info_List;
	vector<CCheck_Base*> Info_List;
	FILE* fp;

	CHECK_ID check_id;
	int check_Hndl;
	CCheck_Point cCheck_Point[MAX_NUM];


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CChecck_Manager();
	~CChecck_Manager();

	//������
	void Init();

	//�S�Ă̏��ǂݎ��
	void LoadInfo();

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

	//Id�擾�֐�
	CHECK_ID GetId() { return check_id; }
};
