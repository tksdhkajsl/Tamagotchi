#pragma once
#include "Tama.h"
class RiceBall :  public Tama
{
public:
	void EatSomething(std::string TamaName, TamaState& state) {
		printf("\t\t\t\t\t%s이/가 식당에서 주먹밥을 먹습니다. + 에너지 20  \n", TamaName.c_str());
		state.Money -= 20;
		state.Energy += 20;
		state.Energy = LimitState(state.Energy);
		Sleep(1200);
	}
};

