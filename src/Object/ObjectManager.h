#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Object.h"
#include "Sky/Sky.h"
#include "Ground/Ground.h"
#include "Route_Point/Route_Point.h"

using namespace std;

//オブジェクトマネージャークラス
class CObjectManager
{
private:
	CSky cSky;			//天球クラス
	CGround cGround;	//マップクラス

	int Point_Hndl;
	Check_Point Check_Point[5];
	//CObject型のRoute_Point格納配列
	//vector<CObject*> Point_List;


public:
	//コンストラクタ・デストラクタ
	CObjectManager();
	~CObjectManager();

	//初期化
	void Init();

	//読み込み関連
	void Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//更新処理
	void Update();

	//後処理
	void Exit();

	//設置処理
	void Set_Point(const VECTOR& vPos);
};
