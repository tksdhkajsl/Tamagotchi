#pragma once
#include <string>
struct TamaState
{
	int Energy = 50;
	int Happiness = 50;
	float Exp = 50.0f;
	int Clean = 50;
	int Money = 20;
	int Level = 1;

	TamaState() = default;
};

class Tama
{
public:
	Tama()=default;
	~Tama();


	//밥 먹기
	void Eating(std::string TamaName);

	// 식당
	void Restaurant(std::string TamaName);

	// 목욕하기
	void TakeBath(std::string TamaName);

	// 잠자기
	void Sleeping(std::string TamaName);
private:
};