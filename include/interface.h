#ifndef INTERFACE
#define INTERFACE

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "game.h"
#include "structures.h"

game_mode_enum DrawInitialMenu(void);
void DrawMainScene(void);
bool DrawEndScene(void);
int GetPlayerInput(void);

#endif