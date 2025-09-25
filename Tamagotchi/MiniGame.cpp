#include "MiniGame.h"
#include "PlayGame.h"
#include <random>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Display.h"
#include "Tama.h"
#include <cstdio>
#include <string>

// 미니게임 모아두는 곳
Display d;
MiniGame miniGame;
Tama tama;

enum ChamCham {
    Left = 0,
    Right
};

struct GAMEREWARDS {
    const int CharmEnergyLoss = 10;
    const float ChamExpReward = 10.0;
    const int ChamMoneyReward = 10;
    const int ChamHappyReward = 5;
    const int ChamCleanLoss = 10;

    const int TypingEnergyLoss = 15;
    const float TypingExpReward = 20.0;
    const int TypingMoneyReward = 20;
    const int TypingHappyReward = 5;
    const int TypingCleanLoss = 20;

    //const int ReactionEnergyLoss = 20;
    //const float ReactionExpReward = 40.0;
    //const int ReactionMoneyReward = 40;
    //const int ReactionHappyReward = 5;
    //const int ReactionCleanLoss = 30;      

    const int TreasureEnergyLoss = 30;

    const int FailReward = 5;
};
GAMEREWARDS reward;

    char WhichGame = ' '; // int 로 했더니 입력받을 때 문자가 입력되면 무한루프에 빠져서 char로 고침

