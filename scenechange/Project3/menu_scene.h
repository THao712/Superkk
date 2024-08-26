#pragma once
#include "scene.h"
#include "scene_manager.h"
#include <iostream>

extern SceneManager scene_manager;

class MenuScene : public Scene
{
public :
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		std::cout << "�������˵�" << std::endl;
	}
    void on_update()
	{
		std::cout << "���˵���������..." << std::endl;
	}
	void on_draw() 
	{
		outtextxy(10, 10, _T("���˵���ͼ����"));
	}
	void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}
	void on_exit() 
	{
		std::cout << "���˵��˳�" << std::endl;
	}
private : 

};