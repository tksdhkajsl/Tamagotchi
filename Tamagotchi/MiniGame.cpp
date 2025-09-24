#include "MiniGame.h"
#include "PlayGame.h"
#include "Tama.h"
#include <random>
#include <iostream>
#include <Windows.h>
#include <time.h>

// 미니게임 모아두는 곳

enum ChamCham {
    Left = 0,
    Right
};

struct GAMEREWARDS {
    const int CharmEnergyLoss = -10;
    const float ChamExpReward = 10.0;
    const int ChamMoneyReward = 10;
    const int ChamHappyReward = 10;
    const int ChamCleanLoss = -10;

    const int TypingEnergyLoss = -15;
    const float TypingExpReward = 20.0;
    const int TypingMoneyReward = 20;
    const int TypingHappyReward = 10;
    const int TypingCleanLoss = -20;

    const int ReactionEnergyLoss = -20;
    const float ReactionExpReward = 40.0;
    const int ReactionMoneyReward = 40;
    const int ReactionHappyReward = 15;
    const int ReactionCleanLoss = -30;
};

void MiniGame::ShowMiniGame(std::string TamaName)
{
    printf("\n\t\t\t\t\t\t\t+------------------------+\n");
    printf("\t\t\t\t\t\t\t|       게임 메뉴        |\n");
    printf("\t\t\t\t\t\t\t+------------------------+\n");
    printf("\t\t\t\t\t\t\t|  남은 게임 횟수 : %d번 |\n",3);
    printf("\t\t\t\t\t\t\t|  1. 참참참             |\n");
    printf("\t\t\t\t\t\t\t|  2. 키보드 따라치기    |\n");
    printf("\t\t\t\t\t\t\t|  3. 반사신경 테스트    |\n");
    printf("\t\t\t\t\t\t\t|  4. 게임 종료          |\n");
    printf("\t\t\t\t\t\t\t+------------------------+\n");
    
    int WhichGame = 0;
    while (WhichGame != 4) {
        printf("\t\t\t\t\t무슨 게임을 하시겠어요? ");
        std::cin >> WhichGame;

        while (!(WhichGame >= 1) && !(WhichGame <= 4)) {
            printf("\t\t\t\t\t그런 게임은 없어요! \n");
            printf("\t\t\t\t\t무슨 게임을 하시겠어요? ");
            std::cin >> WhichGame;
        }

        switch (WhichGame) {
        case 1:
        {
            printf("참참참\n");
            playChamChamCham();
        }
        break;
        case 2:
        {
            printf("타이핑\n");
            playTypingChallenge();
        }
        break;
        case 3:
        {
            printf("반응\n");
            playReactionTest();
        }
        break;
        default:
            break;
        }
    }
}

//int MiniGame::playChamChamCham(TamaState& state)
int MiniGame::playChamChamCham()
{
    //int PlayTime = 3;
    ////참참참은 총 3번 진행해서 승패 판정
    //char PlayersHand = 0;
    //int WinCount = 0;

    //state.Energy -= 10; // 나중에 변수로 수정
    //printf("참참참을 시작할게!\n 게임은 총 %d번 진행이야 \n", PlayTime);
    //printf("다마고치가 뭘 낼지 많이 맞추면 승리야!! \n 왼쪽이면 L 오른쪽이면 R을 입력해줘!");
    //
    //printf("참참참~!\n");
    //std::cin >> PlayersHand;

    //while (!(PlayersHand == 'L' || PlayersHand == 'R')) {
    //    printf("왼쪽이면 L 오른쪽이면 R을 입력해줘!");
    //    printf("참참참~!\n");
    //    std::cin >> PlayersHand;
    //}

    //while (PlayTime > 0) {
    //    // 참참참 머리 방향
    //    int Direction = rand() % 2;
    //    // 0이면 왼쪽 1이면 오른쪽

    //    if (Direction == 0) {
    //        //왼쪽인 경우
    //        if (PlayersHand == 'L') {
    //            printf("너가 맞췄어!! \n");
    //            WinCount++;
    //        }
    //        else {
    //            printf("못 맞췄어.. \n");
    //        }
    //    }
    //    else {
    //        //오른쪽인 경우
    //        if (PlayersHand == 'R') {
    //            printf("너가 맞췄어!! \n");
    //            WinCount++;
    //        }
    //        else {
    //            printf("못 맞췄어.. \n");
    //        }
    //    }
    //        PlayTime--;
    //}
    //
    //if (WinCount >= 2) {
    //    if (state.Happiness >= 80) {
    //        state.Exp *= 2;
    //    }
    //    else if (state.Happiness >= 50) {
    //        state.Exp *= 1.5;
    //    }

    //    printf("우와 너의 승리야!!! \n");
    //    printf("보상으로 너에게 %.1f만큼의 경험치와 %d만큼의 돈을 줄게!\n\n" , state.Exp, state.Money);
    //    state.Exp += 50.0;
    //    state.Money += 50;
    //}
    return 0;
}

int MiniGame::playTypingChallenge()
{
    //state.Energy -= 10; // 나중에 변수로 수정
    //printf("내가 출력해주는 문자열을 따라 치는 게임이야!n 제한시간은 10초 줄게! \n 제한시간내에 똑같이 쓰지 못하면 너의 패배야!\n");
    //// 문자열 랜덤 생성
    //// 시간세기 시작
    ////setTimer 함수 사용하기
    //
    //// 입력받기
    //// 랜덤 생성된 문자열과 입력받은 문자열 비교
    //// 맞으면 보상 // 실패하면 아무것도

    //if (state.Happiness >= 80) {
    //    state.Exp *= 2;
    //}
    //else if (state.Happiness >= 50) {
    //    state.Exp *= 1.5;
    //}

    //printf("우와 너의 승리야!!! \n");
    //printf("보상으로 너에게 %.1f만큼의 경험치와 %d만큼의 돈을 줄게!\n\n", state.Exp, state.Money);
    //state.Exp += 50.0;
    //state.Money += 50;

    return 0;
}

int MiniGame::playReactionTest()
{
    //state.Energy -= 10; // 나중에 변수로 수정
    //printf("3~5초 사이 랜덤한 시간에 지금! 이라는 글자가 뜨면 아무 키를 눌러봐!\n");
    //// 랜덤 함수로 랜덤한 시간 생성
    //// 해당 시간이 지나고 
    //// 지금! 이라는 글자 출력 및 시간 측정 시작
    //// 입력값이 생기면 시간 측정 종료
    //// 시간이 5초 이내이면 보상 지급
    //// 
    ////time_t start, finish;
    ////double duration;

    ////start = time(NULL);

    /////*실행 시간을 측정하고 싶은 코드*/

    ////finish = time(NULL);

    ////duration = (double)(finish - start);
    ////printf("%f초", duration);


    //if (state.Happiness >= 80) {
    //    state.Exp *= 2;
    //}
    //else if (state.Happiness >= 50) {
    //    state.Exp *= 1.5;
    //}

    //printf("우와 너의 승리야!!! \n");
    //printf("보상으로 너에게 %.1f만큼의 경험치와 %d만큼의 돈을 줄게!\n\n", state.Exp, state.Money);
    //state.Exp += 50.0;
    //state.Money += 50;
    return 0;
}
