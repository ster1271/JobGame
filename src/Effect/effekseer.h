#pragma once
#include <DxLib.h>
#include <Effekseer.h>
#include <EffekseerRendererDX9.h>
#include <EffekseerRendererDX11.h>
#include <vector>


class CEffekseer;


//		�G�t�F�N�g�Ǘ��N���X
//		�������g����
class CEffekseerCtrl {
protected:
	static CEffekseer*							m_eff;			// �G�t�F�N�g�P�i�Ǘ��N���X
	static std::vector<::Effekseer::EffectRef>	m_effect;		// �G�t�F�N�g�N���X
	static ::Effekseer::ManagerRef				m_manager;		// �G�t�F�N�g�}�l�[�W��
	static ::EffekseerRendererDX9::RendererRef	m_renderer9;	// �����_���[(DirectX9�p)
	static ::EffekseerRendererDX11::RendererRef	m_renderer11;	// �����_���[(DirectX11�p)
	static int									m_allNum;		// �g�p�G�t�F�N�g����
	static int									m_useID;		// ���Ɏg�p�\���ID
	static int									m_dxVersion;	// DirectX�̃o�[�W����
public:
	//	�R���X�g���N�^�E�f�X�g���N�^
	CEffekseerCtrl();
	~CEffekseerCtrl();

	//	������
	//	effNum		:	�G�t�F�N�g����
	//	particleNum	:	�p�[�e�B�N������
	static void Init(int effNum, int particleNum);
	//	�I������
	static void Exit(void);

	//	�G�t�F�N�g�f�[�^���[�h
	//	name	:	�G�t�F�N�g��(�f�[�^���E�p�X�܂ߓ��{��A�S�p�����͖��Ή�)
	//	@return	:	����=�G�t�F�N�gID,���s=-1
	static int	LoadData(const char* name);
	//	���e�s��ݒ�
	//	pers		:	�J�����̃p�[�X
	//	aspect		:	�A�X�y�N�g��
	//	nearLength	:	�J�����̃j�A�[
	//	farLength	:	�J�����̃t�@�[
	//	@memo		:	�ݒ肪�ς�邽�тɌĂ�ł�������
	static void SetProjectionMtx(float pers, float aspect, float nearLength, float farLength);
	//	���e�s�񎩓��ݒ�
	//	@memo	:	DxLib�̊֐��Ŏ����ݒ�(�Ȃ�ׂ��g��Ȃ�)
	//				��ʕ����Ȃǂɂ͑Ή��s��
	static void SetAutoProjectionMtx(void);
	//	�J�����s��ݒ�
	//	eyePos		:	�J�����̎��_	
	//	focusPos	:	�J�����̒����_
	//	up			:	�J�����̏����
	//	@memo		:	�ݒ肪�ς�邽�тɌĂ�ł�������
	static void SetCameraMtx(VECTOR eyePos, VECTOR focusPos, VECTOR up);
	//	�J�����s�񎩓��ݒ�
	//	@memo	:	DxLib�̊֐��Ŏ����ݒ�(�Ȃ�ׂ��g��Ȃ�)
	static void SetAutoCameraMtx();
	//	�J�����s��ݒ�
	//	eyePos		:	�J�����̎��_	
	//	rot			:	�J�����̊p�x
	//	up			:	�J�����̏����
	//	@memo		:	�ݒ肪�ς�邽�тɌĂ�ł�������
	static void SetCameraRotMtx(VECTOR eyePos, VECTOR rot, VECTOR up);
	//	�X�V����
	static void Update(void);
	//	�X�V����
	//	@memo	: �J�����ݒ������(�Ȃ�ׂ��g��Ȃ�)
	//			  ProjectionMtx,CameraMtx�̐ݒ���s�v
	static void UpdateAutoCamera(void);
	//	�`�揈��
	static void Draw(void);


	//	�G�t�F�N�g�Ăяo��
	//	ID		:	�G�t�F�N�gID
	//	pos		:	�����ʒu
	//	isLoop	:	�G�t�F�N�g�����[�v���邩
	static int Request(int ID, VECTOR pos, bool isLoop);
	//	�w��G�t�F�N�g��~
	static void Stop(int hndl);
	//	�S�G�t�F�N�g��~
	static void StopAll(void);

	//	���W�ύX
	static void SetPosition(int hndl, VECTOR pos);
	//	�g��k�����ύX
	static void SetScale(int hndl, VECTOR scale);
	//	��]�p�x�ύX
	static void SetRot(int hndl, VECTOR rot);
	//	�G�t�F�N�g�A�N�e�B�u����
	static bool IsActive(int hndl);

private:
	//	�f�o�C�X���X�g���̃R�[���o�b�N�֐�
	static void DeviceLostFunction(void* data);
	//	�f�o�C�X���A���̃R�[���o�b�N�֐�
	static void DeviceRestoreFunction(void* data);
};



//		�G�t�F�N�g�P�i�Ǘ��N���X
//		������͊�{�g��Ȃ�
class CEffekseer {
protected:
	VECTOR				m_pos;			// �G�t�F�N�g�̍Đ��ʒu
	VECTOR				m_scale;		// �G�t�F�N�g�̔{��
	VECTOR				m_rot;			// �G�t�F�N�g�̉�]
	int					m_hndl;			// �G�t�F�N�g�n���h��
	int					m_ID;			// �Đ����̃G�t�F�N�gID
	bool				m_isLoop;		// ���[�v�t���O

public:
	//	�R���X�g���N�^�E�f�X�g���N�^
	CEffekseer();
	~CEffekseer();

	void Reset(void);

	//	���W�ݒ�
	inline void	SetTrans(VECTOR pos) { m_pos = pos; }
	//	���W�擾
	inline VECTOR	GetTrans(void) { return m_pos; }
	//	�g��k�����ݒ�
	inline void	SetScale(VECTOR scale) { m_scale = scale; }
	//	�g��k�����擾
	inline VECTOR	GetScale(void) { return m_scale; }
	//	�p�x�ݒ�
	inline void	SetRot(VECTOR rot) { m_rot = rot; }
	//	�p�x�擾
	inline VECTOR	GetRot(void) { return m_rot; }
	//	�G�t�F�N�g�n���h���ݒ�
	inline void	SetHndl(int hndl) { m_hndl = hndl; }
	//	�G�t�F�N�g�n���h���擾
	inline int	GetHndl(void) { return m_hndl; }
	//	�G�t�F�N�gID�ݒ�
	inline void	SetID(int ID) { m_ID = ID; }
	//	�G�t�F�N�gID�擾
	inline int	GetID(void) { return m_ID; }
	//	���[�v���ݒ�
	inline void	SetLoop(bool isLoop) { m_isLoop = isLoop; }
	//	���[�v���擾
	inline bool	IsLoop(void) { return m_isLoop; }
};