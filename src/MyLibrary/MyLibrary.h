#pragma once

//*�����v�Z���Ԉ���Ă��珑�������Ă�������
//�v�Z�p�N���X
class CMyLibrary
{
public:

	//�x�N�g���̑����Z
	static VECTOR AddVec(VECTOR _vec1, VECTOR _vec2);

	//�x�N�g���̈����Z
	static VECTOR SubVec(VECTOR _vec1, VECTOR _vec2);

	//�x�N�g���𐶐�����֐�
	static VECTOR VecCreate(VECTOR start, VECTOR end);

	//�x�N�g���̒������v�Z����֐�
	static float VecLong(VECTOR vec);

	//�x�N�g���𐳋K������֐�
	static VECTOR vecNormalize(VECTOR vec);

	//�x�N�g�����X�J���[�{����֐�
	static VECTOR Scale(VECTOR vec, float scale);

	//���ς����߂�֐�(2D)
	static float VecDot_2D(VECTOR vec1, VECTOR vec2);

	//���ς����߂�֐�(3D)
	static float VecDot_3D(VECTOR vec1, VECTOR vec2);

	//�O�ς����߂�֐�(2D)
	static float VecCross_2D(VECTOR vec1, VECTOR vec2);

	//�O�ς����߂�֐�(3D)
	static VECTOR VecCross_3D(VECTOR vec1, VECTOR vec2);
};
