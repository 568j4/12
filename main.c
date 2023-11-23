#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_DIE 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void opening(void)
{
	printf("======\n");
	printf(" S.G. \n");
	printf("======\n");
}

int rolldie(void)
{
	return rand()%MAX_DIE+1;
}

void printPlayerStatus(void)
{
	int i;
	printf("player status ---\n")
	for (i=0;i<N_PLAYER;i++)
	{
		printf("%s: pos %i, coin %i, status: %s\n",
		       player_name[i], player_position[i], player_coin[i])
	}
	printf("------------------\n");
}

void checkDie(void)
{
	int i;
	for (i=0;i<N_PLAYER;i++)
	    if ()
	       player_status[i]=PLAYERSTATUS_DIE;
}

int main(int argc, char *argv[]) 
{
	int pos=0;
	srand((unsigned)time(NULL));
	
	//0.opening
	opening();
	
	//1. 초기화, 플레이어 이름 결정 
	board_initboard();
	
	//2. 반복문(플레이어 턴)
	do{
		int step = rolldie();
		int coinResult;
		char c;
		
		board_printBoardStatus();
		
		pos += step;
		//printf()
		coinResult = board_getBoardCoin(pos);
		
		printf("press any key to continue:");
		scanf("%d", &c);
		fflush(stdin);
		//2-1.플레이어의 상태 출력
		
		//2-2. 주사위 던지기
		//2-3. 이동
		player_position[turn] += step;
		if (player_position[turn] >= N_BOARD) 
			player_position[turn] = N_BOARD-1;
			
		if (player_position[turn] == N_BOARD-1)	
			player_status[turn]=PLAYERSTATUS_END;
		//printf()
		
		//2-4. 동전 줍기
		coinResult=board_getBoardCoin(pos);
		player_coin[turn] += coinResult;
		//printf()
		
		//2-5. 다음턴
		turn = (turn+1)%N_PLAYER; // wrap around
		//2-6. if (저건: 모든 플레이어가 한번씩 턴을 돔)
		    //상어 동작			
	}while(1);
	//3. 정리(승자 계산, 출력 등) 
	
	system("PAUSE");
	return 0;
}
