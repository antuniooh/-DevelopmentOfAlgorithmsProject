#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "categoria.h"


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
    fclose(file);
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
    fclose(MyPersonalWallet);
}


void ImprimeCategoriaMes(FILE *MyPersonalWallet){

    char vetor[10000], v2[20];
    int maiorAno=0, maiorMes=0, num=0, num2=0, index=0, cont=1;

    while(fgets(vetor, sizeof(vetor), MyPersonalWallet)){
        for (int i = 13, j=0; vetor[i] != ' '; ++i, j++) {

            v2[j] = vetor[i];
        }
        num = atoi(v2);
        if(num > maiorAno){
            maiorAno = num;
        }
        cont++;

    }


    memset(vetor, 0, sizeof(vetor)/sizeof(vetor[0]));
    num=0;
    num2=0;
    cont=1;

    rewind(MyPersonalWallet);

    while(fgets(vetor, sizeof(vetor), MyPersonalWallet)) {

        memset(v2, 0, sizeof(v2)/sizeof(v2[0]));
        for (int i = 10, j=0; i <= 11 ; ++i, j++) {
            v2[j] = vetor[i];
        }

        num=atoi(v2);

        memset(v2, 0, sizeof(v2)/sizeof(v2[0]));

        for (int i = 13, j=0; vetor[i] != ' '; ++i, j++) {
            v2[j] = vetor[i];
        }
        num2=atoi(v2);

        if(num2 == maiorAno){
            if(num > maiorMes){
                maiorMes=num;
            }
        }
    }


    memset(vetor, 0, sizeof(vetor)/sizeof(vetor[0]));

    rewind(MyPersonalWallet);

    while(fgets(vetor, sizeof(vetor), MyPersonalWallet)){

        memset(v2, 0, sizeof(v2)/sizeof(v2[0]));

        for (int i = 10, j=0; i <= 11 ; ++i, j++) {
            v2[j] = vetor[i];
        }
        num=atoi(v2);

        memset(v2, 0, sizeof(v2)/sizeof(v2[0]));

        for (int i = 13, j=0; vetor[i] != ' '; ++i, j++) {
            v2[j] = vetor[i];
        }
        num2=atoi(v2);

        if(num2 == maiorAno && num == maiorMes){
            printf("%s\n", vetor);
        }
    }
    fclose(MyPersonalWallet);
}

void Imprime(FILE *file){

  struct tm *data_hora_atual;     
  time_t segundos;
  time(&segundos);   
  data_hora_atual = localtime(&segundos); 

    puts("Voce deseja ver o relatorio anual ou por categoria?");
    int op;
    puts("1 - Anual");
    puts("2 - Categoria");
    printf("Opcao > ");
    scanf("%d", &op);
    while (op > 2 || op <= 0) {
        puts("Digite um comando valido");
        scanf("%d", &op);
    }
    puts("=================================");

    if(op == 1){

        puts("Voce deseja ver o relatorio do ultimo ano ou em um especifico?");
        int opcao;
        puts("1 - Ultimo");
        puts("2 - Especifico");
        printf("Opcao > ");
        scanf("%d", &opcao);
        while (opcao > 2 || opcao <= 0) {
          puts("Digite um comando valido");
          scanf("%d", &opcao);
          }
          puts("=================================");

          if(opcao == 1){
            int year = (data_hora_atual->tm_year+1900)-1;
            char ano1[20];
            sprintf(ano1,"%d",year); 
            printf("%s\n",ano1);
            Anual(file, ano1);
          }else{
            int num=0;
            char ano[10];
            printf("Digite o ano: ");
            scanf("%s", ano);
            num = atoi(ano);

        while(num <=0 || num >2019){
            printf("Digite o ano corretamente\n");
            scanf("%s", ano);
            num = atoi(ano);
        }
         Anual(file, ano);
        }
        
    }else{
        puts("Voce deseja ver o relatorio do ultimo mes ou de uma categoria especifica?");
        int option;
        puts("1 - Ultimo");
        puts("2 - Especifico");
        printf("Opcao > ");
        scanf("%d", &option);
        while (option > 2 || option <= 0) {
          puts("Digite um comando valido");
          scanf("%d", &option);
          }
         puts("=================================");


          if(option == 1){
             ImprimeCategoriaMes(file);
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
    fclose(file);
        }
}
