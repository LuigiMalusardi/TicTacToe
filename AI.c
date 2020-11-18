

int MinMax(){
}
// cerca il minimo risultato possibile
int Min(){
	int minscore = -99999999;
	int score;
	int i,j,k;
	for(k = 0; k < FMove();k++){
		for(i = 0;i < 3;i++){
			for(j = 0;j < 3;j++){
				if(game[i][j] = ' '){
					game[i][j] = 'X';
					Max();
					game[i][j] = ' ';
					minscore = minscore < score ? minscore : score;
					return minscore;
				}
			}
		}
	}
}
// cerca il maggior risultato possibile
int Max(){
	int maxscore = -99999999;
	int score;
	int k,i,j;
	for(k = 0; k < FMove();k++){
		for(i = 0;i < 3;i++){
			for(j = 0;j < 3;j++){
				if(game[i][j] = ' '){
					game[i][j] = 'O';
					Min();
					game[i][j] = ' ';
					maxscore = maxscore > score ? maxscore : score;
					return maxscore;
				}
			}
		}
	}
}
