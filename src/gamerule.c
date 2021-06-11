#include "gamerule.h"

extern game_struct mGame;
extern game_mode_enum mGamemode;

//Controlla se la partita è finita e se c'è un vincitore
bool isGameEnded(void){
	//Controllo righe
    if(CheckRows())
        return true;

	//Controllo colonne
    if(CheckCols())
        return true;

	//Controllo diagonali
    if(CheckDiagonal())
        return true;

	//Controllo lo stallo
    if(isDraw())
        return true;

    return false;
}

//Controlla le righe della partita per un vincitore 
bool CheckRows(void){

	int i;
    //Per ogni riga
	for(i = 0;i < 3;i++){

        //Controllo se la riga è uguale
		if((mGame.board[i][0] == mGame.board[i][1]) && (mGame.board[i][1] == mGame.board[i][2])){
            //Se è uguale salvo il vincitore
		    mGame.winner = mGame.board[i][0];
            //Se vincitore è definito
            if(mGame.winner != NONE){
                //Restituisco partita terminata
		        return true;
            }
        }

	}
    //Nessuna combinazione vincente nelle righe
    return false;
}

//Controlla le colonne della partita per un vincitore
bool CheckCols(void) {

	int i;
	for(i = 0;i < 3;i++){
        //Controllo se la colonna è uguale
		if((mGame.board[0][i] == mGame.board[1][i]) && (mGame.board[1][i] == mGame.board[2][i])){
            //Se è uguale salvo il vincitore
		    mGame.winner = mGame.board[0][i];
            //Se è valore di default non è finita partita
            if(mGame.winner != NONE){
		        return true;
            }
        }
	}
    //Nessuna combinazione vincente sulle colonne
    return false;
}

//Controllo le due diagonali della griglia
bool CheckDiagonal(void){
    
    //Controllo la prima diagonale
	if(mGame.board[0][0] == mGame.board[1][1] && mGame.board[1][1] == mGame.board[2][2]){
        //Se le caselle sono uguali
		mGame.winner = mGame.board[0][0];
        //Se il vincitore non è il valore default
        if(mGame.winner != NONE)
		    return true;
	}

    //Controllo la seconda diagonale
	if(mGame.board[0][2] == mGame.board[1][1] && mGame.board[1][1] == mGame.board[2][0]){
		
        mGame.winner = mGame.board[0][2];
		//Se il vincitore non è il valore default
        if(mGame.winner != NONE)
		    return true;
	}

    //Nessuna corrispondenza
    return false;
}

/*  Controllo che sia uno stallo - nessun vincitore
*/
bool isDraw(void){
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){

            //Controllo se la casella non ha il valore default
            if(mGame.board[i][j] == NONE)
                return false;
        }
    }

    //Controllato tutte le caselle siano state riempite senza un vincitore
    mGame.winner = DRAW;
    return true;
}