/*
typedef struct{
	int **pozycje;
	char **slowa;
	int *liczba_wystapien;
	int ile_slow;
}skorowidz_t;
*/

void wypisz_skorowidz( skorowidz_t *skorowidz){
	int i;
	for (i = 0 ; i < skorowidz->ile_slow ; i++){
		if(skorowidz -> liczba_wystapien[i] != 0){
			printf("Słowo \"%s\" występuje w liniach: ", skorowidz->slowa[i]);
			int j;
			for(j = 0 ; j < skorowidz->liczba_wystapien[i] ; j++){
				printf("%d, ", skorowidz->pozycje[i][j]);
			}
			printf(".\n");
		}else{
			printf("Nie napotkano słowa \"%s\".\n", skorowidz->slowa[i]);
		}
	}
	return ;
}
	
		
	
