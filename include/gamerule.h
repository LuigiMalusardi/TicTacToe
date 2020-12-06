#ifndef GAMERULE
#define GAMERULE

#include <stdbool.h>

#include "game.h"

bool isGameEnded(void);	// Controlla le condizioni di vittoria
bool CheckRows(void);   //Controlla righe della partita
bool CheckCols(void);   //Controlla colonne della partita
bool CheckDiagonal(void);   //Controlla diagonali della partita
bool isDraw(void);  //Controlla se è stallo


#endif