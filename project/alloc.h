#include<stdlib.h>
#include<stdio.h>
#include "struct.h"

cool_t startalloc (cool_t cool_data );

cool_t Yalloc( cool_t cool_data );
	/** 
	  * allokuje cool_data->Y (**Y)
	  * cool_data->Yc to liczba kolumn ( bez jednej )
	  */

cool_t add_const( cool_t cool_data , FILE *in );

/**
  *Dodanie danych do stale z pliku in
  */
