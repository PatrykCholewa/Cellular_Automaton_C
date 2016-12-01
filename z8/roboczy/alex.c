
#include "alex.h"

#include <ctype.h>
#include <string.h>

static int  ln= 0;
static char ident[256];
static FILE *ci= NULL;

void    alex_init4file( FILE *in ) {
   ln= 0;
   ci= in;
}

int isKeyword( char *slowo){
	int a;
	a = 0;
	if (strcmp(slowo, "auto") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "break") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "case") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "char") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "const") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "continue") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "default") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "do") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "double") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "else") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "enum") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "extern") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "float") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "for") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "goto") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "if") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "int") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "long") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "register") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "return") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "short") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "signed") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "sizeof") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "static") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "struct") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "switch") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "typedef") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "union") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "unsigned") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "void") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "volatile") == 0 ){
		a = 1;
	}
	if (strcmp(slowo, "while") == 0 ){
		a = 1;
	}
		
	return a;
}
lexem_t alex_nextLexem( void ) {
  int c;
  while( (c= fgetc(ci)) != EOF ) {
    if( isspace( c ) )
                        continue;
                else if( c == '\n' )
                        ln++;
    else if( c == '(' )
                        return OPEPAR;
    else if( c == ')' )
      return CLOPAR;
    else if( c == '{' )
                        return OPEBRA;
    else if( c == '}' )
                        return CLOBRA;
    else if( isalpha( c ) ) {
      int i= 1;
      ident[0] = c;
      while( isalnum( c= fgetc(ci) ) )
                                ident[i++] = c;
                        ident[i] = '\0';
      return isKeyword(ident) ? OTHER : IDENT;
                } else if( c == '"' ) {
      /* Uwaga: tu trzeba jeszcze poprawic obsluge nowej linii w trakcie napisu
         i \\ w napisie 
      */
      int cp = c;
                        while( (c= fgetc(ci)) != EOF && c != '"' && cp == '\\' ) {
                                cp = c;
      }
      return c==EOF ? EOFILE : OTHER; 
    } else if( c == '/' ) {
      /* moze byc komentarz */
                } if( isdigit( c ) || c == '.' ) {
      /* liczba */
                } else {
      return OTHER;
                }
        }       
  return EOFILE;
}

char *  alex_ident( void ) {
   return ident;
}

int     alex_getLN() {
        return ln;
}

