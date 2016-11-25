#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"

typedef struct e{
        int par_level;
        char *funame;
        struct e *poprz;
}elem_t, *wierzcholek_t;

wierzcholek_t sztos;

int
top_of_funstack( void ) {
        if(sztos != NULL)
                return sztos->par_level;
        return 0;
}

void
put_on_fun_stack(int par_level, char *funame) {

        if(sztos == NULL) {
                sztos = malloc(sizeof (wierzcholek_t));

        }

}

char *get_from_fun_stack( void ) {


        return '\0';
}

