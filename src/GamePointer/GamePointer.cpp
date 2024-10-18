#include "GamePointer.h"

#define MOVE_SPEED	(3.0f)

//�R���X�g���N�^�E�f�X�g���N�^
CGame_Pointer::CGame_Pointer()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cBoxSize, 0, sizeof(VECTOR));
	iHndl = -1;
	
}

CGame_Pointer::~CGame_Pointer() {};

//������
void CGame_Pointer::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	cPos = VGet(0.0f, 5.0f, 0.0f);
	cBoxSize = VGet(20.0f, 20.0f, 20.0f);
	iHndl = -1;
}

//�ǂݍ���
void CGame_Pointer::Load()
{

}

//���t���[���s������
void CGame_Pointer::Step(CHECK_ID id)
{
	
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		cPos.z += MOVE_SPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		cPos.z -= MOVE_SPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_A)) {
		cPos.x -= MOVE_SPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_D)) {
		cPos.x += MOVE_SPEED;
	}

	

}

//�`��
void CGame_Pointer::Draw(CHECK_ID id)
{
	/*if (id == ID_CHECK_POINT)
	{
		MV1DrawModel();
	}
	else
	{
		CDraw3D::DrawBox3D(cPos, cBoxSize);
	}*/

	CDraw3D::DrawBox3D(cPos, cBoxSize);

}

//�㏈��
void CGame_Pointer::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	cBoxSize = VGet(100.0f, 100.0f, 100.0f);
	iHndl = -1;
}