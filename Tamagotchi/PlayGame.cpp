#include "PlayGame.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>

const int MAXLEVEL = 5;

// 로고나 메뉴창, 다마고치 상태창을 출력하는 곳

PlayGame::PlayGame()
{

}
std::string TamaName;
int PlayGame::PlayTamagotchi()
{

    TamaState state;

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
  
        // 제대로 입력할때까지
        printf("\n\t\t\t\t\t\t\t\tYES OR NO ? ");
        std::cin >> StartORNo;
        
    }
    if (StartORNo == "No" || StartORNo == "N" || StartORNo == "n" || StartORNo == "NO" || StartORNo == "no") {
        printf("\n\t\t\t\t\t\t\t  다마고치를 종료합니다.\n\n\n\n\n\n\n\n\n\n");
        return 0;
    }
    else if (StartORNo == "Yes" || StartORNo == "YES" || StartORNo == "Y" || StartORNo == "y" || StartORNo == "yes") {
        printf("\n\t\t\t\t\t\t\t   이름을 지어주세요! ");
        std::cin >> TamaName;
    }

    if (TamaName == "0125" || TamaName == "980125" || TamaName == "yujin") {
        printf("\t\t\t\t\t★★★개발자를 아는 당신-★\nt\t\t\t\t축복을 내려주게써요★★★");
        Sleep(1500);
        display.EvolutionShow();
    }

    system("cls");
    display.ShowTamaEgg();

    if (state.Level == MAXLEVEL) {
        display.EvolutionShow(); // 다마고치가 5레벨이 되어 게임 종료
    }

    while (state.Level != MAXLEVEL) {
            system("cls");          // 최대레벨이 아니면 계속해서 메뉴화면과 상태창이 뜨는 메인화면을 보여주도록
            showStatus(state);
            ShowMenu(state);
    }

    return 0;
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

        std::string InputMenu;
        int ChooseMenu;
        while (true) {

            printf("\t\t\t\t\t\t\t무엇을 하시겠어요? (예시 : 1) ");
            std::cin >> InputMenu;
            //showStatus(state);

            if (InputMenu.length() == 1) {  // 한 글자만 입력되도록
                ChooseMenu = InputMenu[0]-'0'; // -'0' 하면 정수로 변환된다
                if (ChooseMenu >= 1 && ChooseMenu <= 5) {
                    break;
                }
            }
        }

        switch (ChooseMenu)
        {
        case 1:
            system("cls");
            display.ShowEatingTama();
            tama.Eating(TamaName,state.Energy);
            break;
        case 2:
            system("cls");
            display.ShowUsual();
            minigame.ShowMiniGame(state);
            break;
        case 3:
            system("cls");
            display.ShowUsual();
            tama.Restaurant(TamaName,state);
            break;
        case 4:
            system("cls");
            display.BathTama();
            tama.TakeBath(TamaName,state.Clean);
            break;
        case 5:
            if (state.Energy <=20) {
                printf("\n\t\t\t\t\t\t에너지가 20 이하일 때 자면 다마고치가 피곤해요...\n");
                Sleep(800);
            }
            system("cls");
            display.SleepingTama();
            tama.Sleeping(TamaName,state);
            break; 
        default:
            printf("\t\t\t\t메뉴 선택 중 에러가 발생했습니다. \n");
            break;
        }
}

void PlayGame::showStatus(TamaState& state)
{
    printf("\n");
    if (state.Clean >= 50) {
        display.ShowUsual();
    }
    else {
        display.DirtyTama();
    }
    printf("\n\t\t\t=================================================================================================\n");
    printf("\t\t\t\t\t\t\t     ★다마고치 상태★");
    printf("\n\t\t\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t다마고치 이름: %6s \t\tLV.%d\t\tDAY %3d\n", TamaName.c_str(),state.Level,state.Day);
    if (state.Clean >= 80) {
        printf("\t\t\t  에너지 : %3d/100\t행복도 : %3d/100\t경험치 : %3.1f\t청결도 : 깨끗함    돈 : %4d\n", state.Energy, state.Happiness, state.Exp, state.Money);
    }
    else if (state.Clean >= 50) {
        printf("\t\t\t  에너지 : %3d/100\t행복도 : %3d/100\t경험치 : %3.1f\t청결도 : 꼬질함    돈 : %4d\n", state.Energy, state.Happiness, state.Exp, state.Money);
    }
    else {
        printf("\t\t\t  에너지 : %3d/100\t행복도 : %3d/100\t경험치 : %3.1f\t청결도 : 더러움    돈 : %4d\n", state.Energy, state.Happiness, state.Exp, state.Money);
    }
    printf("\t\t\t=================================================================================================\n\n");
}

