#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int verifica(char* v, char* quer, int tamPalavra, int tam){

    int i=0, j=0;

    for (i = 0; i < tamPalavra; ++i) {
        if (v[i] != ' ') {
            if (v[i] == quer[j]) {
                j++;
            }
        }
    }

    if(j == tam)
        return 1;
    j=0;

    return 0;

}

void ImprimeCategoria(FILE *file, char* categoria){
    char c;
    char line[100000];
    int index = 0;
    c = getc(file);

    while ( 1 ) {

        if ( c != '\n'){
            line[index++] = c;
        }
        else {

            if(verifica(line, categoria, index, strlen(categoria))) {
                printf("%s\n", line);
            }
            line[index] = '\0';
            index = 0;

            memset(line, 0, sizeof(line));


        }
        if( c == EOF){
            printf("%s\n", line);
            break;
        }

        c = getc ( file );
    }
}