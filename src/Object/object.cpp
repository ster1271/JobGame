#include "object.h"

//�R���X�g���N�^
CObject::CObject()
{
	cHp = 0;
	iHndl = -1;

	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	cGravity = 0.0f;
	cYspeed = 0.0f;
}

//�f�X�g���N�^
CObject::~CObject()
{
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
	}
}


