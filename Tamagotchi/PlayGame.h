#pragma once
class PlayGame
{
public:
	PlayGame();
	// 처음 시작시 다마고치 로고 출력, 게임 시작할지말지
	int PlayTamagotchi();

private:
	// 메뉴 보여주기
	void ShowMenu();

	// 다마고치 상태표 보여주기
	void showStatus(int Energy, int Happiness, float Exp, int Clean, int Money);
};

