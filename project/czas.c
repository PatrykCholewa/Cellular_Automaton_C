#include "struct.h"
#include "czas.h"
#include <stdlib.h>
#include <stdio.h>
double cw( cool_t cool_data , int index){

	int i;

	for(i = 0 ; cool_data->Y[1][index] < cool_data->cw[0][i] ; i++ ){
		;
	}

	return cool_data->cw[1][i];
}

cool_t przebiegnij( cool_t cool_data){

	int i;

	for(i = 1 ; i <= cool_data->Yc ; i++){
	
	cool_data->Y[0][i] = cool_data->Y[0][i - 1] + cool_data->dt * ( ( cool_data->Y[1][i - 1] - cool_data->Y[0][i - 1]) * cool_data->stale.h * cool_data->stale.A / cool_data->stale.mb / cool_data->stale.cb );

	cool_data->Y[1][i] = cool_data->Y[1][i - 1] + cool_data->dt * ( ( cool_data->Y[0][i - 1] - cool_data->Y[1][i - 1]) * cool_data->stale.h * cool_data->stale.A / cool_data->stale.mw / cw(cool_data , i-1) );

	}	

	return cool_data;
}
