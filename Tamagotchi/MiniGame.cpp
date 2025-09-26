#include "MiniGame.h"
#include <random>
#include <iostream>
#include <Windows.h>
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

    // 반응속도 테스트 미니게임 포기
    //const int ReactionEnergyLoss = 20;
    //const float ReactionExpReward = 40.0;
    //const int ReactionMoneyReward = 40;
    //const int ReactionHappyReward = 5;
    //const int ReactionCleanLoss = 30;      

    const int TreasureEnergyLoss = 30;

    const int FailReward = 5;
};

GAMEREWARDS reward;

//char WhichGame = ' '; // int 로 했더니 입력받을 때 문자가 입력되면 무한루프에 빠져서 char로 고침
                        // 이것도 여러글자 입력하면 그 글자수만큼 반복해서 변경..

void ShowGameMenu(TamaState& state) {
    printf("\n\t\t\t\t\t\t+----------------------------------+\n");
    printf("\t\t\t\t\t\t|             게임 메뉴            |\n");
    printf("\t\t\t\t\t\t+----------------------------------+\n");
    printf("\t\t\t\t\t\t|      남은 게임 횟수 : %d번        |\n", state.GameLimit);
    printf("\t\t\t\t\t\t|  1. 참참참 (-10 에너지)          |\n");
    printf("\t\t\t\t\t\t|  2. 키보드 따라치기 (-15 에너지) |\n");
    printf("\t\t\t\t\t\t|  3. 보물 찾기 (-30 에너지)       |\n");
    printf("\t\t\t\t\t\t|  4. 게임 종료                    |\n");
    printf("\t\t\t\t\t\t+----------------------------------+\n");
}
int WhichGame = 0;
void MiniGame::ShowMiniGame(TamaState& state)
{
    WhichGame = 0;
    std::string InputGameMenu;
    int ShowMenuCount = 0; // 게임 한번 한 이후에 다시 게임 메뉴 출력할때 메뉴는 한번만 출력하고싶어서

    system("cls");
    d.ShowUsual();
    ShowGameMenu(state);
    /*  printf("\t\t\t\t\t무슨 게임을 하시겠어요? (예시 : 1) ");
      std::cin >> InputGameMenu;*/

    while (true) {
        if (ShowMenuCount == 1) {
            ShowGameMenu(state);
            ShowMenuCount = 0;
        }
        printf("\t\t\t\t\t무슨 게임을 하시겠어요? 현재 에너지 : %d (예시 : 1) ", state.Energy);
        std::cin >> InputGameMenu;

        if (InputGameMenu.length() == 1) {  // 한 글자만 입력되도록
            WhichGame = InputGameMenu[0] - '0'; // -'0' 하면 정수로 변환된다
            if (WhichGame >= 1 && WhichGame <= 4) {
                switch (WhichGame) {
                case 1:
                {
                    if (state.GameLimit > 0) {
                        if (state.Energy >= reward.CharmEnergyLoss) {
                            state.GameLimit--;
                            playChamChamCham(state);
                            ShowMenuCount++;
                        }
                        else {
                            printf("\t\t\t\t\t에너지가 부족해서 게임을 할 수 없어..!\n");
                        }
                    }
                    else
                    {
                        printf("\t\t\t\t\t게임 횟수를 모두 소진해서 놀아줄 수 없어...\n\t\t\t\t\t다마고치를 재우면 게임 횟수가 초기화 돼!\n");
                    }
                }
                break;
                case 2:
                {
                    if (state.GameLimit > 0) {
                        if (state.Energy >= reward.TypingEnergyLoss) {
                            state.GameLimit--;
                            playTypingChallenge(state);
                            ShowMenuCount++;
                        }
                        else {
                            printf("\t\t\t\t\t에너지가 부족해서 게임을 할 수 없어..!\n");
                        }
                    }
                    else
                    {
                        printf("\t\t\t\t\t게임 횟수를 모두 소진해서 놀아줄 수 없어...\n\t\t\t\t다마고치를 재우면 게임 횟수가 초기화 돼!\n");
                    }
                }
                break;
                case 3:
                {
                    if (state.GameLimit > 0) {
                        if (state.Energy >= reward.TreasureEnergyLoss) {
                            state.GameLimit--;
                            playTreasureHunt(state);
                            ShowMenuCount++;
                        }
                        else {
                            printf("\t\t\t\t\t에너지가 부족해서 게임을 할 수 없어..!\n");
                        }
                    }
                    else
                    {
                        printf("\t\t\t\t\t게임 횟수를 모두 소진해서 놀아줄 수 없어...\n\t\t\t\t다마고치를 재우면 게임 횟수가 초기화 돼!\n");
                    }
                }
                break;
                case 4:
                    printf("\t\t\t\t\t놀아주기를 종료합니다..   \n");
                    Sleep(1000);
                    return;
                    break;
                default:
                    break;
                }
            }
            else {
                printf("\t\t\t\t\t그런 게임은 없어요! \n");
            }
        }
        else {
            printf("\t\t\t\t\t그런 게임은 없어요! \n");
        }
    }

}

