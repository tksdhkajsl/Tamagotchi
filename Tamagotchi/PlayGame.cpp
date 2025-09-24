#include "PlayGame.h"
#include <stdio.h>
#include "Tama.h"
#include "MiniGame.h"
#include "Display.h"
#include <string>
#include <iostream>
#include <windows.h>


// 로고나 메뉴창, 다마고치 상태창을 출력하는 곳

PlayGame::PlayGame()
{

}
std::string TamaName;
int PlayGame::PlayTamagotchi()
{

    TamaState state;

    //printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
    ////printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    //printf("□□□□□□□□□□□□□■■■□□□□□□□□□□□□□□□■■■□□□□■■■■■■■■■■■□□□□□□■■■□□□□□□■■■□□□\n");
    //printf("□□□■■■■■■■■□□■■■□□□□■■■■■■■■■□□■■■□□□□■■■■■■■■■■■□□□□□□■■■□□□□□□■■■□□□\n");
    //printf("□□□■■■■■■■■□□■■■□□□□■■■■■■■■■□□■■■□□□□□□□□□□□□■■■□□■■■■■■■■■■■□□■■■□□□\n");
    //printf("□□□■■■□□□□□□□■■■□□□□■■■□□□■■■□□■■■□□□□□□□□□□□□■■■□□■■■■■■■■■■■□□■■■□□□\n");
    //printf("□□□■■■□□□□□□□■■■■■□□■■■□□□■■■□□■■■■■□□□□□□□□□□■■■□□□□□■■■■■□□□□□■■■□□□\n");
    //printf("□□□■■■□□□□□□□■■■■■□□■■■□□□■■■□□■■■■■□□□□□□□□□□■■■□□□□■■■□■■■□□□□■■■□□□\n");
    //printf("□□□■■■□□□□□□□■■■■■□□■■■□□□■■■□□■■■■■□□□□□■■■□□■■■□□□■■■□□□■■■□□□■■■□□□\n");
    //printf("□□□■■■□□□□□□□■■■□□□□■■■□□□■■■□□■■■□□□□□□□■■■□□■■■□□■■■□□□□□■■■□□■■■□□□\n");
    //printf("□□□■■■■■■■■□□■■■□□□□■■■■■■■■■□□■■■□□□□□□□■■■□□□□□□□■■■□□□□□■■■□□■■■□□□\n");
    //printf("□□□■■■■■■■■□□■■■□□□□■■■■■■■■■□□■■■□□□□■■■■■■■■■■■□□□□□□□□□□□□□□□■■■□□□\n");
    //printf("□□□□□□□□□□□□□■■■□□□□□□□□□□□□□□□■■■□□□□■■■■■■■■■■■□□□□□□□□□□□□□□□■■■□□□\n");
    ////printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    //printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");

    printf("\n\n");
    printf("\t\t\t\t\t   ■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t\t\t\t\t   ■□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
    printf("\t\t\t\t\t   ■□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
    printf("\t\t\t\t\t   ■□□■■■■■□■■□□□■■■■■□■■□□□□■\n");
    printf("\t\t\t\t\t   ■□□■■■■■□■■□□□■■■■■□■■□□□□■\n");
    printf("\t\t\t\t\t   ■□□■■□□□□■■■■□■■□■■□■■■■□□■\n");
    printf("\t\t\t\t\t   ■□□■■□□□□■■■■□■■□■■□■■■■□□■\n");
    printf("\t\t\t\t\t   ■□□■■■■■□■■□□□■■■■■□■■□□□□■\n");
    printf("\t\t\t\t\t   ■□□■■■■■□■■□□□■■■■■□■■□□□□■\n");
    printf("\t\t\t\t\t   ■□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
    printf("\t\t\t\t\t   ■□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
    printf("\t\t\t\t\t   ■□□■■■■■■■□□□□□□■■□□□□■■□□■\n");
    printf("\t\t\t\t\t   ■□□■■■■■■■□□□□□□■■□□□□■■□□■\n");
    printf("\t\t\t\t\t   ■□□□□□□□■■□□■■■■■■■■■□■■□□■\n");
    printf("\t\t\t\t\t   ■□□□□■■□■■□□■■■■■■■■■□■■□□■\n");
    printf("\t\t\t\t\t   ■□□□□■■□■■□□□□■■□■■□□□■■□□■\n");
    printf("\t\t\t\t\t   ■□□□□■■□□□□□□■■□□□■■□□■■□□■\n");
    printf("\t\t\t\t\t   ■□□■■■■■■■□□■■□□□□□■■□■■□□■\n");
    printf("\t\t\t\t\t   ■□□■■■■■■■□□□□□□□□□□□□■■□□■\n");
    printf("\t\t\t\t\t   ■□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
    printf("\t\t\t\t\t   ■□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
    printf("\t\t\t\t\t   ■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");



    std::string StartORNo;
   
    printf("\n\n\t\t\t\t\t\t\tPlay Tamagotchi Yes or No??  ");
    std::cin >> StartORNo;

    while (!(StartORNo == "No" || StartORNo == "N" || StartORNo == "n" || StartORNo == "NO" || StartORNo == "no" || StartORNo == "Yes" || StartORNo == "YES" || StartORNo == "Y" || StartORNo == "y" || StartORNo == "yes")) {
  
        // 제대로 입력할때까지 - 조건문 수정하기
        printf("\n\t\t\t\t\t\t\t\tYES OR NO ? ");
        std::cin >> StartORNo;
        
    }
    if (StartORNo == "No" || StartORNo == "N" || StartORNo == "n" || StartORNo == "NO" || StartORNo == "no") {
        printf("\n\t\t\t\t\t\t\t  다마고치를 종료합니다.\n\n");
        return 0;
    }
    else if (StartORNo == "Yes" || StartORNo == "YES" || StartORNo == "Y" || StartORNo == "y" || StartORNo == "yes") {
        printf("\n\t\t\t\t\t\t\t   이름을 지어주세요!  ");
        std::cin >> TamaName;
    }
    system("cls");
    display.ShowTamaEgg();

    while (state.Level != 5) {
        system("cls");
        showStatus(state);
        ShowMenu(state);
    }
}

void PlayGame::ShowMenu(TamaState& state)
{
        printf("\n\t\t\t\t\t\t\t+----------------------+\n");
        printf("\t\t\t\t\t\t\t|      메인 메뉴       |\n");
        printf("\t\t\t\t\t\t\t+----------------------+\n");
        printf("\t\t\t\t\t\t\t|  1.밥먹기            |\n");
        printf("\t\t\t\t\t\t\t|  2.놀아주기          |\n");
        printf("\t\t\t\t\t\t\t|  3.식당              |\n");
        printf("\t\t\t\t\t\t\t|  4.목욕하기          |\n");
        printf("\t\t\t\t\t\t\t|  5.잠자기            |\n");
        //printf("\t\t\t\t\t\t\t|  6.게임종료          |\n");
        printf("\t\t\t\t\t\t\t+----------------------+\n");

        int ChooseMenu;
        printf("\t\t\t\t\t\t\t무엇을 하시겠어요? ");
        std::cin >> ChooseMenu;

        system("cls"); // 콘솔창 지우고 출력되도록 하기
   
        showStatus(state);

        switch (ChooseMenu)
        {
        case 1:
            display.ShowEatingTama();
            tama.Eating(TamaName);
       
            break;
        case 2:
            break;
        case 3:
            
            tama.Restaurant(TamaName);
            break;
        case 4:
            display.BathTama();
            tama.TakeBath(TamaName);
            break;
        case 5:
            tama.Sleeping(TamaName);
            break; 
        default:
            printf("메뉴 선택 중 에러가 발생했습니다. \n");
            break;
        }
 

}

void PlayGame::showStatus(TamaState& state)
{
    printf("\n");
    display.ShowUsual();
    printf("\n\t\t\t   =================================================================================================\n");
    printf("\t\t\t\t\t\t\t   ★다마고치 상태★\n\t\t\t\t\t\t\t      다마고치 이름 : %s\n", TamaName.c_str());
    printf("\t\t\t\t      에너지 : %d\t행복도 : %d\t경험치 : %.1f\t청결도 : %d\t돈 : %d\n", state.Energy, state.Happiness,state.Exp, state.Clean, state.Money);
    //printf ( "\t\t\t\t\t\t\t에너지     :     %d\n" , Energy );
    //printf ( "\t\t\t\t\t\t\t행복도     :     %d\n" ,Happiness );
    //printf ( "\t\t\t\t\t\t\t경험치     :     %.1f\n",Exp );
    //printf ( "\t\t\t\t\t\t\t청결도     :     %d\n",Clean);
    //printf("\t\t\t\t\t\t\t========================\n");
    printf("\t\t\t   =================================================================================================\n\n");
}


