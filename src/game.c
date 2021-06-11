#include "game.h"

//VARIABILI
game_struct mGame;
game_mode_enum mGamemode;

//FUNZIONI
//Inizializza le variabili di gioco
void GameInit(void){

	ResetGame();

	//Disegno menu iniziale
	mGamemode = DrawInitialMenu();
}

//Main task del gioco
void GameTask(void){

	DrawMainScene();
	do{
		
		int choice = GetPlayerInput();
		//Se scelta valida
		if(isChoiceValid(choice)){

			//Inserisco la scelta nel gioco
			int row = GetRow(choice);
			int col = GetColumn(choice);
			mGame.board[row][col] = mGame.playing_player;

			//Cambio giocatore
			PlayerSwitch();
		}
		DrawMainScene();

	}while(!isGameEnded());

}

//Cambia il giocatore che sta giocando
void PlayerSwitch(void){
	
	if(mGame.playing_player == PLAYER_1){
	mGame.playing_player = PLAYER_2;
	}
	else {								
	mGame.playing_player = PLAYER_1;
	}
}

//Se la casella scelta è libera restituisce TRUE altrimenti FALSE
bool isChoiceValid(int choice){

	int row = GetRow(choice);
	int col = GetColumn(choice);

	//Controllo se la casella è occupata
	if(mGame.board[row][col] == NONE){
		//Casella libera, mossa valida
		return true;
	}

	//Casella piena, mossa non valida
	return false;
	
}

//Restituisce il valore di colonna della scelta
int GetColumn(int choice){
	//Switch per colonne
	switch(choice){
		case 7:
		case 4:
		case 1:
			return 0;
			break;
		case 8:
		case 5:
		case 2:
			return 1;
			break;
		default: 
			return 2;
			break;
	}
}

//Restituisce il valore di riga della scelta
int GetRow(int choice){
	//Switch per righe
	switch(choice){
		case 1:
		case 2:
		case 3:
			return 2;
			break;
		case 4:
		case 5:
		case 6:
			return 1;
			break;
		default: 
			return 0;
			break;
	}
}

//Stampa a schermo il vincitore e chiude il gioco
void GameEnd(void){
	//Se vincitore diverso da DEFAULT
	if(mGame.winner != NONE){

		//Imposta il punteggio
		SetScore(mGame.winner);

		//Stampo il punteggio
		DrawMainScene();

		//Restituisce true se il giocatore ha chiesto di rigiocare
		if(DrawEndScene()){	

			//Avvio un'altra partita
			RestartGame();

		} else {
			//Smetto di giocare, chiedo prima di uscire l'inserimento di un quasiasi valore
			system("pause");
		}
		
	} else 	//Sto giocando winner = NONE
		printf("\n %c playing... ",mGame.playing_player);
}

//Fornisce i punteggi in base al vincitore fornito
void SetScore(player_enum winner){
	//Fornisco punteggi
	if(winner == PLAYER_1){
		mGame.score_p1++;
	} else if(winner == PLAYER_2){
		mGame.score_p2++;
	} else if(winner == DRAW){
		mGame.score_p1++;
		mGame.score_p2++;	
	}
}

//Reset variabili di gioco
void ResetGame(void){

	//Resetto la board
	
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			mGame.board[i][j] = NONE;
		}
	}

	//Resetto giocatore e vincitore
	mGame.playing_player = PLAYER_1;
	mGame.winner = NONE;

}

//Per giocare nuovamente resetto e chiamo gametask e gameend
void RestartGame(void){

	ResetGame();
	GameTask();
	GameEnd();
}