void MiniGame::ShowMiniGame(TamaState& state)
{    
    WhichGame = ' ';

    while (WhichGame != '4') {
        printf("\n\t\t\t\t\t\t\t+------------------------+\n");
        printf("\t\t\t\t\t\t\t|       게임 메뉴        |\n");
        printf("\t\t\t\t\t\t\t+------------------------+\n");
        printf("\t\t\t\t\t\t\t|  남은 게임 횟수 : %d번  |\n", state.GameLimit);
        printf("\t\t\t\t\t\t\t|  1. 참참참             |\n");
        printf("\t\t\t\t\t\t\t|  2. 키보드 따라치기    |\n");
        printf("\t\t\t\t\t\t\t|  3. 보물 찾기          |\n");
        printf("\t\t\t\t\t\t\t|  4. 게임 종료          |\n");
        printf("\t\t\t\t\t\t\t+------------------------+\n");
        printf("\t\t\t\t\t무슨 게임을 하시겠어요? ");
        std::cin >> WhichGame;

        while (!(WhichGame == '1' || WhichGame == '2' || WhichGame == '3' || WhichGame == '4')) {
            printf("\t\t\t\t\t그런 게임은 없어요! \n");
            printf("\t\t\t\t\t무슨 게임을 하시겠어요? ");
            std::cin >> WhichGame;
        }

        switch (WhichGame) {
        case '1':
        {
            if (state.GameLimit > 0) {
                if (state.Energy >= reward.CharmEnergyLoss) {
                    state.GameLimit--;
                    playChamChamCham(state);
                }
                else {
                    printf("\t\t\t\t에너지가 부족해서 게임을 할 수 없어..!\n");
                }
            }
            else
            {
                printf("\t\t\t\t게임 횟수를 모두 소진해서 놀아줄 수 없어...\n\t\t\t\t다마고치를 재우면 게임 횟수가 초기화 돼!\n");
            }
        }
        break;
        case '2':
        {
            if (state.GameLimit > 0) {
                if (state.Energy >= reward.TypingEnergyLoss) {
                    state.GameLimit--;
                    playTypingChallenge(state);
                }
                else {
                    printf("\t\t\t\t에너지가 부족해서 게임을 할 수 없어..!\n");
                }
            }
            else
            {
                printf("\t\t\t\t게임 횟수를 모두 소진해서 놀아줄 수 없어...\n\t\t\t\t다마고치를 재우면 게임 횟수가 초기화 돼!\n");
            }
        }
        break;
        case '3':
        {
            if (state.GameLimit > 0) {
                if (state.Energy >= reward.TreasureEnergyLoss) {
                    state.GameLimit--;
                    playTreasureHunt(state);
                }
                else {
                    printf("\t\t\t\t에너지가 부족해서 게임을 할 수 없어..!\n");
                }
            }
            else
            {
                printf("\t\t\t\t게임 횟수를 모두 소진해서 놀아줄 수 없어...\n\t\t\t\t다마고치를 재우면 게임 횟수가 초기화 돼!\n");
            }
        }
        break;
        default:
            break;
        }
    }
    
}
void WhenLevelUp(TamaState& state) {
    // 경험치 모았을때 레벨업시키기
    if (state.Exp >= 50.0f && state.Level == 1) {
        system("cls");
        d.LevelUp();
        printf("\t\t\t\t\t다마고치가 2레벨이 되었어요!!!\n");
        Sleep(1000);
        state.Level++;
        state.Exp = 0;
        state.Energy += 20;
        state.Money += 20;

        WhichGame = '4';
    }
    else if (state.Exp >= 80.0f && state.Level == 2)
    {
        system("cls");
        d.LevelUp();
        printf("\t\t\t\t\t다마고치가 3레벨이 되었어요!!!\n");
        Sleep(1000);
        state.Level++;
        state.Exp = 0;
        state.Energy += 20;
        state.Money += 30;
        //miniGame.ShowMiniGame(state);

        WhichGame = '4';
        
    }
    else if (state.Exp >= 120.0f && state.Level == 3)
    {
        system("cls");
        d.LevelUp();
        printf("\t\t\t\t\t다마고치가 4레벨이 되었어요!!!\n");
        Sleep(1000);
        state.Level++;
        state.Exp = 0;
        state.Energy += 20;
        state.Money += 40;

        WhichGame = '4';

    }
    else if (state.Exp >= 150.0f && state.Level == 4)
    {
        system("cls");
        d.LevelUp();
        printf("\t\t\t\t\t다마고치가 5레벨이 되었어요!!!\n");
        d.EvolutionShow(); // 다마고치가 5레벨이 되어 게임 종료

        WhichGame = '4';

    }

}
float RewardExp = 0.0f;
int MiniGame::playChamChamCham(TamaState& state)
{

    int PlayTime = 3;
    //참참참은 총 3번 진행해서 승패 판정
    std::string PlayersHand;
    int WinCount = 0;

    state.Energy -= reward.CharmEnergyLoss; 
    state.Energy = tama.LimitState(state.Energy);
    state.Happiness += reward.ChamHappyReward;
    state.Happiness = tama.LimitState(state.Happiness);
    state.Clean -= reward.ChamCleanLoss;
    state.Clean = tama.LimitState(state.Clean);

    system("cls");
    d.ShowUsual();
    printf("\n\t\t\t\t\t참참참을 시작할게!\n\n\t\t\t\t\t게임은 총 %d번 진행이야 \n", PlayTime);
    printf("\t\t\t\t\t다마고치가 뭘 낼지 많이 맞추면 승리야!! \n\t\t\t\t\t왼쪽이면 L 오른쪽이면 R을 입력해줘!\n");
    printf("\t\t\t\t\t참참참~! ");
    std::cin >> PlayersHand;

    while (!(PlayersHand == "L" || PlayersHand == "l" || PlayersHand == "R" || PlayersHand == "r")) {
        printf("\t\t\t\t\t왼쪽이면 L 오른쪽이면 R을 입력해줘!\n");
        printf("\t\t\t\t\t참참참~! ");
        std::cin >> PlayersHand;
    }

    while (PlayTime > 0) {

        // 참참참 머리 방향
        int Direction = rand() % 2;
        // 0이면 왼쪽 1이면 오른쪽
      
        if (Direction == 0) {
            //왼쪽인 경우
            system("cls");
            d.ChamChamChamLeft();
            if (PlayersHand == "L" || PlayersHand == "l") {
                printf("\n\t\t\t\t\t\t\t너가 맞췄어!! \n");
                WinCount++;
            }
            else {
                printf("\n\t\t\t\t\t\t\t못 맞췄어.. \n");
            }
        }
        else {
            //오른쪽인 경우
            system("cls");
            d.ChamChamChamRight();
            if (PlayersHand == "R" || PlayersHand == "r") {
                printf("\n\t\t\t\t\t\t\t너가 맞췄어!! \n");
                WinCount++;
            }
            else {
                printf("\n\t\t\t\t\t\t\t못 맞췄어.. \n");
            }
        }
            PlayTime--;
            if (PlayTime > 0) {
                printf("\t\t\t\t\t\t\t참참참~! ");
                std::cin >> PlayersHand;
            }
    }
    
    if (WinCount >= 2) {
      
        printf("\n\t\t\t\t\t우와 너가 더 많이 맞춰서 너의 승리야!!! \n");
        if (state.Happiness >= 80) {
            RewardExp = (reward.ChamExpReward * 2);
        }
        else if (state.Happiness >= 50) {
            RewardExp += (reward.ChamExpReward * 1.5);
        }
        else {
            RewardExp = reward.ChamExpReward;
        }
        printf("\t\t\t\t\t보상으로 너에게 %.1f만큼의 경험치와 %d만큼의 돈을 줄게!\n\n" , RewardExp, reward.ChamMoneyReward);
        //state.Exp += 50; // 테스트를 위해
        state.Exp += RewardExp; 
        state.Money += reward.ChamMoneyReward;
        Sleep(1000);
        WhenLevelUp(state);
        
    }
    else {
        printf("\n\t\t\t\t\t나보다 많이 못 맞춰서 너의 패배야ㅜㅜㅜ \n");
        printf("\t\t\t\t\t그래도 노력했으니 %d만큼의 돈을 줄게!\n\n", reward.FailReward);
        state.Money += reward.FailReward;
    }
   
    return 0;
}

