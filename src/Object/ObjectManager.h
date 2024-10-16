#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Object.h"
#include "Sky/Sky.h"
#include "Ground/Ground.h"

using namespace std;

//�I�u�W�F�N�g�}�l�[�W���[�N���X
class CObjectManager
{
private:
	CSky cSky;			//�V���N���X
	CGround cGround;	//�}�b�v�N���X


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CObjectManager();
	~CObjectManager();

	//������
	void Init();

	//�ǂݍ��݊֘A
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//�X�V����
	void Update();

	//�㏈��
	void Exit();

	//�n���h���擾
	int GetHndl() { return cGround.GetHndl(); }

};
