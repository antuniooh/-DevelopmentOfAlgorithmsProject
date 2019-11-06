#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "menu.h"


int menu(){
    puts("=================================");
    puts("Menu de opcoes");
    puts("=================================");
    puts("1 - Inserir");
    puts("2 - Relatorio de Movimentos");
    puts("3 - Saldo");
    puts("4 - Remover dados");
    puts("5 - Extrato");
    puts("");
    puts("0 - Sair");
    int operacao;
    printf("Opcao > ");
    scanf(" %d",&operacao);
    return operacao;
}