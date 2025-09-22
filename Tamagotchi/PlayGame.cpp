#include "PlayGame.h"
#include <stdio.h>
#include "Tama.h"
#include "MiniGame.h"
#include <string>
#include <iostream>

PlayGame::PlayGame()
{

}

int PlayGame::PlayTamagotchi()
{
    printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
    //printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    printf("□□□□□□□□□□□□□■■■□□□□□□□□□□□□□□□■■■□□□□■■■■■■■■■■■□□□□□□■■■□□□□□□■■■□□□\n");
    printf("□□□■■■■■■■■□□■■■□□□□■■■■■■■■■□□■■■□□□□■■■■■■■■■■■□□□□□□■■■□□□□□□■■■□□□\n");
    printf("□□□■■■■■■■■□□■■■□□□□■■■■■■■■■□□■■■□□□□□□□□□□□□■■■□□■■■■■■■■■■■□□■■■□□□\n");
    printf("□□□■■■□□□□□□□■■■□□□□■■■□□□■■■□□■■■□□□□□□□□□□□□■■■□□■■■■■■■■■■■□□■■■□□□\n");
    printf("□□□■■■□□□□□□□■■■■■□□■■■□□□■■■□□■■■■■□□□□□□□□□□■■■□□□□□■■■■■□□□□□■■■□□□\n");
    printf("□□□■■■□□□□□□□■■■■■□□■■■□□□■■■□□■■■■■□□□□□□□□□□■■■□□□□■■■□■■■□□□□■■■□□□\n");
    printf("□□□■■■□□□□□□□■■■■■□□■■■□□□■■■□□■■■■■□□□□□■■■□□■■■□□□■■■□□□■■■□□□■■■□□□\n");
    printf("□□□■■■□□□□□□□■■■□□□□■■■□□□■■■□□■■■□□□□□□□■■■□□■■■□□■■■□□□□□■■■□□■■■□□□\n");
    printf("□□□■■■■■■■■□□■■■□□□□■■■■■■■■■□□■■■□□□□□□□■■■□□□□□□□■■■□□□□□■■■□□■■■□□□\n");
    printf("□□□■■■■■■■■□□■■■□□□□■■■■■■■■■□□■■■□□□□■■■■■■■■■■■□□□□□□□□□□□□□□□■■■□□□\n");
    printf("□□□□□□□□□□□□□■■■□□□□□□□□□□□□□□□■■■□□□□■■■■■■■■■■■□□□□□□□□□□□□□□□■■■□□□\n");
    //printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");

    std::string StartORNo;
    std::string TamaName;
    printf("\n\n\t\t\t\t\t\t\tPlay Tamagotchi Yes or No??  ");
    std::cin >> StartORNo;

    while (!(StartORNo == "No" || StartORNo == "N" || StartORNo == "n" || StartORNo == "NO" || StartORNo == "Yes" || StartORNo == "YES" || StartORNo == "Y" || StartORNo == "y")) {
  
        // 제대로 입력할때까지 - 조건문 수정하기
        printf("\n\n\t\t\t\t\t\t\tCHOOSE ONLY YES OR NO!!!");
        std::cin >> StartORNo;
        
    }
    if (StartORNo == "No" || StartORNo == "N" || StartORNo == "n" || StartORNo == "NO") {
        printf("\n\t\t\t\t\t\t\t\t다마고치를 종료합니다.\n\n");
        return 0;
    }
    else if (StartORNo == "Yes" || StartORNo == "YES" || StartORNo == "Y" || StartORNo == "y") {
        printf("\t\t\t\t\t\t\t   이름을 지어주세요!  ");
        std::cin >> TamaName;
    }

    showStatus(100, 100, 90.0, 100, 20);
    ShowMenu();
}

void PlayGame::ShowMenu()
{
    printf("\t\t\t\t\t\t\t+----------------------+\n");
    printf("\t\t\t\t\t\t\t|      메인 메뉴       |\n");
    printf("\t\t\t\t\t\t\t+----------------------+\n");
    printf("\t\t\t\t\t\t\t|  1.밥먹기            |\n");
    printf("\t\t\t\t\t\t\t|  2.놀아주기          |\n");
    printf("\t\t\t\t\t\t\t|  3.상점              |\n");
    printf("\t\t\t\t\t\t\t|  4.목욕하기          |\n");
    printf("\t\t\t\t\t\t\t|  5.잠자기            |\n");
    //printf("\t\t\t\t\t\t\t|  6.게임종료          |\n");
    printf("\t\t\t\t\t\t\t+----------------------+\n");

}

void PlayGame::showStatus(int Energy, int Happiness, float Exp, int Clean, int Money)
{
    printf("\n\t\t   =================================================================================================\n");
    printf("\t\t\t\t\t\t\t   ★다마고치 상태★\n\t\t\t\t      에너지 : %d\t행복도 : %d\t경험치 : %.1f\t청결도 : %d\t돈 : %d\n", Energy, Happiness, Exp, Clean, Money);
    //printf ( "\t\t\t\t\t\t\t에너지     :     %d\n" , Energy );
    //printf ( "\t\t\t\t\t\t\t행복도     :     %d\n" ,Happiness );
    //printf ( "\t\t\t\t\t\t\t경험치     :     %.1f\n",Exp );
    //printf ( "\t\t\t\t\t\t\t청결도     :     %d\n",Clean);
    //printf("\t\t\t\t\t\t\t========================\n");
    printf("\t\t   =================================================================================================\n\n");
}
