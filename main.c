#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "include/menu.h"
#include "include/user.h"
#include "include/inserir.h"
#include "include/remover.h"
#include "include/categoria.h"
#include "include/extrato.h"


struct Usuario{
    char nome[200];
    long long int CPF ;
    float saldo;
    int senha;
};

int main() {
    struct Usuario u;
    FILE *p_user = fopen("user.txt", "r");;

    if(p_user == NULL)
    {
        p_user = fopen("user.txt", "a+");
        criaUsuario(p_user, &(u));
        main();
    }
    else {
        while (1) {
            struct Usuario a = retornaUsuario();
            FILE *pont_arq;
            pont_arq = fopen("MyPersonalWallet.txt", "a+");
            printf("Seja bem-vindo %s\n",a.nome);
            int op = menu();
            if (op == 1) {
                Inserir(pont_arq, p_user, &a);
            } else if (op == 2) {
                Imprime(pont_arq);
            } else if (op == 3) {
                printf("Seu saldo atual é: %f\n", a.saldo);
            } else if (op == 4) {
                Remover(pont_arq, p_user);
                p_user = fopen("user.txt", "a+");
            }else if(op == 5){
                Extrato(pont_arq);
                printf("Seu saldo atual é: %f\n", a.saldo);
              }
            else if (op == 0) {
                puts("Fechando o sistema....");
                fclose(p_user);
                fclose(pont_arq);
                break;
            } else {
                puts("Operacao Invalida, fechando o sistema....");
                fclose(p_user);
                fclose(pont_arq);
                break;
            }
        }
    }

    return 0;
}