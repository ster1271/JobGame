#include "Goal.h"
#include "../../Debug/DebugString.h"

const char MODEL_PATH[] = "data/Map/door.x";

//�R���X�g���N�^
CGoal::CGoal()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//�f�X�g���N�^
CGoal::~CGoal()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//������
void CGoal::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	cPos = VGet(600.0f, -20.0f, 100.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(0.2f, 0.2f, 0.2f);

	IsActive = true;
}

//�ǂݍ��݊֘A
void CGoal::Load()
{
	iHndl = MV1LoadModel(MODEL_PATH);
}

//�`��
void CGoal::Draw()
{
	if (!IsActive)
		return;

	MV1DrawModel(iHndl);

	CDraw3D::DrawBox3D(cPos, GOAL_SIZE, GetColor(255, 255, 0));
}

//���t���[���s������
void CGoal::Step()
{
	if (!IsActive)
		return;
}

//�X�V����
void CGoal::Update()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}

//�㏈��
void CGoal::Exit()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}