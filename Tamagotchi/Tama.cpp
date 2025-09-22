#include "Tama.h"
#include <stdio.h>
#include <string>
#include <iostream>

TamaState state;

// 다마고치의 먹거나 구매하거나 자거나 목욕하는 행동

Tama::Tama()
{
}

void Tama::Eating(std::string TamaName)
{
	printf("%s이/가 밥을 먹습니다. + 에너지 5 \n", TamaName.c_str());
	state.Energy += 5;
}

void Tama::Restaurant(std::string TamaName) // 수정필요
{
	
	printf("\t\t\t\t\t\t\t+---------------------------------------------------------------+\n");
	printf("\t\t\t\t\t\t\t|    물건  목록      |   가격  |              효과              |\n");
	printf("\t\t\t\t\t\t\t+---------------------------------------------------------------+\n");
	printf("\t\t\t\t\t\t\t|   1. 주먹밥        |   20$   |   에너지 + 20                  |\n");
	printf("\t\t\t\t\t\t\t|   2. 떡볶이        |   50$   |   에너지 + 50	행복도 + 20   |\n");
	printf("\t\t\t\t\t\t\t|   3. 딸기맛 젤리   |    5$   |	     			행복도 + 10   |\n");
	printf("\t\t\t\t\t\t\t|   4. 초코 쿠키     |   10$   |   에너지 + 10	행복도 + 20   |\n");
	printf("\t\t\t\t\t\t\t+---------------------------------------------------------------+\n");
	printf("구매할 물건을 고르세요 \n");


	printf("%s이/가 식당에서 %s를 먹습니다. + 에너지 20  \n", TamaName.c_str(), TamaName.c_str());
	state.Energy += 20;		
	state.Happiness += 20;
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
