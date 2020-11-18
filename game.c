#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

// Variabili
char game[3][3] = {' '};
int EmptySpace = 9;
char player = 'X';
char winner = ' ';
bool end;

//FUNZIONI

//Disegna la grafica
void draw(){
	
	//Pulisco schermo
	system("cls");
	
	int i,j;
	for(i = 0;i < 3;i++){	
		for(j = 0;j < 3;j++){
			if(j != 2){
				printf("%2c |",game[i][j]);
			}else{
				printf("%2c ",game[i][j]);
			}
		}
		if(i != 2){
			printf("\n---|---|---\n");
		}else{
			printf("\n");
		}
	}
}

//Cambia il giocatore che sta giocando
void playerSwitch(){
	
	if(player == 'X'){
		player='O';
	}else{
		player='X';
	}
}

//Prende l'input del giocatore e se è uno spazio vuoto fa la mossa
void getInput(){
	int choice,row,col;
	scanf("%d",&choice);
	switch(choice){
	case 1:
	case 2:
	case 3:
		row = 2;
		break;
	case 4:
	case 5:
	case 6:
		row = 1;
		break;
	default: 
		row = 0;
		break;
	}
	switch(choice){
	case 7:
	case 4:
	case 1:
		col = 0;
		break;
	case 8:
	case 5:
	case 2:
		col = 1;
		break;
	default: 
		col = 2;
		break;
	}
	if(game[row][col] == ' '){
	game[row][col] = player;
	EmptySpace--;
	playerSwitch();
	}
}

//Controlla se un giocatore ha vinto
bool win(){
	// controllo righe
	int i;
	for(i = 0;i < 3;i++){
		if(game[i][0] != ' '){
		if(game[i][0] == game[i][1] && game[i][1] == game[i][2]){
			winner = game[i][0];
			return true;
		}
	}
	}
	// controllo colonne
	int j;
	for(j = 0;j < 3;j++){
		if(game[0][j] != ' '){
	if(game[0][j] == game[1][j] && game[1][j] == game[2][j]){
		winner = game[0][j];
		return true;
		}
	}
	}
	// controllo diagonali
		if(game[0][0] != ' '){
	if(game[0][0] == game[1][1] && game[1][1] == game[2][2]){
		winner = game[0][0];
		return true;
		}
	}
	if(game[0][2] != ' '){
	if(game[0][2] == game[1][1] && game[1][1] == game[2][0]){
		winner = game[0][2];
		return true;
		}
	}
	if(EmptySpace == 0){
		winner = 'N';
		return true;
	}
	return false;
}

//Identifica lo stato di avanzamento del gioco
void gameStatus(){
	if(winner != ' '){
		if(winner == 'N')printf("\n\n   DRAW! \n");
	else printf("\n\n   %c is the winner! \n",winner);
	} else printf("\n %c playing... ",player);
}

//Conta le mosse rimanenti
int fMove(){
	int moves = 0;
	int i,j;
	for(i = 0;i < 3;i++){
		for(j = 0;j < 3;j++){
			if(game[i][j] = ' ')moves++;
	}
}
return moves;
}
