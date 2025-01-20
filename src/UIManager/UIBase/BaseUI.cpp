#include "BaseUI.h"

//èâä˙âª
void CUIBase::Init()
{
	memset(&cPos, -1, sizeof(VECTOR));
	memset(&cRotate, -1, sizeof(VECTOR));
	memset(&cSize, -1, sizeof(VECTOR));
}

//å„èàóù
void CUIBase::Exit()
{
	memset(&cPos, -1, sizeof(VECTOR));
	memset(&cRotate, -1, sizeof(VECTOR));
	memset(&cSize, -1, sizeof(VECTOR));
}