#include "Tama.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "PlayGame.h"
#include <windows.h>

#include "Display.h"

Display display;
TamaState state;
// 다마고치의 상태 지수, 먹거나 구매하거나 자거나 목욕하는 행동


Tama::~Tama()
{
}

int MAXSTATE = 100;
int MINSTATE = 0;

int Tama::LimitState(int StateIndex) {	// 에너지, 행복도, 청결도는 0~100 사이
	if (StateIndex >= MAXSTATE) {
		StateIndex = MAXSTATE;
	}

	if (StateIndex < MINSTATE) {
		StateIndex = MINSTATE;
	}
	return StateIndex;
}


void Tama::Eating(std::string TamaName, int& Energy) // 에너지값 변화가 없음 , 아래 printf 안 출력되고 바로 메뉴창으로 이동
{
	printf("\n\t\t\t\t\t\t%s이/가 밥을 먹습니다 냠냠. + 에너지 5 \n", TamaName.c_str());
	Energy += 5;
	Energy = LimitState(Energy);

	Sleep(1200);
}

void Tama::Restaurant(std::string TamaName, TamaState& state) // 값 변화, 금액 지불 부분
{

	printf("\n\n");
	printf("\t\t\t\t +---------------------------------------------------------------+\n");
	printf("\t\t\t\t |    물건  목록      |   가격  |              효과              |\n");
	printf("\t\t\t\t +---------------------------------------------------------------+\n");
	printf("\t\t\t\t |   1. 주먹밥        |   20$   |   에너지 + 20                  |\n");
	printf("\t\t\t\t |   2. 떡볶이        |   50$   |   에너지 + 50    행복도 + 30   |\n");
	printf("\t\t\t\t |   3. 딸기맛 젤리   |    5$   |                  행복도 + 15   |\n");
	printf("\t\t\t\t |   4. 초코 쿠키     |   10$   |   에너지 + 10    행복도 + 20   |\n");
	printf("\t\t\t\t |   5. 식당 나가기   |         |                                |\n");
	printf("\t\t\t\t +---------------------------------------------------------------+\n");
	
	int WhichFood = 0;
	while (WhichFood != 5) {


	printf("\t\t\t\t\t어떤 음식을 구매하시겠어요? (소지금 : %d) ",state.Money);
	std::cin >> WhichFood;

	while (!(WhichFood >= 1) &&!( WhichFood <=5)) {
		printf("\t\t\t\t\t그런 음식은 없어요! \n");
		printf("\t\t\t\t\t어떤 음식을 구매하시겠어요? (소지금 : %d) ", state.Money);
		std::cin >> WhichFood;
	}

	
	switch (WhichFood) {
	case 1: 
	{
		if (state.Money >= 20) {
		printf("\t\t\t\t\t%s이/가 식당에서 주먹밥을 먹습니다. + 에너지 20  \n", TamaName.c_str()); 
		state.Energy += 20;
		state.Happiness += 20;
		state.Money -= 20;
		state.Energy = LimitState(state.Energy);
		state.Happiness = LimitState(state.Happiness);
		printf("\t\t\t\t\t\t남은 소지금 : %4d\n", state.Money);
		}
		else{
			printf("\t\t\t\t\t\t금액이 부족합니다.\n");
		}
	}
		break;
	case 2:
	{
		if (state.Money >= 50) {
		printf("\t\t\t\t%s이/가 식당에서 떡볶이를 먹습니다. + 에너지 50 + 행복도 30  \n", TamaName.c_str());
		state.Energy += 50;
		state.Happiness += 30;
		state.Money -= 50;
		state.Energy = LimitState(state.Energy);
		state.Happiness = LimitState(state.Happiness);
		printf("\t\t\t\t\t\t남은 소지금 : %4d\n", state.Money);
		}
		else {
			printf("\t\t\t\t\t\t금액이 부족합니다.\n");
		}
	}
		break;
	case 3:
	{
		if (state.Money >= 5) {
		printf("\t\t\t\t\t%s이/가 식당에서 딸기맛 젤리를 먹습니다. + 행복도 15  \n", TamaName.c_str());
		state.Happiness += 15;
		state.Money -= 5;
		state.Happiness = LimitState(state.Happiness);
		printf("\t\t\t\t\t\t남은 소지금 : %4d\n", state.Money);
		}
		else {
			printf("\t\t\t\t\t\t금액이 부족합니다.\n");
		}
	}
		break;
	case 4:
	{
		if (state.Money >= 10) {
		printf("\t\t\t\t%s이/가 식당에서 초코 쿠키를 먹습니다. + 에너지 10 + 행복도 20  \n", TamaName.c_str());
		state.Energy += 10;
		state.Happiness += 20;
		state.Money -= 10;

		state.Energy = LimitState(state.Energy);
		state.Happiness = LimitState(state.Happiness);
		printf("\t\t\t\t\t\t남은 소지금 : %4d\n", state.Money);
		}
		else {
			printf("\t\t\t\t\t\t금액이 부족합니다.\n");
		}
	}
		break;
	case 5:
	{
		printf("\t\t\t\t\t%s이/가 식당을 나갑니다..   \n", TamaName.c_str());
	}
		break;
	default:
		printf("\t\t\t\t\t식당에서 무언가 잘못되었어요.. \n");
		break;
	
	}
	Sleep(1200);
	}
}

void Tama::TakeBath(std::string TamaName, int& Clean)
{
	printf("\n\t\t\t\t\t\t%s이/가 목욕합니다. + 청결도 30 \n", TamaName.c_str());
	Clean += 30;
	state.Clean = LimitState(state.Clean);
	Sleep(1200);
}

void Tama::Sleeping(std::string TamaName, TamaState& state)
{
	if (state.Energy <= 20) {
		state.BadCount++;
	}

	if (state.BadCount == 3) {
		display.GameOver(); // 에너지가 20이하일때 재우기 누적 3번이면 과로사로 게임 종료
	}
	
	printf("\n\t\t\t\t\t\t%s이/가 잠을 잡니다. + 에너지 20 \n", TamaName.c_str());
	printf("\t\t\t\t\t\t다음날이 되었습니다.\n");
	
	state.Energy += 20;
	state.Energy = LimitState(state.Energy);
	state.Day++;
	state.GameLimit = 4;	// 하루에 할 수 있는 게임 횟수 초기화하기
	
	if (state.Clean < 80 && state.Clean >= 50) {
		state.Happiness -= 20;
	}
	else if (state.Clean < 50) {
		state.Happiness -= 40;
	}

	Sleep(1200);
}

