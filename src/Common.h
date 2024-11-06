#pragma once
#include <DxLib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "MyLibrary/MyLibrary.h"
#include "Input/Input.h"
#include "Draw3D/Draw3D.h"

#define SCREEN_SIZE_X 1280	//画面サイズ 横
#define SCREEN_SIZE_Y 720	//画面サイズ 縦

#define MAP_SIZE		50	//マップのサイズ
#define MAP_MAX_NUM		10	//マップの縦横

const unsigned int DEFAULT_COLOR = (255, 0, 0);		//デフォルトの色

const VECTOR VECTOR_ZERO = VGet(0.0f, 0.0f, 0.0f);	//VECTORの初期化に使う

const bool IS_DEBUG = true;							//デバックフラグ

using namespace std;
