#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "struct.h"

#define BUF_SIZE 1024 

cool_t Yalloc( cool_t cool_data ){
	
	cool_data->Y = malloc( 2 * sizeof (*cool_data->Y));

	cool_data->Y[0] = malloc( ( cool_data->Yc + 1 ) * sizeof (cool_data->Y[0] ));
	cool_data->Y[1] = malloc( ( cool_data->Yc + 1 ) * sizeof (cool_data->Y[1] ));
	
	return cool_data;
}

cool_t startalloc( cool_t cool_data , int max_iter ){

	cool_data = malloc(sizeof(*cool_data));
	
	cool_data->stale.A = 0.0109;
	cool_data->stale.h = 50;
	cool_data->stale.mb = 0.4;
	cool_data->stale.mw = 2.5;
	cool_data->stale.cb = 0.22;
	cool_data->tend = 0.4;
	cool_data->tempend = 200;
	cool_data->Yc = 1000;
	cool_data->dt = 0.001;	

	return cool_data;
}

cool_t add_const( cool_t cool_data , FILE *in ){
	
	cool_data->Y[1][0] = 65;
	cool_data->Y[0][0] = 1200;

	char s[BUF_SIZE];
	double v;

	while( fscanf( in , "%s = %lf" , s , &v) != EOF ){
		if( strcmp( s , "A" ) == 0 ){
			cool_data->stale.A = v;
		}
		if( strcmp( s , "mb" ) == 0 ){
			cool_data->stale.mb = v;
		}
		if( strcmp( s , "mw" ) == 0 ){
			cool_data->stale.mw = v;
		}
		if( strcmp( s , "cb" ) == 0 ){
			cool_data->stale.cb = v;
		}
		if( strcmp( s , "h" ) == 0 ){
			cool_data->stale.h = v;
		}
		if( strcmp( s , "tend" ) == 0 ){
			cool_data->tend = v;
		}
		if( strcmp( s , "tempend" ) == 0 ){
			cool_data->tempend = v;
		}
		if( strcmp( s , "tempb" ) == 0 ){
			cool_data->Y[0][0] = v;
		}
		if( strcmp( s , "tempw" ) == 0 ){
			cool_data->Y[1][0] = v;
		}
	}

	// obsługa błędów

	return cool_data;
}

cool_t cw_gen( cool_t cool_data , char *cwplot ){

	int i;
	FILE *in = fopen( cwplot , "r" );
	cool_data->cw = malloc( 2 * sizeof (*cool_data->cw));

	cool_data->cw[0] = malloc( ( cool_data->Yc + 1 ) * sizeof (cool_data->cw[0] ));
	cool_data->cw[1] = malloc( ( cool_data->Yc + 1 ) * sizeof (cool_data->cw[1] ));

	for( i = 0 ; i <= cool_data->Yc ; i++ ){
	
		fscanf( in , "%lf %lf" , &(cool_data->cw[0][i]) , &(cool_data->cw[1][i]));

	}

	return cool_data;

}

		
		
