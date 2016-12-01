#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"

typedef struct e{
        int parlevel;
        char *fun_name;
        struct e *next;
}elem_t, *stack_t;

stack_t sztos;

int top_of_funstack( void ) {
        if(sztos == NULL)
		return 0;
	return sztos->parlevel;
}

void put_on_fun_stack(int par_level, char *funame) {
	
	elem_t *x = malloc(sizeof *x);
	if(x != NULL) {
		x->parlevel = par_level;
		x->fun_name = funame;
		x->next = sztos;
		sztos = x;
	}
}

char *get_from_fun_stack( void ) {
	
	elem_t *x = sztos;
	char *tmp = sztos->fun_name;
	sztos = x->next;
	free(x);
	return tmp;
}
