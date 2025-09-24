// Tamagotchi.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <stdio.h>
#include "Tama.h"
#include "PlayGame.h"

int main()
{
    system("mode con cols=140 lines=50"); // 콘솔 창 크기 조절
    
    PlayGame playGame;
    playGame.PlayTamagotchi();
    //playGame.Evolution();

}