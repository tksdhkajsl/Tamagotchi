#pragma once
#include "Tama.h"
class Cookie :  public Tama
{
public:
	void EatSomething(std::string TamaName, TamaState& state) {
		printf("\t\t\t\t\t%s이/가 식당에서 초코 쿠키를 먹습니다. + 에너지 10 + 행복도 20  \n", TamaName.c_str());
		state.Money -= 10;
		state.Energy += 10;
		state.Energy = LimitState(state.Energy);
		state.Happiness += 20;
		state.Happiness = LimitState(state.Happiness);
		Sleep(1200);
	}
};

