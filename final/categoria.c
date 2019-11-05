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
    int index = 0, bool=0;


    while ( 1 ) {
        c = getc(file);
        if ( c != '\n'){
            line[index++] = c;
        }
        else {

            if(verifica(line, categoria, index, strlen(categoria))) {
                bool=1;
                printf("%s\n", line);
            }
            line[index] = '\0';
            index = 0;

            memset(line, 0, sizeof(line));


        }
        if( c == EOF){
            break;
        }

    }
    if(bool == 0){
        printf("Categoria nao encontrada\n");
    }
}

void Anual(FILE *MyPersonalWallet, char *ano){
    int bool=0;
    char vetor[50000], v2[10];

    while(fgets(vetor, sizeof(vetor), MyPersonalWallet)){


        for (int i = 13, j=0; vetor[i] != ' '; ++i, j++) {

            v2[j] = vetor[i];
        }
        if(strcmp(v2, ano) == 0){
            bool=1;
            printf("%s\n", vetor);
        }

    }
    if(bool == 0){
        printf("Ano nao encontrado\n");
    }
}

void Imprime(FILE *file){
    puts("Voce deseja ver o relatorio anual ou por categoria?");
    int op;
    puts("1 - Anual");
    puts("2 - Categoria");
    printf("Opcao > ");
    scanf("%d", &op);
    while (op > 2 && op <= 0) {
        puts("Digite um comando valido");
        scanf("%d", &op);
    }
    puts("=================================");

    if(op == 1){
        char ano[10];
        int num=0;
        printf("Digite o ano: ");
        scanf("%s", ano);
        num = atoi(ano);

        while(num <=0 || num >2019){
            printf("Digite o ano corretamente\n");
            scanf("%s", ano);
            num = atoi(ano);
        }
        Anual(file, ano);
    }else{
        puts("Digite o nome da categoria a ser pesquisada");
        char categoriaR[100];
        scanf("%s", categoriaR);
        while ((strcmp(categoriaR, "Moradia") !=0) && (strcmp(categoriaR, "Estudos") != 0) &&
               (strcmp(categoriaR, "Alimentacao") != 0) && (strcmp(categoriaR, "Transporte") != 0) &&
               (strcmp(categoriaR, "Trabalho") != 0))
        {
            puts("Digite uma categoria valida");
            scanf("%s", categoriaR);
        }
        ImprimeCategoria(file, categoriaR);

    }
}
