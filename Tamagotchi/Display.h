#pragma once
class Display
{
public:
	// 다마고치 시작화면
	void TamaDisplay();

	// 다마고치 알일때 화면
	void ShowTamaEgg();
	
	// 평상시 모습
	void ShowUsual();

	// 밥 먹는 모습
	void ShowEatingTama();
	void EatingTama1();
	void EatingTama2();

	// 참참참 게임 모습
	void ChamChamChamLeft();
	void ChamChamChamRight();

	// 키보드 따라치기 모습
	void TypingTama();

	// 반사신경 테스트 모습
	void ReactionTama();
		
	// 목욕하는 모습
	void BathTama();

	// 잠자는 모습
	void SleepingTama();

	// 더러운 모습
	void DirtyTama();

	//진화과정
	void EvolutionShow();

	// 레벨업표시
	void LevelUp();

	// 게임실패시 (다마고치 죽음)
	void GameOver();
};