// 레벨업시 문구 및 수치 변경
void LevelUP(TamaState& state) {
    system("cls");
    state.Level++;
    state.Exp = 0;
    state.Energy += 20;
    state.Money += ((state.Level + 1) * 10);
    d.LevelUp();
    printf("\n\t\t\t\t\t다마고치가 %d레벨이 되었어요!!!\n", state.Level);
    Sleep(1500);
    WhichGame = '4';
}

void WhenLevelUp(TamaState& state) {
    // 경험치 모았을때 레벨업시키기
    if (state.Exp >= 50.0f && state.Level == 1) {
        LevelUP(state);
    }
    else if (state.Exp >= 80.0f && state.Level == 2)
    {
        LevelUP(state);
    }
    else if (state.Exp >= 120.0f && state.Level == 3)
    {
        LevelUP(state);
    }
    else if (state.Exp >= 150.0f && state.Level == 4)
    {
        LevelUP(state);
        Sleep(1200);
        d.EvolutionShow(); // 다마고치가 5레벨이 되어 게임 종료
    }
}
float RewardExp = 0.0f;
int MiniGame::playChamChamCham(TamaState& state)
{

    int PlayTime = 3;
    //참참참은 총 3번 진행해서 승패 판정

    //문장을 입력하는 게임이 아닌 이상 
    //해당 게임에서만 사용하는 문자 입력변수면 char가 더 좋은 선택 
    //std::string PlayersHand;
    char PlayersHand;
    int WinCount = 0;

    state.Energy -= reward.CharmEnergyLoss;
    state.Energy = tama.LimitState(state.Energy);
    state.Happiness += reward.ChamHappyReward;
    state.Happiness = tama.LimitState(state.Happiness);
    state.Clean -= reward.ChamCleanLoss;
    state.Clean = tama.LimitState(state.Clean);

    system("cls");
    d.ShowUsual();
    /*printf("\n\t\t\t\t\t참참참을 시작할게!\n\n\t\t\t\t\t게임은 총 %d번 진행이야 \n", PlayTime);
    printf("\t\t\t\t\t다마고치가 뭘 낼지 많이 맞추면 승리야!! \n\t\t\t\t\t왼쪽이면 L 오른쪽이면 R을 입력해줘!\n");
    printf("\t\t\t\t\t참참참~! ");
    std::cin >> PlayersHand;*/
    //중복 문장이라 제거함.  playChamChamCham 시작되면 아래 while문 시작됨. 중복이 필요하지 않은 게임 설명만 printf
    printf("\n\t\t\t\t\t참참참을 시작할게!\n\n\t\t\t\t\t게임은 총 %d번 진행이야 \n", PlayTime);
    printf("\t\t\t\t\t다마고치가 뭘 낼지 많이 맞추면 승리야!!\n");


    /* while (!(PlayersHand == "L" || PlayersHand == "l" || PlayersHand == "R" || PlayersHand == "r")) {
         printf("\t\t\t\t\t왼쪽이면 L 오른쪽이면 R을 입력해줘!\n");
         printf("\t\t\t\t\t참참참~! ");
         std::cin >> PlayersHand;
     }*/
     //별도의 while문이 되어서 아래 게임 첫째판 종료 후 남은 게임판에서 해당 문으로 돌아오지 않음. 아래의 while문과 합치는 게 맞음




    while (PlayTime > 0) {



        printf("\t\t\t\t\t왼쪽이면 L 오른쪽이면 R을 입력해줘!\n");
        printf("\t\t\t\t\t참참참~!\n\t\t\t\t\t>> ");
        std::cin >> PlayersHand;

        if (!(PlayersHand == 'L' || PlayersHand == 'l' || PlayersHand == 'R' || PlayersHand == 'r'))
        {
            printf("\t\t\t\t\t잘못 입력 했습니다. 다시 입력해줘\n");
            continue;
        }
        // 참참참 머리 방향
        int Direction = rand() % 2;
        // 0이면 왼쪽 1이면 오른쪽

        if (Direction == 0) {
            //왼쪽인 경우
            system("cls");
            d.ChamChamChamLeft();
            if (PlayersHand == 'L' || PlayersHand == 'l') {
                printf("\n\t\t\t\t\t너가 맞췄어!! \n\n");
                WinCount++;
            }
            else {
                printf("\n\t\t\t\t\t못 맞췄어.. \n\n");
            }
        }
        else {
            //오른쪽인 경우
            system("cls");
            d.ChamChamChamRight();
            if (PlayersHand == 'R' || PlayersHand == 'r') {
                printf("\n\t\t\t\t\t너가 맞췄어!! \n\n");
                WinCount++;
            }
            else {
                printf("\n\t\t\t\t\t못 맞췄어.. \n\n");
            }
        }

        PlayTime--;
        //위의 별도 입력 while문 때문에 넣은 듯 한데.
        //while문 합쳐서 진행하면 해당 조건문은 불필요
        /*if (PlayTime > 0) {
            printf("\t\t\t\t\t참참참~! ");
            std::cin >> PlayersHand;
        }*/

    }

    if (WinCount >= 2) {

        printf("\n\t\t\t\t\t우와 너가 더 많이 맞춰서 너의 승리야!!! \n");
        if (state.Happiness >= 80) {
            RewardExp = (reward.ChamExpReward * 2);
        }
        else if (state.Happiness >= 50) {
            RewardExp = (reward.ChamExpReward * 1.5);
        }
        else {
            RewardExp = reward.ChamExpReward;
        }
        printf("\t\t\t\t\t보상으로 너에게 %.1f만큼의 경험치와 %d만큼의 돈을 줄게!\n\n", RewardExp, reward.ChamMoneyReward);
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
    char RandomString[StringSize + 1]; // 랜덤 문자열을 담을 배열 // 10글자이지만 마지막 \0을 위해
    char InputTyping[StringSize + 1];

    // 너무 어려워서 10초 제한 없앨래 ㅜㅜㅜ
    //printf("\t\t\t\t\t내가 출력해주는 문자열을 따라 치는 게임이야!n 제한시간은 10초 줄게! \n\t\t\t\t\t제한시간내에 똑같이 쓰지 못하면 너의 패배야!\n"); 
    // 시간세기 시작
    //setTimer 함수 사용하기

    printf("\n\t\t\t\t\t키보드 따라치기를 시작할게!\n\n");
    printf("\t\t\t\t\t내가 출력해주는 문자열을 따라 치는 게임이야!\n\t\t\t\t\t똑같이 쓰지 못하면 너의 패배야!\n");
    printf("\n\t\t\t\t\t문제 : ");
    for (int i = 0; i < StringSize; i++) {
        RandomString[i] = rand() % 25 + 65; // 대문자만 나오게 랜덤 문자열 생성
        printf("%c", RandomString[i]);
    }
    RandomString[StringSize] = '\0';

    printf("\n\n");

    // 입력받기
    printf("\t\t\t\t\t따라 써!! : ");
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

        printf("\n\n\t\t\t\t\t똑같이 적었네! 너의 승리야!!!! \n");
        if (state.Happiness >= 80) {
            RewardExp = (reward.TypingExpReward * 2);
        }
        else if (state.Happiness >= 50) {
            RewardExp = (reward.TypingExpReward * 1.5);
        }
        else {
            RewardExp = reward.TypingExpReward;
        }
        printf("\t\t\t\t\t보상으로 너에게 %.1f만큼의 경험치와 %d만큼의 돈을 줄게!\n\n", RewardExp, reward.TypingMoneyReward);
        //state.Exp += 50; // 테스트를 위해
        state.Exp += RewardExp;
        state.Money += reward.TypingMoneyReward;
        Sleep(1000);
        WhenLevelUp(state);

    }
    else {
        printf("\n\n\t\t\t\t\t똑같이 못 써서 너의 패배야ㅜㅜㅜ \n");
        printf("\t\t\t\t\t그래도 노력했으니 %d만큼의 돈을 줄게!\n\n", reward.FailReward);
        state.Money += reward.FailReward;
    }

    return 0;
}

