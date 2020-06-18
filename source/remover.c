#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../include/remover.h"
#include "../include/categoria.h"

void RemoverTudo(){
    remove("MyPersonalWallet.txt");
    remove("user.txt");

    printf("Historico de transacoes removidas\n");
    printf("Dados de usuario deletados\n");
    exit(0);

}

void ApagaLinha(FILE *MyPersonalWallet, FILE *user, const int num)
{
    FILE *file;
    FILE *file2;

    char v[1000], v2[1000], v3[1000], c;
    int cont=1, index=0, index2=0, bol=0;
    float transacao=0, saldo=0;

    file = fopen("MyPersonalWallet_Temp.txt", "w");
    file2 = fopen("user_Temp.txt", "w");

    memset(v, 0, sizeof(v)/sizeof(v[0]));
    memset(v2, 0, sizeof(v2)/sizeof(v2[0]));
    memset(v3, 0, sizeof(v3)/ sizeof(v3[0]));



    while (1)
    {
        c=fgetc(MyPersonalWallet);
        if(c == '\n')cont++;

        if(cont == 2){
            if(c == '+' || c == '-'){
                bol=1;
            }
            if(bol==1){
                v2[index2++] = c;
            }
            continue;
        }
        else {
            v[index] = c;
            index++;
        }
        if(c == EOF){
            break;
        }

    }
    v3[0] = v2[0];
    int j=3;

    while(v2[j] != ' '){
        v3[j-2] = v2[j];
        j++;
    }

    transacao = atof(v3);

    printf("T: %f\n", transacao);

    memset(v2, 0,sizeof(v2)/ sizeof(v2[0]));

    cont=1;

    while(fgets(v2, sizeof(v2), user)){


        printf("V2: %s\n", v2);

        if (cont == 3){
            saldo = atof(v2);
            printf("SALDO: %f\n", saldo);
            fprintf(file2, "%f\n", saldo+transacao);
        }
        else{
            fprintf(file2, "%s", v2);
        }
        cont++;


    }

    for (int i = 0; i < index-1; ++i) {
        fprintf(file, "%c", v[i]);
    }


    fclose(MyPersonalWallet);
    fclose(user);
    fclose(file);
    fclose(file2);
    remove("MyPersonalWallet.txt");
    remove("user.txt");
    rename("MyPersonalWallet_Temp.txt", "MyPersonalWallet.txt");
    rename("user_Temp.txt", "user.txt");


}

void Remover(FILE *MyPersonalWallet, FILE *user){

    int op=0;
    puts("Voce deseja remover uma transacao ou seus dados?");
    puts("1 - Transacao");
    puts("2 - Dados");
    printf("Opcao > ");
    scanf(" %d", &op);
    puts("=================================");
    if (op == 1) {
        puts("Qual o numero da transacao que deseja remover?");
        printf("Opcao > ");
        int num=0;
        scanf(" %d", &num);
        ApagaLinha(MyPersonalWallet, user, num);
    } else if (op == 2) {
        RemoverTudo();
    }
}