#include "Draw3D.h"

//3D�̃{�b�N�X�\���֐�
//��1�����F���W(���S�łȂ��Ă��悢)
//��2�����F�\���������{�b�N�X�̃T�C�Y
//��3�����F���S���W�łȂ����̃Y��(���łɒ��S�̎��͏����Ȃ��Ă悢)
void CDraw3D::DrawBox3D(VECTOR Pos, VECTOR Size, unsigned int Color)
{
	//�T�C�Y�̔������Ƃ�
	VECTOR HalfSize = VScale(Size, 0.5f);

	/*��̖�*/
	//������E(��O)
	DrawLine3D(VGet(Pos.x - HalfSize.x, Pos.y + HalfSize.y, Pos.z - HalfSize.z), VGet(Pos.x + HalfSize.x, Pos.y + HalfSize.y, Pos.z - HalfSize.z), Color);
	//������E(��)
	DrawLine3D(VGet(Pos.x - HalfSize.x, Pos.y + HalfSize.y, Pos.z + HalfSize.z), VGet(Pos.x + HalfSize.x, Pos.y + HalfSize.y, Pos.z + HalfSize.z), Color);
	//����O���獶��
	DrawLine3D(VGet(Pos.x - HalfSize.x, Pos.y + HalfSize.y, Pos.z - HalfSize.z), VGet(Pos.x - HalfSize.x, Pos.y + HalfSize.y, Pos.z + HalfSize.z), Color);
	//�E��O����E��
	DrawLine3D(VGet(Pos.x + HalfSize.x, Pos.y + HalfSize.y, Pos.z - HalfSize.z), VGet(Pos.x + HalfSize.x, Pos.y + HalfSize.y, Pos.z + HalfSize.z), Color);

	/*���̖�*/
	//������E(��O)
	DrawLine3D(VGet(Pos.x - HalfSize.x, Pos.y - HalfSize.y, Pos.z - HalfSize.z), VGet(Pos.x + HalfSize.x, Pos.y - HalfSize.y, Pos.z - HalfSize.z), Color);
	//������E(��)
	DrawLine3D(VGet(Pos.x - HalfSize.x, Pos.y - HalfSize.y, Pos.z + HalfSize.z), VGet(Pos.x + HalfSize.x, Pos.y - HalfSize.y, Pos.z + HalfSize.z), Color);
	//����O���獶��
	DrawLine3D(VGet(Pos.x - HalfSize.x, Pos.y - HalfSize.y, Pos.z - HalfSize.z), VGet(Pos.x - HalfSize.x, Pos.y - HalfSize.y, Pos.z + HalfSize.z), Color);
	//�E��O����E��
	DrawLine3D(VGet(Pos.x + HalfSize.x, Pos.y - HalfSize.y, Pos.z - HalfSize.z), VGet(Pos.x + HalfSize.x, Pos.y - HalfSize.y, Pos.z + HalfSize.z), Color);

	/*����*/
	//��O��(�ォ�牺)
	DrawLine3D(VGet(Pos.x - HalfSize.x, Pos.y + HalfSize.y, Pos.z - HalfSize.z), VGet(Pos.x - HalfSize.x, Pos.y - HalfSize.y, Pos.z - HalfSize.z), Color);
	//��O�E(�ォ�牺)
	DrawLine3D(VGet(Pos.x + HalfSize.x, Pos.y + HalfSize.y, Pos.z - HalfSize.z), VGet(Pos.x + HalfSize.x, Pos.y - HalfSize.y, Pos.z - HalfSize.z), Color);
	//����(�ォ�牺)
	DrawLine3D(VGet(Pos.x - HalfSize.x, Pos.y + HalfSize.y, Pos.z + HalfSize.z), VGet(Pos.x - HalfSize.x, Pos.y - HalfSize.y, Pos.z + HalfSize.z), Color);
	//���E(�ォ�牺)
	DrawLine3D(VGet(Pos.x + HalfSize.x, Pos.y + HalfSize.y, Pos.z + HalfSize.z), VGet(Pos.x + HalfSize.x, Pos.y - HalfSize.y, Pos.z + HalfSize.z), Color);
}