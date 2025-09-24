#pragma once
#include "Tama.h"
#include "Display.h"



class PlayGame
{
public:
	PlayGame();
	// 처음 시작시 다마고치 로고 출력, 게임 시작할지말지
	int PlayTamagotchi();
	// 메뉴 보여주기
	void ShowMenu(TamaState& state);

	// 다마고치 상태표 보여주기
	void showStatus(TamaState& state);

	void Evolution();
private:
	
	

	Tama tama;
	Display display;
	TamaState state;

};

