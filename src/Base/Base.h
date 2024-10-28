#pragma once
#include "../Common.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"
#include "../Object/ObjectManager.h"

//�q���[�}���x�[�X�N���X
class CBase
{
protected:
	//�A�j���Đ����
	enum ANIME_STATE
	{
		ANIMESTATE_NORMAL = 0,
		ANIMESTATE_LOOP,
		ANIMESTATE_END,
	};

	

	//�A�j���֘A�̃f�[�^���܂Ƃ߂��\����
	struct ANIME_DATA
	{
		float m_EndFrame;
		float m_Frame;
		float m_Speed;
		int m_iHndl;
		int m_AnimID;
		int m_State;
	};

	VECTOR cPos;			//���W
	VECTOR cSize;			//�T�C�Y
	VECTOR cRotate;			//��]�l
	ANIME_DATA AnimData;	//�A�j���Đ��f�[�^

	float Life;			//���C�t
	int iHndl;			//�n���h��

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBase();
	~CBase();

	//������
	void Init();

	//�ǂݍ��݊֘A
	bool Load(const char FILEPATH[]);

	//�`��
	void Draw();

	//���t���[���s������
	virtual void Step(CShotManager& cShotManager, CTurretManager& cTurretManager) = 0;

	//�X�V����
	void Update();

	//�㏈��
	void Exit();

	//�A�j���A�b�v�f�[�g
	void UpdateAnim();

	//���N�G�X�g
	void Reqest(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����ŏ��ɖ߂�)
	void ReqestLoop(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//�G���h���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����~�܂�)
	void ReqestEndLoop(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//�A�j�����f�^�b�`
	void DetachAnim();

	//���W�擾
	VECTOR GetPos() { return cPos; }

	//�T�C�Y�擾
	VECTOR GetSize() { return cSize; }

	//��]�n�擾
	VECTOR GetRotate() { return cRotate; }

};
