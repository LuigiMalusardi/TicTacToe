#ifndef GAME
#define GAME

#include <stdbool.h>
#include <string.h>

#include "gamerule.h"
#include "interface.h"
#include "structures.h"
#include "AI.h"

// Funzioni
void GameInit(void);   
void GameTask(void);   
void PlayerSwitch(void);	
bool isChoiceValid(int choice);  
void GameEnd(void);	
void SetScore(player_enum winner);
void ResetGame(void);
void RestartGame(void);

int GetRow(int choice);
int GetColumn(int choice);

#endif
