#ifndef AI
#define AI

#define WIN_SCORE 1
#define LOSE_SCORE -1
#define DRAW_SCORE  0

#include "game.h"
#include <limits.h>

int AIPlay(void);
int minmax_algo(int depth,bool isAiTurn);



#endif