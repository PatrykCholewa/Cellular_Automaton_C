#include "struct.h"

double cw( cool_t cool_data){ 
	return 0.2;
}

cool_t przebiegnij( cool_t cool_data){

	int i;

	for(i = 1 ; i <= cool_data->Yc ; i++){

	cool_data->Y[0][i] = cool_data->Y[0][i - 1] + cool_data->stale.h * ( ( cool_data->Y[1][i - 1] - cool_data->Y[0][i - 1]) * cool_data->stale.h * cool_data->stale.A / cool_data->stale.mb / cool_data->stale.cb );

	cool_data->Y[1][i] = cool_data->Y[1][i - 1] + cool_data->stale.h * ( ( cool_data->Y[0][i - 1] - cool_data->Y[1][i - 1]) * cool_data->stale.h * cool_data->stale.A / cool_data->stale.mw / cw(cool_data) );

	}	

	return cool_data;
}
