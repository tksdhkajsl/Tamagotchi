#include "Tama.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "PlayGame.h"
#include <windows.h>
#include "Display.h"

#include "RiceBall.h"
#include "Tteokbokki.h"
#include "Jelly.h"
#include "Cookie.h"

Display display;
TamaState state;

RiceBall riceball;
Tteokbokki tteokbokki;
Jelly jelly;
Cookie cookie;
// 다마고치의 상태 지수, 먹거나 구매하거나 자거나 목욕하는 행동

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

void Tama::EatSomething(std::string TamaName, TamaState& state)
{
	printf("\n\t\t\t\t\t\t%s이/가 밥을 먹습니다 냠냠. + 에너지 5 \n", TamaName.c_str());
	state.Energy += 5;
	state.Energy = LimitState(state.Energy);
	Sleep(1200);
}

void Tama::Eating(std::string TamaName, TamaState& state)
{
	EatSomething(TamaName, state);
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
	std::string InputRestMenu; 

	// 한 글자 이상이나 문자 입력하면 무한 루프 걸려서 조건문 수정
	//while (WhichFood != 5) {
	
	while(true){
		printf("\t\t\t\t\t어떤 음식을 구매하시겠어요? (소지금 : %d) ", state.Money);
		std::cin >> InputRestMenu;

	if (InputRestMenu.length() == 1) {  // 한 글자만 입력되도록
		WhichFood = InputRestMenu[0] - '0'; // -'0' 하면 정수로 변환된다
		if (WhichFood >= 1 && WhichFood <= 5) {
			switch (WhichFood) {
			case 1:
			{
				if (state.Money >= 20) {
					riceball.EatSomething(TamaName, state);
				}
				else {
					printf("\t\t\t\t\t금액이 부족합니다.\n");
				}
			}
			break;
			case 2:
			{
				if (state.Money >= 50) {
					tteokbokki.EatSomething(TamaName, state);
				}
				else {
					printf("\t\t\t\t\t금액이 부족합니다.\n");
				}
			}
			break;
			case 3:
			{
				if (state.Money >= 5) {
					jelly.EatSomething(TamaName, state);
				}
				else {
					printf("\t\t\t\t\t금액이 부족합니다.\n");
				}
			}
			break;
			case 4:
			{
				if (state.Money >= 10) {
					cookie.EatSomething(TamaName, state);
				}
				else {
					printf("\t\t\t\t\t금액이 부족합니다.\n");
				}
			}
			break;
			case 5:
			{
				printf("\t\t\t\t\t%s이/가 식당을 나갑니다..   \n", TamaName.c_str()); 
				Sleep(1000);
				return;
			}
			break;
			default:
				printf("\t\t\t\t\t식당에서 무언가 잘못되었어요.. \n");
				break;

			}
			Sleep(1000);
		}
		else {
			printf("\t\t\t\t\t그런 음식은 없어요! \n");
		}
	}
	else {
		printf("\t\t\t\t\t그런 음식은 없어요! \n");
	}
	}
}

void Tama::TakeBath(std::string TamaName, int& Clean)
{
	printf("\n\t\t\t\t\t%s이/가 목욕합니다. + 청결도 50 \n", TamaName.c_str());
	Clean += 50;
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
	
	printf("\n\t\t\t\t\t%s이/가 잠을 잡니다. + 에너지 20 \n", TamaName.c_str());
	printf("\t\t\t\t\t다음날이 되었습니다.\n");
	
	state.Energy += 20;
	state.Energy = LimitState(state.Energy);
	state.Day++;
	state.GameLimit = 4;	// 하루에 할 수 있는 게임 횟수 초기화하기
	
	if (state.Clean < 80 && state.Clean >= 50) {
		state.Happiness -= 20;
		state.Happiness = LimitState(state.Happiness);
	}
	else if (state.Clean < 50) {
		state.Happiness -= 40;
		state.Happiness = LimitState(state.Happiness);
	}

	Sleep(1200);
}

