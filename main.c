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
	
	//1. �ʱ�ȭ, �÷��̾� �̸� ���� 
	board_initboard();
	
	//2. �ݺ���(�÷��̾� ��)
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
		//2-1.�÷��̾��� ���� ���
		
		//2-2. �ֻ��� ������
		//2-3. �̵�
		player_position[turn] += step;
		if (player_position[turn] >= N_BOARD) 
			player_position[turn] = N_BOARD-1;
			
		if (player_position[turn] == N_BOARD-1)	
			player_status[turn]=PLAYERSTATUS_END;
		//printf()
		
		//2-4. ���� �ݱ�
		coinResult=board_getBoardCoin(pos);
		player_coin[turn] += coinResult;
		//printf()
		
		//2-5. ������
		turn = (turn+1)%N_PLAYER; // wrap around
		//2-6. if (����: ��� �÷��̾ �ѹ��� ���� ��)
		    //��� ����			
	}while(1);
	//3. ����(���� ���, ��� ��) 
	
	system("PAUSE");
	return 0;
}
