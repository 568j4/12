#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_CHARNAME    200
#define N_PLAYER        3
#define MAX_DIE         6

#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAX_CHARNAME] = {"LIVE","DIE","END"};


void opening(void)
{
     printf("======\n");
     printf(" S.G. \n");
     printf("======\n");   
}


int rolldie(void)
{
    return rand() % MAX_DIE + 1;
}


void printPlayerPosition(int player)
{
     int i;
     for(i=0; i< N_BOARD; i++)
     {
         printf("|");
         if (i == player_position[player])
            printf("%c", player_name[player][0]);
         else
         {
             if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
             else
                printf(" ");
         }                 
     }
     printf("|\n");
}

void printPlayerStatus(void)
{
     int i;
     printf("player status ---\n");
     for (i=0;i<N_PLAYER;i++)
     {
         printf("%s : pos %i, coin %i, status : %s\n",
                player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
     }
     printf("-----------------\n");
}

void checkDie(void)
{
     int i;
     for (i=0;i<N_PLAYER;i++)
         if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
            player_status[i] = PLAYERSTATUS_DIE;
}

int game_end(void)
{
  	int i;
  	int flag_end=1;
  	for (i=0;N_PLAYER;i++)
  	{
  		if (player_status[i]==PLAYERSTATUS_LIVE)
  		{
  			flag_end=0;
  			break;
		  }
	  }
	  
	  return flag_end;
}
  
int getAlivePlayer(void)
{
  	int i;
  	int cnt = 0;
  	for (i=0 ; i < N_PLAYER ; i++)
  	{
  		if(player_status[i] == PLAYERSTATUS_LIVE)
  		   cnt++;
	}
	return cnt;
}
  
int getWinner(void)
{
  	int i;
  	int winner = 0;
  	int max_coin = -1;
  	
  	for (i=0; i < N_PLAYER; i++)
  	{
  		if (player_coin[i] > max_coin)
  		{
  			max_coin = player_coin[i];
  			winner=i;
		}
	}
	return winner;
}

int main(int argc, char *argv[])
{
  int pos=0;
  int i;
  int turn = 0;
  
  srand((unsigned)time(NULL));
  

  opening();
  

  board_initboard();

  for (i=0; i<N_PLAYER; i++)
  {
      player_position[i] = 0;
      player_coin[i] = 0;
      player_status[i] = PLAYERSTATUS_LIVE;
      //player_name
      printf("Player %i's name:", i);
      scanf("%s", player_name[i]);
  }
  
  
  
  
  

  do 
  {
    int step;
    int coinResult;
    char c;
    
    if (player_status[turn] != PLAYERSTATUS_LIVE)
    {
       turn = (turn + 1) % N_PLAYER;
       continue;
    }
    

    board_printBoardStatus();
    for (i=0; i < N_PLAYER; i++)
        printPlayerPosition(i);
    printPlayerStatus();
    
    

    printf("%s turn!! ", player_name[turn]);
    printf("press any key to roll a die!\n");
    scanf(" %c", &c);
    fflush(stdin);
    step = rolldie();
    

    player_position[turn] += step;
    if (player_position[turn] >= N_BOARD)
        player_position[turn] = N_BOARD-1;
    
    if (player_position[turn] == N_BOARD-1)
       player_status[turn] = PLAYERSTATUS_END;

    

    coinResult = board_getBoardCoin(player_position[turn]);
    player_coin[turn] += coinResult;

    

    turn = (turn + 1) % N_PLAYER;
    
   
    if (turn == 0)
    {
    
       int shark_pos = board_stepShark();
       printf("Shark moved to %i\n", shark_pos);
       checkDie();
    } 
  } while(!game_end());

  
  int winner = getWinner();
  printf("Game Over! Winner: %s\n", player_name[winner]);

  system("PAUSE");
  return 0;
}
