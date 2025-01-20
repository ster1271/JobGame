#pragma once
#include "../UIBase/BaseUI.h"
#include "../../DrawFont/DrawNumberFont.h"
#include "../../Wave/Wave.h"


class CWaveUI : public CUIBase
{
private:
	int BgHndl;
	int num;
	int ChangeCount;

public:
	//‰Šú‰»
	void Init();

	//“Ç‚İ‚İ
	void Load();

	//–ˆƒtƒŒ[ƒ€s‚¤ˆ—
	void Step();

	//•`‰æ
	void Draw();

	//Œãˆ—
	void Exit();

};

