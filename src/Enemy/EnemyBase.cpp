#include"EnemyBase.h"


const float NEMY_RADIUS	(5.0f);		//���f���̔��a
const int MAX_LIFE		(3);		//�ő�̗�
const float SPEED		(1.0f);		//�ړ����x

//--------------------------------------
//�R���X�g���N�^
//--------------------------------------
CEnemyBase::CEnemyBase()
{
	//�ЂƂ܂�������
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	Radius = NEMY_RADIUS;
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
	cPos = VGet(0.0f, 0.0f, 0.0f);
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	Life = 0;;			//���C�t
	HitCount = 0;;		//�e�̓���������
	iHndl = -1;			//�n���h��

	IsActive = false;	//�����t���O
}

//--------------------------------------
//�I������
//--------------------------------------
void CEnemyBase::Exit()
{
	//���f���n���h�����
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	//�ЂƂ܂�������
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

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
	Life = MAX_LIFE;
	IsActive = true;

	//��x���W�X�V���Ă���
	MV1SetPosition(iHndl, cPos);
	return true;
}

//--------------------------------------
//���t���[���Ăԏ���
//--------------------------------------
void CEnemyBase::Step()
{
	if (!IsActive)
	{
		return;
	}

	//���W�ɑ��x�����Z
	cPos = VAdd(cPos, VGet(SPEED, 0.0f, SPEED));
	//���͈͂𒴂��������
	float fLength = 300.0f;
	if (cPos.x > fLength || cPos.x < -fLength
		|| cPos.z > fLength || cPos.z < -fLength)
	{
		IsActive = false;
	}

	//�X�V����
	Update();
}

//�X�V����
void CEnemyBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}



