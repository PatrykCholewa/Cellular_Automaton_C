#include "struct.h"
#include<stdio.h>
#include<stdlib.h>

void generuj( cool_t cool_data ){

	FILE *out1 = fopen( "myplot1" , "w" );
	FILE *out2 = fopen( "myplot2" , "w" );
	int i;

	for( i = 0 ; i <= cool_data->Yc ; i++ ){
		
		fprintf( out1 , "%lf %lf\n" , cool_data->dt * i , cool_data->Y[0][i] );
		fprintf( out2 , "%lf %lf\n" , cool_data->dt * i , cool_data->Y[1][i] );

	}

	return ;
}
