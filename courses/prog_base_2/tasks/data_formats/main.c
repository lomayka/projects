#include <stdio.h>
#include <stdlib.h>
#include "struct.h"




// gcc main.c cJSON.c -lm
int main() {
	FILE * fr = fopen("Programmers.json", "r");
    char text[10000];
    char line[100];
    int size = 3;
    programmer * p[size];            // create array of struture pointers

    for (int i = 0; i < size; i++){ // fill it
    p[i] = progr_create();
    }
    while(fgets(line, 100, fr) != NULL) {  // read file
        strcat(text, line);
    }
	parse(text,p);                         // to parse json file
	for (int i = 0; i < size; i++){       // to print array of structure
    printf("Programmer %d:\n",i+1);
	prog_print(p[i]);
	}
	for (int i = 0; i < size; i++){
    progr_free(p[i]);
    }
	return 0;
}
