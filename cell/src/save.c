#include "save.h"

int scale(int m, int n) {
	if(m*n<=400) {
		return 5;
	}
	if(m*n<=15000) {
		return 3;
	}
	return 1;
}

int numOfDigits(int n) {
    int digits = 0;
    if(n == 0) {
        return 1;
    }
    while(n != 0) {
        n/=10;
        digits++;
    }
    return digits;
}

char* addNumToName(char *s) {
    static int number = 0;
    int i;
    int tmp = number;
    int digits = numOfDigits(number);
    char *ns = malloc((strlen(s)+digits+1)*sizeof (char));
    for(i=digits-1; i>=0; i--) {
        int d = tmp % 10;
        ns[i] = d+'0';
        tmp /= 10;
    }
    ns[digits] = '_';
    i = 0;
    while(s[i] != '\0') {
        ns[digits+i+1] = s[i];
        i++;
    }
    ns[digits+i+1] = '\0';
    number++;
    return ns;
}

char* createCommand(char *c) {
	char command_base[40] = "convert out/cellsim_output_tmp.pbm out/";
	char *command = malloc(strlen(command_base)+strlen(c)+1);
	strcpy(command, command_base);
	strcat(command, command_base);
	return command;
}

void save_scalex1(map_t map);
void save_scalex3(map_t map);
void save_scalex5(map_t map);

int save(map_t map) {
	static int first = 1;
	char *outFile;
	char *command;
	int scl;
	
	scl = scale(map->m, map->n);
	
	if(first == 1) {
		system("rm -R out");
		system("mkdir out");
		first = 0;
	}
	
	switch(scl) {
		case 1:
			save_scalex1(map);
			break;
		case 3:
            save_scalex3(map);
			break;
		case 5:
            save_scalex5(map);
			break;
	}

	outFile = addNumToName(map->cfg.out);
	command = createCommand(outFile);
	
	system(command);
	remove("out/cellsim_output_tmp.pbm");
	
	free(outFile);
	free(command);
	
	return 0;
}

void save_scalex1(map_t map) {
	int x, y;
	FILE *tmp_out = fopen("out/cellsim_output_tmp.pbm", "w");
	
	fprintf(tmp_out, "P1\n%d %d\n", map->m, map->n);
	
	for(y=0; y<map->n; y++) {
		for(x=0; x<map->m; x++) {
			fprintf(tmp_out, "%d ", map->board[x][y] == '\0' ? 0 : 1);
		}
		fprintf(tmp_out, "\n");
	}
	
	fclose(tmp_out);
}

void save_scalex3(map_t map) {
    int x, y;
    FILE *tmp_out = fopen("out/cellsim_output_tmp.pbm", "w");

    fprintf(tmp_out, "P1\n%d %d\n", 3*map->m, 3*map->n);

    for(y=0; y<map->n; y++) {
        for(x=0; x<map->m; x++) {
			int val = map->board[x][y] == '\0' ? 0 : 1;
            fprintf(tmp_out, "%d %d %d ", val, val, val);
        }
        fprintf(tmp_out, "\n");
        for(x=0; x<map->m; x++) {
            int val = map->board[x][y] == '\0' ? 0 : 1;
            fprintf(tmp_out, "%d %d %d ", val, val, val);
        }
        fprintf(tmp_out, "\n");
        for(x=0; x<map->m; x++) {
            int val = map->board[x][y] == '\0' ? 0 : 1;
            fprintf(tmp_out, "%d %d %d ", val, val, val);
        }
        fprintf(tmp_out, "\n");
    }
    
    fclose(tmp_out);
}

void save_scalex5(map_t map) {
    int x, y;
    FILE *tmp_out = fopen("out/cellsim_output_tmp.pbm", "w");

    fprintf(tmp_out, "P1\n%d %d\n", 5*map->m, 5*map->n);

    for(y=0; y<map->n; y++) {
        for(x=0; x<map->m; x++) {
            int val = map->board[x][y] == '\0' ? 0 : 1;
            fprintf(tmp_out, "%d %d %d %d %d ", val, val, val, val, val);
        }
        fprintf(tmp_out, "\n");
        for(x=0; x<map->m; x++) {
            int val = map->board[x][y] == '\0' ? 0 : 1;
            fprintf(tmp_out, "%d %d %d %d %d ", val, val, val, val, val);
        }
        fprintf(tmp_out, "\n");
        for(x=0; x<map->m; x++) {
            int val = map->board[x][y] == '\0' ? 0 : 1;
            fprintf(tmp_out, "%d %d %d %d %d ", val, val, val, val, val);
        }
        fprintf(tmp_out, "\n");
        for(x=0; x<map->m; x++) {
            int val = map->board[x][y] == '\0' ? 0 : 1;
            fprintf(tmp_out, "%d %d %d %d %d ", val, val, val, val, val);
        }
        fprintf(tmp_out, "\n");
        for(x=0; x<map->m; x++) {
            int val = map->board[x][y] == '\0' ? 0 : 1;
            fprintf(tmp_out, "%d %d %d %d %d ", val, val, val, val, val);
        }
        fprintf(tmp_out, "\n");
    }
    
    fclose(tmp_out);
}
