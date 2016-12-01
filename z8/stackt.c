#include<stdio.h>
#include<stdlib.h>
#include "fun_stack.h"

int main (int argc, char ** argv){
	int i;
	for( i = 1; i < argc; i+=2){
		put_on_fun_stack ( argv[i], argv[i+1] );
	}
	for(i = 1; i < argc; i+=2){
		printf(" %s\n", get_from_fun_stack());
	}
	return EXIT_SUCCESS;
}	
