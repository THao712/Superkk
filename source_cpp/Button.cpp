#include "global_variable.h"
#include <graphics.h>
#include "Button.h"

	Button::Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed) {
		region = rect;
		loadimage(&img_idle, path_img_idle);
		loadimage(&img_hovered, path_img_hovered);
		loadimage(&img_pushed, path_img_pushed);
	}
	void Button::ProcessEvent(const ExMessage& msg) {
		switch (msg.message) {
		case WM_MOUSEMOVE:
			if (status == Status::Idle && CheckCursorHit(msg.x, msg.y))
				status = Status::Hovered;
			else if (status == Status::Hovered && !CheckCursorHit(msg.x, msg.y))
				status == Status::Idle;
			break;
		case WM_LBUTTONDOWN:
			if (CheckCursorHit(msg.x, msg.y))
				status = Status::Pushed;
			break;
		case WM_LBUTTONUP:
			if (status == Status::Pushed)
				OnClick();
			break;
		default:
			break;
		}
	}
	void Button::Draw() {
		switch (status) {
		case Status::Idle:
			putimage(region.left, region.top, &img_idle);
			break;
		case Status::Hovered:
			putimage(region.left, region.top, &img_hovered);
			break;
		case Status::Pushed:
			putimage(region.left, region.top, &img_pushed);
			break;
		}
	}
	bool Button::CheckCursorHit(int x, int y) {
		return x >= region.left && x <= region.right && y > -region.top && y <= region.bottom;
	}
//开始游戏按钮

	StartGameButton::StartGameButton(RECT rect,LPCTSTR path_img_idle,LPCTSTR path_img_hovered,LPCTSTR path_img_pushed)
	:Button(rect, path_img_idle, path_img_hovered, path_img_pushed){}

	void StartGameButton :: OnClick() {
		is_game_started = true;
	}

//退出游戏按钮

	QuitGameButton::QuitGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}
	void QuitGameButton::OnClick() {
		running = false;
	}