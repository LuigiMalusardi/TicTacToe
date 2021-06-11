
#include "interface.h"

extern game_struct mGame;
extern game_mode_enum mGamemode;

//Disegna menu iniziale del gioco
game_mode_enum DrawInitialMenu(void){
	printf("%s\n","********** TIC TAC TOE **********");
	printf("%s\n","****Press any key to continue****");
	getch();

	printf("\n1. PLAYER vs COMPUTER\n2. PLAYER vs PLAYER\n\nMake your choice: ");
    int gamemode = 0;
	scanf("%d",&gamemode);

    switch(gamemode){
        case 1:
            return PLAYER_VS_PC;
            break;
        case 2:
            return PLAYER_VS_PLAYER;
            break;
        default:
            return UNDEFINED;
            break;
    }
}

//Disegna la grafica del gioco
void DrawMainScene(void){
	
	//Pulisco schermo
	system("cls");

	//Disegno i punteggi
	if(mGamemode == 1){
		printf("PUNTEGGIO:\n\n	GIOCATORE: %d\n	       AI: %d\n",mGame.score_p1,mGame.score_p2);
	} else {
		printf("PUNTEGGIO:\n\n	GIOCATORE 1: %d\n	GIOCATORE 2: %d\n",mGame.score_p1,mGame.score_p2);
	}
	
	printf("\n");

    //Se partita finita esco senza disegnare la board
    if(mGame.winner != NONE)
        return;

    //Disegno la board di gioco
    int i,j;
	for(i = 0;i < 3;i++){	
		printf("     ");
		for(j = 0;j < 3;j++){
			if(j != 2){
				printf("%2c |",(char)mGame.board[i][j]);
			}else{
				printf("%2c ",(char)mGame.board[i][j]);
			}
		}
		if(i != 2){
			printf("\n     ---|---|---\n");
		}else{
			printf("\n");
		}
	}
}

//Disegna la grafica di fine partita
bool DrawEndScene(void){
    //Vincitore DRAW
	if(mGame.winner == DRAW)
		printf("\n\nDRAW! \n\n");
	else	//Vincitore PLAYERS
		printf("\n\n%c is the winner! \n\n",mGame.winner);
	printf("Do you want to play again? Y/N ");
	char endgame;
	scanf(" %c",&endgame);
    //Se input == SI gioco altra partita
	if(endgame == 'y' || endgame == 'Y') return true;

    return false;
}

//Chiede la mossa al giocatore e lo restituisce
int GetPlayerInput(void){
	int choice = 0;

	if(mGamemode == PLAYER_VS_PC && mGame.playing_player == PLAYER_2){
		//Gioca AI
		choice = AIPlay();
		//Resetto winner perchè potrebbe essere rimasto salvato da MinMax
		mGame.winner = NONE;

	} else{
		//Gioca player
		printf("\nPlayer %c move: ", mGame.playing_player);
		scanf("%d",&choice);
	}

	return choice;
}