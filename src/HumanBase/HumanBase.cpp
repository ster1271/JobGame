#include "HumanBase.h"
#include "../Mouse/Mouse.h"


//�R���X�g���N�^
CHumanBase::CHumanBase()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cMoveRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	IsActive = false;

	MouseX = MouseY = 0;

	Life = -1;
	iHndl = -1;
	PushCnt = 0;
	ReturnCnt = 0;
}

//�f�X�g���N�^
CHumanBase::~CHumanBase(){}


//������
void CHumanBase::Init()
{
	//�ϐ��̏�����
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	IsActive = false;

	MouseX = MouseY = 0;

	Life = 0;
	iHndl = 0;
	PushCnt = 0;
	ReturnCnt = 0;
}

//�f�[�^�ǂݍ���
void CHumanBase::Load(const char FILEPATH[])
{
	iHndl = MV1LoadModel(FILEPATH);
}

//�`��
void CHumanBase::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		CDraw3D::DrawBox3D(cPos, cSize);
	}

}

//���t���[���s������
void CHumanBase::Step(){}

//���X�V
void CHumanBase::UpData()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cScale);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V

	CAnim::UpdateAnim(iHndl);						//�A�j���[�V�����̏��X�V
}

//�㏈��
void CHumanBase::Exit()
{
	//�ϐ��̏�����
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	IsActive = false;

	MouseX = MouseY = 0;

	Life = -1;
	iHndl = -1;
	PushCnt = 0;
	ReturnCnt = 0;
}

//�L�����N�^�[��]����
void CHumanBase::Player_Rotation()
{
	StoreRot = cRotate.y;


	if (CGamePad::GetPadNumState() != 0)
	{
		cRotate.y = CGamePad::StickRot(STICK_RIGHT);
	}
	else
	{
		cRotate.y = CMouse::MouseToRot();
	}

	if (cRotate.y == 0.0f)
	{
		cRotate.y = StoreRot;
	}

}

//�����t���O�ݒ�
void CHumanBase::SetDir()
{
	if (cNextPos.x > cPos.x)
	{
		//�E�ɓ����Ă���
		IsDir[DIR_RIGHT] = true;
	}
	else
	{
		IsDir[DIR_RIGHT] = false;
	}

	if (cNextPos.x < cPos.x)
	{
		//���ɓ����Ă���
		IsDir[DIR_LEFT] = true;
	}
	else
	{
		IsDir[DIR_LEFT] = false;
	}

	if (cNextPos.y > cPos.y)
	{
		//��ɓ����Ă���
		IsDir[DIR_UP] = true;
	}
	else
	{
		IsDir[DIR_UP] = false;
	}

	if (cNextPos.y < cPos.y)
	{
		//���ɓ����Ă���
		IsDir[DIR_DOWN] = true;
	}
	else
	{
		IsDir[DIR_DOWN] = false;
	}

	if (cNextPos.z > cPos.z)
	{
		//���ɓ����Ă���
		IsDir[DIR_BACK] = true;
	}
	else
	{
		IsDir[DIR_BACK] = false;
	}

	if (cNextPos.z < cPos.z)
	{
		//��O�ɓ����Ă���
		IsDir[DIR_NEAR] = true;
	}
	else
	{
		IsDir[DIR_NEAR] = false;
	}
}

