#pragma once
#include "Tama.h"
#include "Display.h"

class MiniGame
{	// 놀아주기
public:
	MiniGame() = default;
	//~MiniGame();

	// 미니게임 선택창 보여주기
	void ShowMiniGame(TamaState& state);

	// 1. 참참참
	int playChamChamCham(TamaState& state);

	// 2. 키보드 따라치기
	int playTypingChallenge(TamaState& state);
	
	// 3. 반사신경 테스트
	//int playReactionTest(TamaState& state);

	// 4. 보물찾기
	int playTreasureHunt(TamaState& state);
};