int MiniGame::playTypingChallenge(TamaState& state)
{
    state.Energy -= reward.TypingEnergyLoss;
    state.Energy = tama.LimitState(state.Energy);
    state.Happiness += reward.TypingHappyReward;
    state.Happiness = tama.LimitState(state.Happiness);
    state.Clean -= reward.TypingCleanLoss;
    state.Clean = tama.LimitState(state.Clean);

    system("cls");
    d.TypingTama();

    bool PlayerWin = true; 

    const int StringSize = 10; 
    char RandomString[StringSize+1]; // 랜덤 문자열을 담을 배열 // 10글자이지만 마지막 \0을 위해
    char InputTyping[StringSize+1];

    // 너무 어려워서 10초 제한 없앨래 ㅜㅜㅜ
    //printf("\t\t\t\t\t내가 출력해주는 문자열을 따라 치는 게임이야!n 제한시간은 10초 줄게! \n\t\t\t\t\t제한시간내에 똑같이 쓰지 못하면 너의 패배야!\n"); 
    // 시간세기 시작
    //setTimer 함수 사용하기

    printf("\n\t\t\t\t\t키보드 따라치기를 시작할게!\n\n");
    printf("\t\t\t\t\t\t내가 출력해주는 문자열을 따라 치는 게임이야!\n\t\t\t\t\t똑같이 쓰지 못하면 너의 패배야!\n");
    printf("\n\t\t\t\t\t\t문제 : ");
    for (int i = 0; i < StringSize;i++) {
        RandomString[i] = rand() % 25 + 65; // 대문자만 나오게 랜덤 문자열 생성
        printf("%c", RandomString[i]);
    }
    RandomString[StringSize] = '\0';

    printf("\n\n");

    // 입력받기
    printf("\t\t\t\t\t\t따라 써!! : ");
    std::cin >> InputTyping;
 
    // 랜덤 생성된 문자열과 입력받은 문자열 비교
    for (int n = 0; n < StringSize; n++) {
            if (RandomString[n] != InputTyping[n])
            {
                PlayerWin = false;
                break;
            }
    }
    
    if (PlayerWin) {

        printf("\n\n\t\t\t\t\t\t똑같이 적었네! 너의 승리야!!!! \n");
        if (state.Happiness >= 80) {
            RewardExp = (reward.TypingExpReward * 2);
        }
        else if (state.Happiness >= 50) {
            RewardExp += (reward.TypingExpReward * 1.5);
        }
        else {
            RewardExp = reward.TypingExpReward;
        }
        printf("\t\t\t\t\t\t보상으로 너에게 %.1f만큼의 경험치와 %d만큼의 돈을 줄게!\n\n", RewardExp, reward.TypingMoneyReward);
        //state.Exp += 50; // 테스트를 위해
        state.Exp += RewardExp;
        state.Money += reward.TypingMoneyReward;
        Sleep(1000);
        WhenLevelUp(state);

    }
    else {
        printf("\n\n\t\t\t\t\t\t똑같이 못 써서 너의 패배야ㅜㅜㅜ \n");
        printf("\t\t\t\t\t\t그래도 노력했으니 %d만큼의 돈을 줄게!\n\n", reward.FailReward);
        state.Money += reward.FailReward;
    }

    return 0;
}

int MiniGame::playTreasureHunt(TamaState& state)
{
    state.Energy -= reward.TreasureEnergyLoss;
    state.Energy = tama.LimitState(state.Energy);

    int LimitMove = rand() & 10 + 1;

    printf("\n\t\t\t\t\t\t보물찾기 시간~!!!\n");


    return 0;
}

//int MiniGame::playReactionTest(TamaState& state)
//{
//    //state.Energy -= 10; // 나중에 변수로 수정
//    //printf("3~5초 사이 랜덤한 시간에 지금! 이라는 글자가 뜨면 아무 키를 눌러봐!\n");
//    // 랜덤 함수로 랜덤한 시간 생성
//    // 해당 시간이 지나고 
//    // 지금! 이라는 글자 출력 및 시간 측정 시작
//    // 입력값이 생기면 시간 측정 종료
//    // 시간이 5초 이내이면 보상 지급
//
//    ///*실행 시간을 측정하고 싶은 코드*/
//
//    return 0;
//}
