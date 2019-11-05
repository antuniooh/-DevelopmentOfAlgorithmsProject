#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "menu.h"
#include "user.h"
#include "inserir.h"
#include "remover.h"
#include "categoria.h"

struct Usuario{
    char nome[200];
    int CPF ;
    float saldo;
    int senha;
};

int main() {
    struct Usuario u;
    FILE *p_user = fopen("user.txt", "a+");

    if(p_user == NULL)
    {
        //FILE *p_user = fopen("user.txt", "a+");
        criaUsuario(p_user, &(u));
        main();
    }
    else {
        while(1){
            struct Usuario a = retornaUsuario();
            FILE *pont_arq;
            pont_arq = fopen("MyPersonalWallet.txt", "a+");
            printf("Seja bem vindo %s\n", a.nome);

            int op = menu();
            if (op == 1) {
                Inserir(pont_arq, p_user, &a);
            } else if (op == 2) {
                puts("Digite o nome da categoria a ser pesquisada");
                char categoria[100];
                scanf("%s", categoria);
                ImprimeCategoria(pont_arq, categoria);
            } else if (op == 3) {
                printf("Seu saldo atual é: %f\n", a.saldo);
            } else if (op == 4) {
                ApagaLinha(pont_arq, p_user, 3);
                p_user = fopen("user.txt", "a+");
            }
            else if (op == 0) {
                puts("Fechando o sistema....");
                fclose(pont_arq);
                break;
            } else {
                puts("Operacao Invalida, fechando o sistema....");
                fclose(pont_arq);
                break;
            }
        }
    }

    return 0;
}