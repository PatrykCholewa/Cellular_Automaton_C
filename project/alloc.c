#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "struct.h"

#define BUF_SIZE 1024 

cool_t alloc( cool_t cool_data ){
	
	cool_data = malloc( sizeof(*cool_data));
	
	/**
	  * alloc dla **Y
	  */
	
	return cool_data;
}

cool_t add_const( cool_t cool_data , FILE *in ){
	
	char s[BUF_SIZE];
	double v;
	char c;
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
	}
	return cool_data;
}
		
		
