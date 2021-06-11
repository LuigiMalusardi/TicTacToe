#ifndef STRUCTURES
#define STRUCTURES

//Enum gamemode
typedef enum {
    UNDEFINED,
    PLAYER_VS_PLAYER,
    PLAYER_VS_PC
} game_mode_enum;

//Enum giocatori
typedef enum {
    NONE        = 32,   //spazio
    PLAYER_1    = 88,   //X
    PLAYER_2    = 79,   //O
    DRAW        = 68    //DRAW
} player_enum;

// Struttura gioco
typedef struct {
    player_enum board[3][3];
    int score_p1;
    int score_p2;
    player_enum playing_player;
    player_enum winner;
} game_struct;



#endif