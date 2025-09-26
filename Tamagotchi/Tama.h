#pragma once
#include <string>
struct TamaState
{
	std::string TamaName;	// 다마고치 이름
	int Energy = 50;		// 에너지
	int Happiness = 50;		// 행복도
	float Exp = 0.0f;		// 경험치
	int Clean = 50;			// 청결도
	int Money = 20;			// 소지금
	int Level = 1;			// 레벨
	int BadCount = 0;		// 에너지가 20 이하인데 재우기를 한 경우 카운트 , 3이 되면 게임 종료이다
	int Day = 1;			// 날짜 출력, 재우기 하면 + 1이 된다.
	int GameLimit = 4;		// 게임은 하루에 최대 4번만 할 수 있다.

	TamaState() = default;
};

class Tama
{
public:
	Tama()=default;
	~Tama();

	//밥 먹기
	void Eating(std::string TamaName, int& Energy);

	// 식당
	void Restaurant(std::string TamaName, TamaState& state);

	// 목욕하기
	void TakeBath(std::string TamaName, int& Clean);

	// 잠자기
	void Sleeping(std::string TamaName, TamaState& state);

	// 에너지, 행복도, 청결도 0~100으로 제한하기
	int LimitState(int StateIndex);

protected:

};