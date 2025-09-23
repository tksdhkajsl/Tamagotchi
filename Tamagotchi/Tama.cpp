#include "Tama.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "PlayGame.h"
#include <windows.h>

TamaState state;
// 다마고치의 상태 지수, 먹거나 구매하거나 자거나 목욕하는 행동

Tama::Tama()
{}

void Tama::Eating(std::string TamaName) // 에너지값 변화가 없음 , 아래 printf 안 출력되고 바로 메뉴창으로 이동
{
	printf("\t\t\t\t\t%s이/가 밥을 먹습니다 냠냠. + 에너지 5 \n", TamaName.c_str());
	state.Energy += 5;
	Sleep(3000);
}

void Tama::Restaurant(std::string TamaName) // 값 변화, 금액 지불 부분
{
	
	printf("\n\n");
	printf("\t\t\t\t\t+---------------------------------------------------------------+\n");
	printf("\t\t\t\t\t|    물건  목록      |   가격  |              효과              |\n");
	printf("\t\t\t\t\t+---------------------------------------------------------------+\n");
	printf("\t\t\t\t\t|   1. 주먹밥        |   20$   |   에너지 + 20                  |\n");
	printf("\t\t\t\t\t|   2. 떡볶이        |   50$   |   에너지 + 50    행복도 + 30   |\n");
	printf("\t\t\t\t\t|   3. 딸기맛 젤리   |    5$   |                  행복도 + 15   |\n");
	printf("\t\t\t\t\t|   4. 초코 쿠키     |   10$   |   에너지 + 10    행복도 + 20   |\n");
	printf("\t\t\t\t\t|   5. 식당 나가기   |         |                                |\n");
	printf("\t\t\t\t\t+---------------------------------------------------------------+\n");
	
	int WhichFood = 0;
	printf("\t\t\t\t\t어떤 음식을 구매하시겠어요? ");
	std::cin >> WhichFood;

	while (!(WhichFood >= 1) &&!( WhichFood <=5)) {
		printf("\t\t\t\t\t그런 음식은 없어요! \n");
		printf("\t\t\t\t\t어떤 음식을 구매하시겠어요? ");
		std::cin >> WhichFood;
	}

	switch (WhichFood) {
	case 1: 
	{
		printf("\t\t\t\t\t%s이/가 식당에서 주먹밥을 먹습니다. + 에너지 20  \n", TamaName.c_str());  // 안 뜯고 처음 메뉴바로 다시 돌아감
		state.Energy += 20;
		state.Happiness += 20;
	}
		break;
	case 2:
	{
		printf("\t\t\t\t\t%s이/가 식당에서 떡볶이를 먹습니다. + 에너지 50 + 행복도 30  \n", TamaName.c_str());
		state.Energy += 50;
		state.Happiness += 30;
	}
		break;
	case 3:
	{
		printf("\t\t\t\t\t%s이/가 식당에서 딸기맛 젤리를 먹습니다. + 행복도 15  \n", TamaName.c_str());
		state.Happiness += 15;
	}
		break;
	case 4:
	{
		printf("\t\t\t\t\t%s이/가 식당에서 초코 쿠키를 먹습니다. + 에너지 10 + 행복도 20  \n", TamaName.c_str());
		state.Energy += 10;
		state.Happiness += 20;
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
	Sleep(3000);
}

void Tama::TakeBath(std::string TamaName)
{
	printf("%s이/가 목욕합니다. + 청결도 50 \n", TamaName.c_str());
	state.Clean += 50;
}

void Tama::Sleeping(std::string TamaName)
{
	printf("%s이/가 잠을 잡니다. + 에너지 20 \n", TamaName.c_str());
	state.Energy += 20;
}
