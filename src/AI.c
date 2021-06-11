#include "AI.h"

int bestRow;
int bestCol;
extern game_struct mGame;
extern game_mode_enum mGamemode;

/* Restituisce un numero corrispondente alla casella che l'AI ha scelto 
*/
int AIPlay(void){

	int bestScore = INT_MIN;
	bestRow = -1;
	bestCol = -1;

	//Per ogni casella
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			//Per ogni casella vuota
			if(mGame.board[i][j] == NONE){
				//Provo la mossa
				mGame.board[i][j] = PLAYER_2;
				//Chiamo algoritmo
				int score = minmax_algo(0,false);
				//Azzero mossa
				mGame.board[i][j] = NONE;

				//Se score è maggiore lo salvo
				if(score > bestScore){
					bestScore = score;
					bestRow = i;
					bestCol = j;
				}
			}
		}
	}
	return (bestCol + 1) + 3 * (2 - bestRow);
}


int minmax_algo(int depth,bool isAiTurn){

	if(isGameEnded()){
		switch(mGame.winner){
			case PLAYER_1:
				return LOSE_SCORE;
				break;
			case PLAYER_2:
				return WIN_SCORE;
				break;
			default:
				return DRAW_SCORE;
				break;
		}
	}

	if(isAiTurn){
		//MAX PLAYER
		int bestScore = INT_MIN;
		int i,j;
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				//Per ogni casella vuota
				if(mGame.board[i][j] == NONE){
					//Provo la mossa
					mGame.board[i][j] = PLAYER_2;
					//Chiamo algoritmo
					int score = minmax_algo(depth + 1,false);
					//Azzero mossa
					mGame.board[i][j] = NONE;
					//Se score è maggiore lo salvo
					if(score > bestScore){
						bestScore = score;
					}
				}
			}
		}
		return bestScore;

	} else {
		//MIN PLAYER
		int bestScore = INT_MAX;
		int i,j;
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				//Per ogni casella vuota
				if(mGame.board[i][j] == NONE){
					//Provo la mossa
					mGame.board[i][j] = PLAYER_1;
					//Chiamo algoritmo
					int score = minmax_algo(depth + 1,true);
					//Azzero mossa
					mGame.board[i][j] = NONE;
					//Se score è maggiore lo salvo
					if(score < bestScore){
						bestScore = score;
					}
				}
			}
		}
		return bestScore;
	}
}