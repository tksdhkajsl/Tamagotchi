#pragma once
#include <string>
struct TamaState
{
	int Energy = 50;
	int Happiness = 50;
	float Exp = 50.0f;
	int Clean = 50;
	int Money = 20;

	TamaState() = default;
};

class Tama
{
public:
	Tama();


	// ¹ä¸Ô±â
	void Eating(std::string TamaName);

	// »óÁ¡
	void Restaurant(std::string TamaName);

	// ¸ñ¿å
	void TakeBath(std::string TamaName);

	// ÀáÀÚ±â
	void Sleeping(std::string TamaName);
private:
};

