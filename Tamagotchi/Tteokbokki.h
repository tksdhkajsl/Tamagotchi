#pragma once
#include "Tama.h"
class Tteokbokki : public Tama
{
public:
	void EatSomething(std::string TamaName, TamaState& state) {
		printf("\t\t\t\t\t%s이/가 식당에서 떡볶이를 먹습니다. + 에너지 50 + 행복도 30  \n", TamaName.c_str());
		state.Money -= 50;
		state.Energy += 50;
		state.Energy = LimitState(state.Energy);
		state.Happiness += 30;
		state.Happiness = LimitState(state.Happiness);
		Sleep(1200);
	}
};

