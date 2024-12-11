#include"EnemyBase.h"


const int MAX_LIFE		(3);		//�ő�̗�
const float SPEED		(1.0f);		//�ړ����x

//--------------------------------------
//�R���X�g���N�^
//--------------------------------------
CEnemyBase::CEnemyBase()
{
	//�ЂƂ܂�������
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	State_Id = STATE_NUM;
	Radius = ENEMY_RADIUS;
	Life = 0;			//���C�t
	HitCount = 0;		//�e�̓���������
	iHndl = -1;			//�n���h��

	IsActive = false;	//�����t���O

}

//--------------------------------------
//�f�X�g���N�^
//--------------------------------------
CEnemyBase::~CEnemyBase()
{
	//�{���͕K�v�Ȃ����O�̂���
	Exit();
}

//--------------------------------------
//������
//--------------------------------------
void CEnemyBase::Init()
{
	//�ЂƂ܂�������
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	State_Id = STATE_MOVE;
	Life = 0;;			//���C�t
	HitCount = 0;;		//�e�̓���������
	iHndl = -1;			//�n���h��
	ListCnt = 0;
	DeathCnt = 0;

	IsActive = false;	//�����t���O
}

//--------------------------------------
//�I������
//--------------------------------------
void CEnemyBase::Exit()
{
	//���f���n���h�����
	/*if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}*/

	//�ЂƂ܂�������
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	Life = 0;;			//���C�t
	HitCount = 0;;		//�e�̓���������


	IsActive = false;	//�����t���O
}

//--------------------------------------
//�f�[�^���[�h
//--------------------------------------

void CEnemyBase::Load(int iMdlHndl)
{
	if (iHndl == -1)
	{
		iHndl = MV1DuplicateModel(iMdlHndl);
	}
}


//--------------------------------------
//�`�揈��
//--------------------------------------
void CEnemyBase::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		//�f�o�b�N�p---------------------------------------------------------------------
		/*
		int R, G, B;
		B = 255;
		R = G = 0;


		switch (HitCount)
		{
		//�����������ĂȂ��Ƃ�
		case 0:
			break;
			B = 255;
			R = G = 0;
		//��񓖂������Ƃ�
		case 1:
			G = 255;
			R = B = 0;

			break;
		//��񓖂������Ƃ�
		case 2:
			R = 255;
			G = B = 0;

			break;

		default:
			break;
		}
		DrawSphere3D(cPos, Radius, 16, GetColor(R, G, B), GetColor(R, G, B), false);
		*/
		//�f�o�b�N�p---------------------------------------------------------------------
	}

}


//--------------------------------------
//���N�G�X�g
//--------------------------------------
bool CEnemyBase::RequestEnemy(const VECTOR &vPos, const VECTOR &vSpeed)
{
	//���łɏo�����Ă���
	if (IsActive)
	{
		return false;
	}

	cPos = vPos;
	cNextPos = cPos;
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}

//--------------------------------------
//���t���[���Ăԏ���
//--------------------------------------
void CEnemyBase::Step()
{
}

//�X�V����
void CEnemyBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cScale);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}


//�ړ�����
void CEnemyBase::Enemy_Move(vector<VECTOR> List, int& Cnt)
{
	cPos = cNextPos;
	//�i�s�����̂ǂ��瑤�ɂ���̂��𒲂ׂ�
	float Dir = 0.0f;

	//�{�b�g����w��̒n�_�֍s���x�N�g�����v�Z
	VECTOR Vtmp;
	Vtmp.x = List[Cnt].x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = List[Cnt].z - cPos.z;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//�{�b�g�̈ړ��x�N�g��
	vSpd.x = sinf(cRotate.y) * -SPEED;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -SPEED;

	//�O�όv�Z
	Dir = (Vtmp.x * vSpd.z) - (vSpd.x * Vtmp.z);

	if (fabsf(Dir) < 1.0f)
	{
		float X = Vtmp.x = cPos.x - List[Cnt].x;
		float Z = Vtmp.x = cPos.z - List[Cnt].z;

		//�w��̈ʒu�֊p�x��ς���
		float NextRotY = atan2f(X, Z);

		cRotate.y = NextRotY;
	}
	else if (Dir >= 0.0f)//����ȊO�͊p�x��ς���
	{
		cRotate.y += 0.08f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.08f;
	}


	//���W�ɑ��x�����Z����
	cNextPos.x += sinf(cRotate.y) * -0.2f;
	cNextPos.z += cosf(cRotate.y) * -0.2f;

	//�v���C���[�Ƃ̋������v�Z
	VECTOR v_tmp;
	v_tmp.x = List[Cnt].x - cPos.x;
	v_tmp.y = 0.0f;
	v_tmp.z = List[Cnt].z - cPos.z;

	float Range = VSize(v_tmp);

	//���������l�ɒB������Id��ύX����
	if (Range < 0.5f)
	{
		Cnt++;

		if (Cnt == List.size())
		{
			State_Id = STATE_SEARCH;
		}
	}
	
}

//�����ǔ�����
void CEnemyBase::Out_Move(VECTOR vPos)
{
	//�i�s�����̂ǂ��瑤�ɂ���̂��𒲂ׂ�
	float Dir = 0.0f;

	//�{�b�g����w��̒n�_�֍s���x�N�g�����v�Z
	VECTOR Vtmp;
	Vtmp.x = vPos.x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = vPos.z - cPos.z;

	float Speed = 1.0f;
	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//�{�b�g�̈ړ��x�N�g��
	vSpd.x = sinf(cRotate.y) * -Speed;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -Speed;

	//�O�όv�Z
	Dir = (Vtmp.x * vSpd.z) - (vSpd.x * Vtmp.z);

	if (fabsf(Dir) < 1.0f)
	{
		float X = cPos.x - vPos.x;
		float Z = cPos.z - vPos.z;

		//�w��̈ʒu�֊p�x��ς���
		float NextRotY = atan2f(X, Z);

		cRotate.y = NextRotY;
	}
	else if (Dir >= 0.0f)//����ȊO�͊p�x��ς���
	{
		cRotate.y += 0.05f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.05f;
	}

	//���W�ɑ��x�����Z����
	cPos.x += sinf(cRotate.y) * -0.2f;
	cPos.z += cosf(cRotate.y) * -0.2f;
}


//�����t���O�ݒ�
void CEnemyBase::SetDir()
{
	if (cNextPos.x > cPos.x)
	{
		//�E�ɓ����Ă���
		IsDir[ENEMY_DIR_RIGHT] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_RIGHT] = false;
	}

	if (cNextPos.x < cPos.x)
	{
		//���ɓ����Ă���
		IsDir[ENEMY_DIR_LEFT] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_LEFT] = false;
	}

	if (cNextPos.y > cPos.y)
	{
		//��ɓ����Ă���
		IsDir[ENEMY_DIR_UP] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_UP] = false;
	}

	if (cNextPos.y < cPos.y)
	{
		//���ɓ����Ă���
		IsDir[ENEMY_DIR_DOWN] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_DOWN] = false;
	}

	if (cNextPos.z > cPos.z)
	{
		//���ɓ����Ă���
		IsDir[ENEMY_DIR_BACK] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_BACK] = false;
	}

	if (cNextPos.z < cPos.z)
	{
		//��O�ɓ����Ă���
		IsDir[ENEMY_DIR_NEAR] = true;
	}
	else
	{
		IsDir[ENEMY_DIR_NEAR] = false;
	}
}


