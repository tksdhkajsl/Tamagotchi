#pragma once
#include "Tama.h"

class MiniGame
{	// 놀아주기
public:
	// 미니게임 선택창 보여주기
	void ShowMiniGame(std::string TamaName);

	// 1. 참참참
	//int playChamChamCham(TamaState& state);
	int playChamChamCham();

	// 2. 키보드 따라치기
	int playTypingChallenge();
	
	// 3. 반사신경 테스트
	int playReactionTest();
};