int MiniGame::playTreasureHunt(TamaState& state)
{
    system("cls");
    d.TresureHunt();
    state.Energy -= reward.TreasureEnergyLoss;
    state.Energy = tama.LimitState(state.Energy);

    int LimitMove = rand() % 4 + 4; // 랜덤한 보물찾기 위치 4 ~ 8
    int PlayerMove = 0; // 플레이어가 이동한 횟수
    int RandomEvent = -1; // 이동 후 발생하는 무언가 있다 없다 랜덤한 이벤트
    int RandomEvent2 = -1; // 무언가를 확인해보았을때 발생하는 랜덤한 이벤트 
    int RandomTreasureEvent = 0; // 보물상자 보상 랜덤 (경험치, 돈, 없음)
    int PlayerSelect = -1; // 이동하기, 그만두기 행동
    int PlayerSelect2 = -1; // 무언가를 열어보기, 그만두기 행동

    printf("\n\t\t\t\t\t보물찾기 시간~!!!\n");
    while (LimitMove > PlayerMove || PlayerSelect != 0) {
        printf("\t\t\t\t\t이동하려면 1, 그만두려면 0을 입력해줘 ");
        std::cin >> PlayerSelect;

        while (PlayerSelect != 1 && PlayerSelect != 0) {
            printf("\t\t\t\t\t이동하려면 1, 그만두려면 0을 입력해줘 ");
            std::cin >> PlayerSelect;
        }

        RandomTreasureEvent = rand() % 3 + 1;
        int RandomReward = rand() % 40 + 10; // 보물상자를 열었을때 10~50 사이의 경험치 또는 돈을 줄 예정

        if (PlayerSelect == 1) {
            PlayerMove++;
            printf("\n\t\t\t\t\t다마고치가 이동중이야..!\n");
            //printf("보물위치 : %d 플레이어 이동 횟수 : %d \n", LimitMove, PlayerMove);
            if (PlayerMove == LimitMove) {
                // 보물이 있는 위치
                printf("\n\t\t\t\t\t보물 상자를 발견했어!!!!\n");
                printf("\t\t\t\t\t보물 상자를 열어보니 ");
                switch (RandomTreasureEvent) {
                case 1:
                {
                    printf("%d의 경험치가 나왔어!!!!\n", RandomReward);
                    state.Exp += RandomReward;
                    Sleep(1000);
                    return 0;
                }
                break;
                case 2:
                {
                    printf("%d의 돈이 나왔어!!!!\n", RandomReward);
                    state.Money += RandomReward;
                    Sleep(1000);
                    return 0;
                }
                break;
                case 3:
                {
                    printf("아무것도 없당.....!\n\t\t\t\t\t다음 기회를 노려보자...!\n");
                    Sleep(1000);
                    return 0;
                }
                break;
                default:
                    break;
                }
            }
            else {
                // 가는 길
                RandomEvent = rand() % 2 + 1;
                int SmallReward = rand() % 5 + 5; // 5~10 사이의 길에서 줍는 자그마한 보상
                switch (RandomEvent) {
                case 1:
                {
                    printf("\n\t\t\t\t\t아무것도 없다..!\n");
                }
                break;
                case 2:
                {

                    printf("\n\t\t\t\t\t무언가가 있다..!\n");
                    printf("\t\t\t\t\t열어보려면 1번, 무시하려면 2번 : ");
                    std::cin >> PlayerSelect2;
                    RandomEvent2 = rand() % 7 + 1; // 랜덤 이벤트 
                    if (PlayerSelect2 == 1) {
                        switch (RandomEvent2) {
                        case 1:
                        {
                            printf("\n\t\t\t\t\t대애박 돈을 주웠다!!!!..! + 돈 %d\n", SmallReward);
                            state.Money += SmallReward;
                        }
                        break;
                        case 2:
                        {
                            printf("\n\t\t\t\t\t귀여운 고양이를 보았다!! + 행복 %d \n", SmallReward);
                            state.Happiness += SmallReward;
                            if (state.Happiness >= 100) {
                                state.Happiness = 100;
                            }
                        }
                        break;
                        case 3:
                        {
                            printf("\n\t\t\t\t\t시원한 호수를 보았다 수영해볼까?! + 청결도 %d \n", SmallReward);
                            state.Clean += SmallReward;
                            if (state.Clean >= 100) {
                                state.Clean = 100;
                            }
                        }
                        break;
                        case 4:
                        {
                            printf("\n\t\t\t\t\t앗.. 늪이었잖아.....  - 청결도 %d \n", SmallReward);
                            state.Clean -= SmallReward;
                            if (state.Clean < 0) {
                                state.Clean = 0;
                            }
                        }
                        break;
                        case 5:
                        {
                            printf("\n\t\t\t\t\t하수구에 돈을 빠트렸어... - 돈 %d \n", SmallReward);
                            state.Money -= SmallReward;
                            if (state.Money < 0) {
                                state.Money = 0;
                            }
                        }
                        break;
                        case 6:
                        {
                            printf("\n\t\t\t\t\t벌레를 보았어... 기분 나빠 - 행복 %d \n", SmallReward);
                            state.Happiness -= SmallReward;
                            if (state.Happiness < 0) {
                                state.Happiness = 0;
                            }
                        }
                        break;
                        case 7:
                        {
                            printf("\n\t\t\t\t\t자세히 보니 아무것도 없었어.. \n");
                        }
                        break;
                        default:
                            break;
                        }
                    }
                    else if (PlayerSelect2 == 0) {
                        break;
                    }
                }
                break;
                default:
                    break;
                }
            }
        }
        else if (PlayerSelect == 0)
        {
            break;
        }
    }
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
