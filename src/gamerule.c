#include "gamerule.h"

/*  Controlla se la partita è finita e se c'è un vincitore
*/
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

/*  Controlla le righe della partita per un vincitore
*/
bool CheckRows(void){

	int i;
	for(i = 0;i < 3;i++){

        //Controllo se la riga è uguale
		if((game[i][0] == game[i][1]) && (game[i][1] == game[i][2])){
            //Se è uguale salvo il vincitore
		    winner = game[i][0];
            //Se è valore di default non è finita partita
            if(winner == EMPTY_VALUE)
                continue;
            //Restituisco partita terminata
		    return true;
		 } else {
            //La riga non è uguale
            continue;
        }

	 }
    //La prima casella non è stata ancora scelta
    return false;
}

/*  Controlla le colonne della partita per un vincitore
*/
bool CheckCols(void) {

	int i;
	for(i = 0;i < 3;i++){
        //Controllo se la colonna è uguale
		if((game[0][i] == game[1][i]) && (game[1][i] == game[2][i])){
            //Se è uguale salvo il vincitore
		    winner = game[0][i];
            //Se è valore di default non è finita partita
            if(winner != EMPTY_VALUE){
		        return true;
            }
        }
	}
    //La prima casella non è stata ancora scelta
    return false;
}

/* Controllo le due diagonali della griglia
*/
bool CheckDiagonal(void){
    

    //Controllo la prima diagonale
	if(game[0][0] == game[1][1] && game[1][1] == game[2][2]){
        //Se le caselle sono uguali
		winner = game[0][0];
        //Se il vincitore non è il valore default
        if(winner != EMPTY_VALUE)
		    return true;
	}

    //Controllo la seconda diagonale
	if(game[0][2] == game[1][1] && game[1][1] == game[2][0]){
		
        winner = game[0][2];
		//Se il vincitore non è il valore default
        if(winner != EMPTY_VALUE)
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
            if(game[i][j] == EMPTY_VALUE)
                return false;
        }
    }

    //Controllato tutte le caselle siano state riempite senza un vincitore
    winner = DRAW_VALUE;
    return true;
}