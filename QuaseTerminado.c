#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main()
{
    FILE *fptr;
    FILE *file2;

    char v[1000], c, v2[1000];
    int cont=1, index=0, index2=0;

    fptr = fopen("projeto.txt", "r");
    file2 = fopen("Projeto_Temp.txt", "w");

    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    memset(v, 0, sizeof(v));
    memset(v2, 0, sizeof(v2));

    while (1)
    {
        c = fgetc(fptr);
        if(c == '\n')cont++;
        else if(cont == 2){
            continue;
        }

        printf ("%c", c);
        v[index] = c;

        if(c == EOF){
            break;
        }
        index++;
    }

    printf("\nCont: %d\n", cont);

    printf("\n\n\nVetor: %s\n", v);


    for (int i = 0; i < index; ++i) {
        if( (v[i] == ' ' && v[i+1] == ' ') || (v[i] == ' ' && v[i+1] == '\n') ){
            continue;
        }
        else{
            v2[index2] = v[i];
            index2++;
        }
    }

    printf("\n\n\n\nVetor2: %s\n", v2);

    fclose(fptr);
    return 0;
}
