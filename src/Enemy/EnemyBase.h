#pragma once
#include "../Common.h"
#include "../Bot/Bot.h"
#include "../RouteSearch/RouteSearch.h"
#include "../SoundManager/SoundManager.h"
#include "../Debug/DebugString.h"

const float ENEMY_RADIUS(10.0f);		//���f���̔��a


//�G����
enum ENEMY_DIR
{
	ENEMY_DIR_RIGHT = 0,	//�E
	ENEMY_DIR_LEFT,		//��
	ENEMY_DIR_UP,			//��
	ENEMY_DIR_DOWN,		//��
	ENEMY_DIR_BACK,		//��
	ENEMY_DIR_NEAR,		//��O

	ENEMY_DIR_NUM,		//���ԍ�
};


class CEnemyBase
{
protected:
	enum ENEMY_STATE
	{
		STATE_SEARCH = 0,	//�o�H�T��
		STATE_MOVE,			//�ړ�
		STATE_ATTACK,		//�U��

		STATE_NUM,
	};

	ENEMY_STATE State_Id;

	VECTOR cPos;		//���W
	VECTOR cNextPos;	//1�t���[����̍��W
	VECTOR cScale;		//�T�C�Y(�{��)
	VECTOR cSize;		//�T�C�Y(�c���A�����A���s)
	VECTOR cRotate;		//��]�l
	VECTOR cSpeed;		//�ړ����x
	float Radius;		//���a
	int iHndl;			//�n���h��

	float Life;			//���C�t
	int HitCount;		//�e�̓���������
	bool IsActive;		//�����t���O

	bool IsDir[ENEMY_DIR_NUM];	//�����t���O

	vector<VECTOR>List;	//���W�i�[�p
	int ListCnt;

public:
	VECTOR GetPosition() { return cPos; }						//���W�擾
	VECTOR GetNextPosision() { return cNextPos; }				//���W�擾
	void SetNextPosision(VECTOR NewPos) { cNextPos = NewPos; }	//���W�ݒ�
	bool GetDir(int dir) { return IsDir[dir]; }					//�����t���O�擾

	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemyBase();
	~CEnemyBase();

	//������
	void Init();

	//�f�[�^���[�h
	void Load(int iMdlHndl);

	//�I������
	void Exit();

	//���t���[���Ăԏ���
	virtual void Step();

	//�X�V����
	void Update();

	//�`�揈��
	void Draw();

	//���N�G�X�g
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);

	bool GetActive() { return IsActive; }						//��������

	float GetRadius() {	return ENEMY_RADIUS;}					//���f���̔��a�擾

	//�����蔻��̏���
	void HitCalc()
	{
		Life--;
		HitCount++;

		//���C�t���Ȃ��Ȃ�����t���O������
		if (Life <= 0)
		{
			//�ЂƂ܂�������
			/*memset(&cPos, 0, sizeof(VECTOR));
			memset(&cNextPos, 0, sizeof(VECTOR));
			memset(&cRotate, 0, sizeof(VECTOR));
			memset(&cScale, 0, sizeof(VECTOR));
			memset(&cSize, 0, sizeof(VECTOR));
			memset(&cSpeed, 0, sizeof(VECTOR));*/
			iHndl = -1;

			HitCount = 0;
			State_Id = STATE_NUM;
			List.clear();
			IsActive = false;
		}
	}

	//�o�H�ړ�����
	void Enemy_Move(vector<VECTOR> List, int& Cnt);

	//�����ǔ�����
	void Out_Move(VECTOR vPos);

	//�����t���O�ݒ�
	void SetDir();


};