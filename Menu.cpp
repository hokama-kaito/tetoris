#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

#define PI 3.1415926535897932384626433832795f

static int mImageHandle; //画像ハンドル格納用変数
static int mImageMenu;	//
static int mImageCone;	//

static int MenuNumber = 0;
//初期化
void Menu_Initialize() {
	mImageHandle = LoadGraph("images/Tetris_title.png"); //画像のロー
	//mImageMenu = LoadGraph("images/Tetris_title.jpg");	//
	mImageCone = LoadGraph("images/cone.png");	//
}
//終了処理
void Menu_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
	DeleteGraph(mImageMenu);	//
	//DeleteGraph(mImageCone);	//
}
//更新
void Menu_Update() {
	//
	if (iKeyFlg & PAD_INPUT_DOWN) {
		if (++MenuNumber > 3)MenuNumber = 0;
	}
	if (iKeyFlg & PAD_INPUT_UP) {
		if (--MenuNumber < 0)MenuNumber = 3;
	}

	if (iKeyFlg == PAD_INPUT_1) {	//
		switch (MenuNumber) {		//
		case 0:		//
			SceneMgr_ChangeScene(eScene_Game);	//
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_Help);	//
			break;
		case 2:
			SceneMgr_ChangeScene(eScene_Rank);	//
			break;
		case 3:
			SceneMgr_ChangeScene(eScene_End);	//
			break;
		}
	}
}
//描画
//void Menu_Draw() {
//	DrawGraph(0, 0, mImageHandle, FALSE);
//	DrawString(20, 380, "メニュー画面です。", GetColor(136, 136, 255));
//	DrawString(20, 400, "Gキーを押すとゲーム画面に進みます。", GetColor(136, 136, 255));
//	DrawString(20, 420, "Cキーを押すと 設定画面に進みます。", GetColor(136, 136, 255));
//}
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	SetFontSize(40);
	DrawString(350, 330, "START", GetColor(255, 255, 255));
	DrawString(350, 370, "HELP", GetColor(255, 255, 255));
	DrawString(350, 410, "RANKING", GetColor(255, 255, 255));
	DrawString(350, 450, "END", GetColor(255, 255, 255));
	//
	DrawGraph(120, 245, mImageMenu, TRUE);
	//
	DrawRotaGraph(320, 345 + MenuNumber * 40, 0.7f, PI / 2, mImageCone, TRUE);

	//SetFontSize(20);
	//DrawString(180,450,"-- 右クリックでタイトル --",0xFF0000);
}