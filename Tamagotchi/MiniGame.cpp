#include "MiniGame.h"
#include "PlayGame.h"
#include "Tama.h"
#include <random>
#include <iostream>

// 미니게임 모아두는 곳

enum ChamCham {
    Left = 0,
    Right
};

int MiniGame::playChamChamCham(TamaState& state)
{
    int PlayTime = 3;
    //참참참은 총 3번 진행해서 승패 판정
    char PlayersHand = 0;
    int WinCount = 0;

    printf("참참참을 시작할게!\n 게임은 총 %d번 진행이야 \n", PlayTime);
    printf("다마고치가 뭘 낼지 많이 맞추면 승리야!! \n 왼쪽이면 L 오른쪽이면 R을 입력해줘!");
    
    printf("참참참~!\n");
    std::cin >> PlayersHand;

    while (!(PlayersHand == 'L' || PlayersHand == 'R')) {
        printf("왼쪽이면 L 오른쪽이면 R을 입력해줘!");
        printf("참참참~!\n");
        std::cin >> PlayersHand;
    }

    while (PlayTime > 0) {
        // 참참참 머리 방향
        int Direction = rand() % 2;
        // 0이면 왼쪽 1이면 오른쪽

        if (Direction == 0) {
            //왼쪽인 경우
            if (PlayersHand == 'L') {
                printf("너가 맞췄어!! \n");
                WinCount++;
            }
            else {
                printf("못 맞췄어.. \n");
            }
        }
        else {
            //오른쪽인 경우
            if (PlayersHand == 'R') {
                printf("너가 맞췄어!! \n");
                WinCount++;
            }
            else {
                printf("못 맞췄어.. \n");
            }
        }
            PlayTime--;
    }
    
    if (WinCount >= 2) {
        printf("우와 너의 승리야!!! \n");
        printf("보상으로 너에게 %.1f만큼의 경험치와 %d만큼의 돈을 줄게..!\n\n" ,state.Exp, state.Money);
    }
    return 0;
}

int MiniGame::playTypingChallenge()
{
    return 0;
}

int MiniGame::playReactionTest()
{
    return 0;
}
