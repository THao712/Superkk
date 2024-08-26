#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include<graphics.h>
#include "global_variable.h"
class Button {
public:
	Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
	~Button() = default;
	void ProcessEvent(const ExMessage& msg);
	void Draw();
protected:
	virtual void OnClick() = 0;
private:enum class Status {
		Idle = 0,
		Hovered,
		Pushed
	};
private:
	RECT region;
	IMAGE img_idle;
	IMAGE img_hovered;
	IMAGE img_pushed;
	Status status = Status::Idle;
private:
	bool CheckCursorHit(int x, int y);
};
class StartGameButton :public Button {
public:
	StartGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
	~StartGameButton()=default;
protected:
	void OnClick();
};
class QuitGameButton :public Button {
public:
	QuitGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
	~QuitGameButton() = default;
protected:
	void OnClick();
};
#endif