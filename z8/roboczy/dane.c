/*#include "dane.h"
#include <stdio.h>

void store_add_def ( char *funame, int ln, char * inpname){
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

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dane.h"

typedef struct l {
        char *name;
        int from;
        int to;
        struct l *next;
}*list_t;

typedef struct cont{
        char *fun_name;
        list_t def;
        list_t prot;
        list_t use; 
        struct cont *next;
}*store_t;

store_t dane = NULL;


int fun_position(char *funame, store_t s) {
        int i=-1;
        store_t tmp ;
        tmp = s;
        while(tmp != NULL) {
                i++;
                if(strcmp(tmp->fun_name, funame) == 0)
                        return i;
                tmp = tmp->next;
        }
        return -1;
}

void add_list_pos(char *name, int from, int to, list_t l) {
        list_t x = malloc(sizeof x);
        if(x != NULL) {
                x->name=name;
                x->from = from;
                x->to = to;
                x->next = l;
                l = x;
        }
}

void store_add_def(char *funame, int ln, char *inpname) {
        int position = fun_position(funame, dane);
        if(position==-1) {
                store_t x = malloc(sizeof x);
                x->fun_name = funame;
                add_list_pos(inpname, 0 , ln, x->def);
                x->prot = NULL;
                x->use = NULL;
                x->next = dane;
                dane = x;
        }else {
                store_t x = dane;
                int i;
                for(i=0; i<position; i++)
                        x = x->next;
                add_list_pos(inpname,0 , ln, x->def);
        }
}

void store_add_proto(char *funame, int ln, char *inpname) {
        int position = fun_position(funame, dane);
        if(position==-1) {
                store_t x = malloc(sizeof x);
                x->fun_name = funame;
                add_list_pos(inpname,0, ln, x->prot);
                x->def = NULL;
                x->use = NULL;
                x->next = dane;
                dane = x;
        }else {
                store_t x = dane;
                int i;
                for(i=0; i<position; i++)
                        x = x->next;
                add_list_pos(inpname,0, ln, x->prot);
        }

}


void store_add_call(char *funame, int ln, char *inpname) {
        int position = fun_position(funame, dane);
        if(position==-1) {
                store_t x = malloc(sizeof x);
                x->fun_name = funame;
                add_list_pos(inpname,0, ln, x->use);

                x->prot = NULL;
                x->def = NULL;
                x->next = dane;
                dane = x;
        }else {
                store_t x = dane;
                int i;
                for(i=0; i<position; i++)
                        x = x->next;
                add_list_pos(inpname,0 , ln, x->use);

        }
}

void print_store( void ) {
	
        printf("\nSegmentation fault (core dumped)\n");

        // Po co sie ma system operacyjny przemeczac... Zrobie to za niego :)
}

