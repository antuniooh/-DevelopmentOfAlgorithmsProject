#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../include/user.h"
#include "../include/inserir.h"

struct Usuario{
    char nome[200];
    long long int CPF ;
    float saldo;
    int senha;
};


struct Usuario retornaUsuario() {
    struct Usuario u;

    char nome[100];
    long long int CPF ;
    float saldo;
    int senha;

    FILE *fileUser = fopen("user.txt", "r+");

    //fscanf(fileUser," %s",nome);
    fgets(nome, 100 ,fileUser);
    tiraEnter(nome);
    fscanf(fileUser,"%lld",&CPF);
    fscanf(fileUser,"%f",&saldo);
    fscanf(fileUser,"%d",&senha);

    strcpy(u.nome, nome);
    u.CPF = CPF;
    u.saldo = saldo;
    u.senha = senha;

    return u;
}

void criaUsuario(FILE *p, struct Usuario* u){

    puts("=================");
    puts("Criacao de Conta");
    puts("=================");
    puts("Qual o seu nome? ");
    fgets(u->nome, 200, stdin);
    fflush(stdin);
    puts("Qual seu CPF? (so numeros)");
    scanf("%lld", &u->CPF);
    fflush(stdin);
    u->saldo = 0.0;
    puts("Qual a sua senha? (so numeros)");
    fflush(stdin);
    scanf("%d", &u->senha);
    fflush(stdin);

    fprintf(p, "%s", u->nome);
    fprintf(p, "%lld\n", u->CPF);
    fprintf(p, "%f\n", u->saldo);
    fprintf(p, "%d\n", u->senha);

    fclose(p);
}

void atualizarUser(float r,struct Usuario* u,FILE* p_user){
    u->saldo += r;
    remove("user.txt");

    p_user = fopen("user.txt", "a");

    fprintf(p_user, "%s\n", u->nome);
    fprintf(p_user, "%lld\n", u->CPF);
    fprintf(p_user, "%f\n", u->saldo);
    fprintf(p_user, "%d\n", u->senha);

    fclose(p_user);


}