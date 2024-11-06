#pragma once
#include <DxLib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "MyLibrary/MyLibrary.h"
#include "Input/Input.h"
#include "Draw3D/Draw3D.h"

#define SCREEN_SIZE_X 1280	//��ʃT�C�Y ��
#define SCREEN_SIZE_Y 720	//��ʃT�C�Y �c

#define MAP_SIZE		50	//�}�b�v�̃T�C�Y
#define MAP_MAX_NUM		10	//�}�b�v�̏c��

const unsigned int DEFAULT_COLOR = (255, 0, 0);		//�f�t�H���g�̐F

const VECTOR VECTOR_ZERO = VGet(0.0f, 0.0f, 0.0f);	//VECTOR�̏������Ɏg��

const bool IS_DEBUG = true;							//�f�o�b�N�t���O

using namespace std;
