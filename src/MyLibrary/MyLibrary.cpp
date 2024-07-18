#include "DxLib.h"
#include "MyLibrary.h"
#include <math.h>

//�x�N�g���̑����Z
VECTOR CMyLibrary::AddVec(VECTOR _vec1, VECTOR _vec2)
{
	VECTOR ret;

	ret.x = _vec1.x + _vec2.x;
	ret.y = _vec1.y + _vec2.y;
	ret.z = _vec1.z + _vec2.z;

	return ret;
}

//�x�N�g���̈����Z
VECTOR CMyLibrary::SubVec(VECTOR _vec1, VECTOR _vec2)
{
	VECTOR ret;

	ret.x = _vec1.x - _vec2.x;
	ret.y = _vec1.y - _vec2.y;
	ret.z = _vec1.z - _vec2.z;

	return ret;
}

//�x�N�g���𐶐�����֐�
VECTOR CMyLibrary::VecCreate(VECTOR start, VECTOR end)
{
	VECTOR ret;

	ret.x = end.x - start.x;
	ret.y = end.y - start.y;
	ret.z = end.z - start.z;
	
	return ret;
}

//�x�N�g���̒������v�Z����֐�
float CMyLibrary::VecLong(VECTOR vec)
{
	float veclong = 0.0f;
	
	veclong = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;

	veclong = sqrtf(veclong);

	return veclong;
}

//�x�N�g���𐳋K������֐�
VECTOR CMyLibrary::vecNormalize(VECTOR _vec)
{
	VECTOR ret;
	ret.y = _vec.y / VecLong(_vec);
	ret.y = _vec.y / VecLong(_vec);
	ret.z = _vec.z / VecLong(_vec);

	return ret;
}

//�x�N�g�����X�J���[�{����֐�
VECTOR CMyLibrary::Scale(VECTOR vec, float scale)
{
	VECTOR ret;

	ret.x = vec.x * scale;
	ret.y = vec.y * scale;
	ret.z = vec.z * scale;

	return ret;

}

//���ς����߂�֐�(2D)
float CMyLibrary::VecDot_2D(VECTOR vec1, VECTOR vec2)
{
	float ret;

	ret = vec1.x * vec2.x + vec1.y * vec2.y;

	return ret;
}

//���ς����߂�֐�(3D)
float CMyLibrary::VecDot_3D(VECTOR vec1, VECTOR vec2)
{
	float ret;

	ret = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;

	return ret;
}

//�O�ς����߂�֐�(2D)
float CMyLibrary::VecCross_2D(VECTOR vec1, VECTOR vec2)
{
	float ret;

	ret = vec1.x * vec2.y - vec1.y * vec2.x;

	return ret;
}

//�O�ς����߂�֐�(3D)
VECTOR CMyLibrary::VecCross_3D(VECTOR vec1, VECTOR vec2)
{
	VECTOR ret;

	ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
	ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
	ret.z = vec1.x * vec2.y - vec1.y * vec2.x;

	return ret;
}
