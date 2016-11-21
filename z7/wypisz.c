/*
typedef struct{
	int **pozycje;
	char **slowa;
	int *liczba wystapien;
}skorowidz_t;
*/

void wypisz_skorowidz(int argc, skorowidz_t *skorowidz){
	int i;
	for (i = 0; i < argc - 2, i++){
		if(skorowidz->liczba_wystapien[i] != 0){
			printf("Słowo \"%s\" występuje w liniach: ", skorowidz->slowa[i]);
			int j;
			for(j=0; j<skorowidz->liczba_wystapien[i]; j++){
				printf("%d, ", skorowidz->pozycje[i][j]);
			}
		}else{
			printf("Nie napotkano słowa \"%s\".", skorowidz->slowa[i]);
		}
		printf("\n");
	}
	return ;
}
	
		
	
