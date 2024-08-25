#include <graphics.h>
#include <string>

int idx_current_anim = 0;
int PLAYER_SPEED = 4;

const int PLAYER_ANIM_NUM = 10;

 IMAGE img_player[PLAYER_ANIM_NUM];
 POINT player_pos = { 500,500 };
#pragma comment(lib,"MSIMG32.LIB")
#pragma comment(lib,"Winmm.lib")
 inline void putimage_alpha(int x, int y, IMAGE* img) {
	 int w = img->getwidth();
	 int h = img->getheight();
	 AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		 GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
 }
 void LoadAnimation() {
		for (int i = 0; i < PLAYER_ANIM_NUM; i++) {
			std::wstring path = L"kunkun/player_" + std::to_wstring(i) + L".png";
			loadimage(&img_player[i], path.c_str(), 100, 100);
		}
	}
int main() {
	initgraph(1280, 720);
	mciSendString(_T("open backgroundmusic/menu_music.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(_T("play bgm repeat from 0"), NULL, 0, NULL);
	IMAGE img,img1,img2,img3;
	bool running = true;
	ExMessage msg;
	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;
	LoadAnimation();
	loadimage(&img, _T("kunkun/GameBackground.jpg"),1280,720);
	loadimage(&img1, _T("kunkun/Gamebackground1.png"), 200, 200);
	loadimage(&img2, _T("kunkun/Gamebackground2.png"), 200, 200);
	loadimage(&img3, _T("kunkun/GAMEbackground3.png"), 300, 200);
	BeginBatchDraw();
	while (running) {
		DWORD start_time = GetTickCount();
		while (peekmessage(&msg)) {
			if (msg.message == WM_KEYDOWN) {
				switch (msg.vkcode) {
				case 0x57:
					is_move_up = true;
					break;
				case 0x53:
					is_move_down = true;
					break;
				case 0x41:
					is_move_left = true;
					break;
				case 0x44:
					is_move_right = true;
					break;
				}
			}
			else if (msg.message == WM_KEYUP) {
				switch (msg.vkcode) {
				case 0x57:
					is_move_up = false;
					break;
				case 0x53:
					is_move_down = false;
					break;
				case 0x41:
					is_move_left = false;
					break;
				case 0x44:
					is_move_right = false;
					break;
				}
			}
		}
		if (is_move_up)player_pos.y -= PLAYER_SPEED;
		if (is_move_down)player_pos.y += PLAYER_SPEED;
		if (is_move_left)player_pos.x -= PLAYER_SPEED;
		if (is_move_right)player_pos.x += PLAYER_SPEED;
		static int counter = 0;
		if (++counter % 12 == 0)
			idx_current_anim++;
		idx_current_anim = idx_current_anim % PLAYER_ANIM_NUM;
		cleardevice();
		putimage(0, 0, &img);
		putimage_alpha(50, 50, &img1);
		putimage_alpha(800, 50, &img2);
		putimage_alpha(50, 400, &img3);
		putimage_alpha(player_pos.x,player_pos.y, &img_player[idx_current_anim]);
		FlushBatchDraw();
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / 144) {
			Sleep(1000 / 144 - delta_time);
		}
	}
	EndBatchDraw();
	return 0;
}