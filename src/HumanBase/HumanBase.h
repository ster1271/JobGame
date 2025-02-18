#pragma once
#include "../Common.h"
#include "../Animation/Animation.h"

//�v���C���[����
enum PLAYER_DIR
{
	DIR_RIGHT = 0,	//�E
	DIR_LEFT,		//��
	DIR_UP,			//��
	DIR_DOWN,		//��
	DIR_BACK,		//��
	DIR_NEAR,		//��O

	DIR_NUM,		//���ԍ�
};

class CHumanBase
{
protected:
	VECTOR cPos;				//���W
	VECTOR cNextPos;			//1�t���[����̍��W
	VECTOR cRotate;				//�L�����N�^�[�̌����̉�]��
	VECTOR cMoveRotate;			//�L�����N�^�[�̕����w��̉�]��
	VECTOR cSpeed;				//�L�����N�^�[���x
	VECTOR cScale;				//�T�C�Y
	VECTOR cSize;				//���f���̕�

	int MouseX, MouseY;			//�}�E�X���W

	bool IsActive;				//�����t���O
	int iHndl;					//�n���h��
	float Life;					//���C�t
	int PushCnt;				//�{�^�������Ă��鎞��
	int ReturnCnt;				//�{�b�g�ɖ߂邽�߂̎���
	float StoreRot;			//�p�x�ۑ�

	bool IsDir[DIR_NUM];	//�����t���O


public:

	VECTOR GetPos() { return cPos; }						//���W�擾
	VECTOR GetNextPos() { return cNextPos; }				//���W�擾
	void SetNextPos(VECTOR NewPos) { cNextPos = NewPos; }	//���W�ݒ�
	VECTOR GetRotate() { return cRotate; }					//��]�l�擾
	VECTOR GetSpeed() { return cSpeed; }					//���x�擾
	VECTOR GetSize() { return cSize; }						//�T�C�Y�擾
	float GetPlayerLife() { return Life; }					//���C�t�擾
	bool GetIsActive() { return IsActive; }					//�t���O�擾
	bool GetDir(int dir) { return IsDir[dir]; }				//�����t���O�擾


	//�R���X�g���N�^�E�f�X�g���N�^
	CHumanBase();
	~CHumanBase();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load(const char FILEPATH[]);

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//���X�V
	void UpData();

	//�㏈��
	void Exit();

	//�L�����N�^�[��]����
	void Player_Rotation();

	//�����t���O�ݒ�
	void SetDir();											


};
