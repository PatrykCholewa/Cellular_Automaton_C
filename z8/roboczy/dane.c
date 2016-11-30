#include "dane.h"
#include <stdio.h>

void store_add_def ( char *funame /*function name*/ , int ln /*line number*/ , char * inpname){
	printf("DEF %s , %d , %s\n", funame, ln, inpname);
	return ;
}

void store_add_proto ( char * funame, int ln , char * inpname){
	printf("PROTO %s , %d , %s\n", funame, ln, inpname);
	return ;
}

void store_add_call ( char * funame, int ln, char * inpname){
	printf("CALL %s , %d , %s\n", funame, ln, inpname);
	return ;
} 
