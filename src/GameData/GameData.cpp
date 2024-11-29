#include "GameData.h"

CGameData* CGameData::cInstance = nullptr;

//�R���X�g���N�^
CGameData::CGameData()
{
	MaxScore = 0;		//�ő�X�R�A
	CurrentScore = 0;	//���݃X�R�A

	//�v���C���[�f�[�^������
	memset(&cPlayerData, 0, sizeof(PlayerData));
	//�K�w�f�[�^������
	memset(&cFloarData, 0, sizeof(FloarData));


}

//�f�X�g���N�^
CGameData::~CGameData(){}


//CGameData���擾
CGameData* CGameData::GetInstance()
{
	//�܂���������Ă��Ȃ��Ȃ�
	if (cInstance == nullptr)
	{
		cInstance = new CGameData();
	}

	return cInstance;
}

//CGameData���폜
void CGameData::DeleteInstance()
{
	//�C���X�^���X��NULL�łȂ��Ȃ�
	if (cInstance != nullptr)
	{
		delete cInstance;
		cInstance = nullptr;	//�폜����nullptr���
	}
}
