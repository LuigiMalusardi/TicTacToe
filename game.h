#ifndef GAME
#define GAME

#include <stdbool.h>

extern char game[3][3];
extern int EmptySpace;
extern char player;
extern char winner;
extern bool end;

// Funzioni
void draw();	// Disegna partita
void playerSwitch();	// Cambia giocatore
void getInput();	// Prende input da tastiera e cambia il valore della partita
bool win();	// Controlla le condizioni di vittoria
void gameStatus();	// Riporta lo stato della partita

#endif
