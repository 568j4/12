#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void opening(void)
{
	printf("======\n");
	printf(" S.G. \n");
	printf("======\n");
}


int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
	//0.opening
	opening();
	
	//1. �ʱ�ȭ, �÷��̾� �̸� ���� 
	board_initboard();
	//2. �ݺ��� 
	do{
		int step=rolldie();
		int coinResult;
		char c;
		
		board_printBoardStatus();
		
		pos += step;
		printf()
		coinResult=board_getBoardCoin(pos);
		
		printf("press any key to continue");
		scanf("%d", &c);
		fflush(stdin);
	}
	system("PAUSE");
	return 0;
}
