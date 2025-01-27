#pragma once
#include "../Common.h"
#include "../Mouse/Mouse.h"

enum tagTITLE_SCENE
{
	TITLE_SCENE_INIT,
	TITLE_SCENE_LAOD,
	TITLE_SCENE_LOOP,
	TITLE_SCENE_END,

	TITLE_SCENE_NUM
};

class CTitleScene
{
private:
	tagTITLE_SCENE eSceneID;

	struct Info
	{
		int Hndl;			//�n���h��
		VECTOR cPos;		//���W
		VECTOR cRotate;		//��]�l
		VECTOR cSize;		//�g�嗦
	};

	Info TitleInfo;
	Info CharaInfo;
	Info Enemy1Info;
	Info Enemy2Info;
	Info StartInfo;
	Info EndInfo;

	int MouseX, MouseY;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CTitleScene();
	~CTitleScene();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//���[�v����
	int Loop();

	//���g�̏���
	void Step();

	//���X�V
	void AllUpdata();

	//���X�V
	void Updata(Info info);

	//�`�揈��
	void Draw();

	//�㏈��
	void Exit();

	//�}�E�X�͈͓�����
	bool Within_Range(VECTOR vPos);
};
