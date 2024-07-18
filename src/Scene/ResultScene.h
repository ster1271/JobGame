#pragma once


class CResultScene
{
private:
	enum tagRESULT_SCENE
	{
		RESULT_SCENE_INIT,
		RESULT_SCENE_LAOD,
		RESULT_SCENE_LOOP,
		RESULT_SCENE_END,

		RESULT_SCENE_NUM
	};

	tagRESULT_SCENE eSceneID;


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CResultScene();
	~CResultScene();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//���[�v����
	int Loop();

	//���g�̏���
	void Step();

	//�`�揈��
	void Draw();

	//�㏈��
	void Exit();

};

