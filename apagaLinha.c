#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main()
{
    FILE *fptr;
    FILE *file2;

    char v[1000], c;
    int cont=1, index=0;

    fptr = fopen("projeto.txt", "r");
    file2 = fopen("Projeto_Temp.txt", "w");

    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    memset(v, 0, sizeof(v));



    while (1)
    {
        c=fgetc(fptr);
        if(c == '\n')cont++;

        if(cont == 2){
            continue;
        }
        else {

            //printf("%c", c);
            v[index] = c;
            index++;
        }
        if(c == EOF){
            break;
        }

    }

    for (int i = 0; i < index-1; ++i) {
        fprintf(file2, "%c", v[i]);
    }

    fclose(fptr);
    fclose(file2);
    remove("projeto.txt");
    rename("Projeto_Temp.txt", "projeto.txt");


    return 0;
}
