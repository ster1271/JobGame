#include "Ground.h"

//�R���X�g���N�^
CGround::CGround()
{

}

//�f�X�g���N�^
CGround::~CGround()
{

}

//������
void CGround::Init()
{
	cPos = VGet(0.0f, 0.0f, 0.0f);
	iHndl = MV1LoadModel("Data/field/field.x");
	MV1SetPosition(iHndl, cPos);
	MV1SetScale(iHndl, VGet(0.1f, 0.1f, 0.1f));
}

//�`��
void CGround::Draw()
{
	MV1DrawModel(iHndl);
}