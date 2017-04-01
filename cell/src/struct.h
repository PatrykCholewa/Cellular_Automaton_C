#ifndef STRUCT_CONTROL
#define STRUCT_CONTROL


typedef struct {
	int nbrhd;	   /* 	typ sąsiedztwa (4,8,/inne/) */
	int bound;	   /*	typ warunków brzegowych (0,1,/inne/)
			   */
	int save; 	   /*  sposób zapisu (1,/więcej/) */
	char *out;	   /* nazwa pliku wyjścia */
	int intrvl;	   /* interwał czasowy */
	char live;	   /* czy na żywo */
} cfg_t;

typedef struct {
	char **board; 	   /*	wiersze tablicy to wiersze komórek
 				kolumny tablicy zawierają indeksy
				kolumn komórek wierszy
				zerowy wiersz zawiera
				tablica jest mxn
			   */
	char **old_board;  /* 	jak wyżej tylko dla poprzedniej generacji */
	int m;		   /* 	ilość wierszy planszy */
	int n;		   /* 	ilość kolumn planszy */
	cfg_t cfg;
} *map_t;

#endif
