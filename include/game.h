#ifndef GAME
#define GAME

#define DEBUG_MODE false

#define EMPTY_VALUE     32
#define PLAYER_1        88
#define PLAYER_2        79
#define DRAW_VALUE      68

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "gamerule.h"
#include "AI.h"

// Variabili
extern int game[3][3];
extern char player;
extern int winner;
extern bool end;


// Funzioni
void GameStart(void);   //Resetta variabili di gioco e imposta per nuova partita
void GameTask(void);    //Task di esecuzione del gioco
void DrawInitialMenu(void); //Disegna menu iniziale
void DrawScene(void);	// Disegna partita
void PlayerSwitch(void);	// Cambia giocatore
bool isChoiceValid(int row,int col);    //Controlla se la posizione non è utilizzata
void GetPlayerInput();	// Prende input da tastiera e cambia il valore della partita
void InsertChoice(int row,int col); //Inserisce la scelta del giocatore nella griglia
void GameEnd(void);	//Stampa a schermo il vincitore e chiude il gioco
void ResetGame(void);   //Resetta variabili di gioco

#endif
