#include "game.h"

int game[3][3];
int gamemode;
char player;
int winner;
bool forcedExit = false;
int player_1_score = 0;
int player_2_score = 0;

//FUNZIONI
/*	Inizializza le variabili di gioco
*/
void GameStart(void){

	ResetGame();

	//Disegno menu iniziale
	DrawInitialMenu();
}

/*	Disegna menu iniziale del gioco
*/
void DrawInitialMenu(void){
	printf("%s\n","********** TIC TAC TOE **********");
	printf("%s\n","****Press any key to continue****");
	getch();

	printf("\n1. PLAYER vs COMPUTER\n2. PLAYER vs PLAYER\n\nMake your choice: ");
	scanf("%d",&gamemode);
}

/* Main task del gioco
*/
void GameTask(void){

	DrawScene();
	do{
		
		GetPlayerInput();
		if(forcedExit){
			break;
		}
		DrawScene();

	}while(!isGameEnded());

}

/*	Disegna la grafica del gioco
*/
void DrawScene(){
	
	//Pulisco schermo
	system("cls");
	
	char cell = EMPTY_VALUE;
	//Disegno la tabella di gioco
	int i,j;
	if(gamemode == 1){
		printf("PUNTEGGIO:\n\n	GIOCATORE: %d\n	       AI: %d\n",player_1_score,player_2_score);
	} else {
		printf("PUNTEGGIO:\n\n	GIOCATORE 1: %d\n	GIOCATORE 2: %d\n",player_1_score,player_2_score);
	}
	
	printf("\n");
	for(i = 0;i < 3;i++){	
		printf("     ");
		for(j = 0;j < 3;j++){

			cell = game[i][j];

			if(j != 2){
				printf("%2c |",cell);
			}else{
				printf("%2c ",cell);
			}
		}
		if(i != 2){
			printf("\n     ---|---|---\n");
		}else{
			printf("\n");
		}
	}
}

/*	Cambia il giocatore che sta giocando
*/
void PlayerSwitch(){
	
	if(player == PLAYER_1){

		player = PLAYER_2;
	}else{
		player = PLAYER_1;
	}
}

/*Prende l'input del giocatore e se posto libero inserisce la mossa cambiando giocatore
*/
void GetPlayerInput(){
	int choice = 0,row = 0,col = 0;
	if(DEBUG_MODE){
		printf("\nDEBUG MODE ON - 0 to reset	99 to exit\n");
	}

	if(gamemode == 1 && player == PLAYER_2){
		//Gioca AI
		choice = AIPlay();

	} else{
		printf("\nPlayer %c move: ", player);
		scanf("%d",&choice);
	}
	

	//Debug mode
	if(DEBUG_MODE){
	
		if(choice == 0){
			
			//Reset play
			ResetGame();
			return;
		}

		if(choice == 99){
			forcedExit = true;
			return;
		}
	}

	//Switch per righe
	switch(choice){
		case 1:
		case 2:
		case 3:
			row = 2;
			break;
		case 4:
		case 5:
		case 6:
			row = 1;
			break;
		default: 
			row = 0;
			break;
	}

	//Switch per colonne
	switch(choice){
		case 7:
		case 4:
		case 1:
			col = 0;
			break;
		case 8:
		case 5:
		case 2:
			col = 1;
			break;
		default: 
			col = 2;
			break;
	}

	//Se scelta valida
	if(isChoiceValid(row,col)){

		//Inserisco la scelta nel gioco
		InsertChoice(row,col);

		//Cambio giocatore
		PlayerSwitch();
	}
}

/*	Se la casella non ha un valore inserito restituisco TRUE
*/
bool isChoiceValid(int row,int col){

	if(game[row][col] == EMPTY_VALUE){
		
		return true;
	} else {
		return false;
	}
}

/*	Inserisco la scelta del giocatore nel riquadro
*/
void InsertChoice(int row,int col){	
	//Inserisco scelta
	game[row][col] = player;

}

/*	Stampa a schermo il vincitore e chiude il gioco
*/
void GameEnd(){
	//Se vincitore diverso da DEFAULT
	if(winner != EMPTY_VALUE){

		//Vincitore DRAW
		if(winner == DRAW_VALUE)
			printf("\n\nDRAW! \n\n");
		else	//Vincitore PLAYERS
		printf("\n\n%c is the winner! \n\n",winner);
		printf("Do you want to play again? Y/N ");
		char endgame;
		scanf(" %c",&endgame);
		if(endgame == 'y' || endgame == 'Y'){
			if(winner == PLAYER_1){
				player_1_score++;
			} else if(winner == PLAYER_2){
				player_2_score++;
			} else {
				player_1_score++;
				player_2_score++;
			}

			ResetGame();
			GameTask();
			GameEnd();
		} else {

			system("pause");
		}
		
	} else 	//Sto giocando
		printf("\n %c playing... ",player);
}

/*
*/
void ResetGame(void){
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			game[i][j] = EMPTY_VALUE;
		}
	}
	forcedExit = false;
	player = PLAYER_1;
	winner = EMPTY_VALUE;

}