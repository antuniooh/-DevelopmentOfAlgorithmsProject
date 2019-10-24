#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Receita{
    struct Data data;
    float valor;
    char categoria[200];
};

struct Usuario{
    char nome[200];
    int CPF ;
    float saldo;
    int senha;
};

int menu(){
    puts("=================");
    puts("Menu de opcoes");
    puts("=================");
    puts("1 - Inserir");
    puts("2 - Remover");
    puts("3 - Relatorio de Movimentos");
    puts("");
    puts("0 - Sair");
    int operacao;
    printf("Opcao > ");
    scanf(" %d",&operacao);
    return operacao;
}

void Inserir (FILE *p, FILE* p_user, struct Usuario* u) {
    struct Receita r;

    int senha;
    puts("=================================");
    puts("Necessario a senha para fazer movimentacoes! ");
    scanf("%d", &senha);

    if (senha == (u->senha)) {
        printf("A senha esta correta\n");
        int op;
        puts("Voce deseja inserir uma receita ou um gasto?");
        puts("1 - Receita");
        puts("2 - Gasto");
        printf("Opcao > ");
        scanf(" %d", &op);

        puts("Qual o valor? ");
        float valor;
        scanf(" %f", &valor);
        while (valor <= 0) {
            puts("Digite um valor valido");
            scanf("%f", &valor);
        }
        puts("Qual a data? (dd mm aaaa)");
        int dia, mes, ano;
        scanf("%d %d %d", &dia, &mes, &ano);
        while ((dia <= 0 || dia >= 32) || (mes <= 0 || mes >= 13) || (ano <= 0)) {
            puts("Digite uma data valida");
            scanf("%d %d %d", &dia, &mes, &ano);
        }
        puts("Qual a categoria?: (Moradia, Estudos, Transporte, Alimentacao, Trabalho)");
        char categoria[200];
        memset(categoria, 0, sizeof(categoria)/ sizeof(categoria[0]));
        fflush(stdin);
        fgets(categoria, 200, stdin);
        while (strcmp(categoria, "Moradia") != 0 && strcmp(categoria, "Estudos") != 0 &&
               strcmp(categoria, "Alimentacao") != 0 && strcmp(categoria, "Transporte") != 0 &&
               strcmp(categoria, "Trabalho") != 0) {
            puts("Digite uma categoria valida");
            fgets(categoria, 200, stdin);
        }
        r.valor = valor;
        r.data.dia = dia;
        r.data.mes = mes;
        r.data.ano = ano;
        strcpy(r.categoria, categoria);

        fprintf(p, "%s", "Data: ");
        fprintf(p, " %d/%d/%d ", r.data.dia, r.data.mes, r.data.ano);
        if (op == 1) {
            fprintf(p, "%s", " + ");
        } else if (op == 2) {
            fprintf(p, "%s", " - ");
        }
        fprintf(p, " %f ", r.valor);
        fprintf(p, " %s", r.categoria);

        puts("Transacao cadastrada com sucesso !");
    } else {
        printf("As senhas nao coincidem\n");
        menu();
    }
}

void criaUsuario(FILE *p, struct Usuario* u){

    puts("=================");
    puts("Criacao de Conta");
    puts("=================");
    puts("Qual o seu nome? ");
    fgets(u->nome, 200, stdin);
    fflush(stdin);
    puts("Qual seu CPF? *so numeros");
    scanf("%d", &u->CPF);
    fflush(stdin);
    u->saldo = 0.0;
    puts("Qual a sua senha? (deve ter 4 digitos)");
    fflush(stdin);
    scanf("%d", &u->senha);
    fflush(stdin);

    fprintf(p, "%s", u->nome);
    fprintf(p, "%d\n", u->CPF);
    fprintf(p, "%f\n", u->saldo);
    fprintf(p, "%d\n", u->senha);

    fclose(p);
}

struct Usuario retornaUsuario() {
    struct Usuario u;

    char nome[100];
    int CPF;
    float saldo;
    int senha;

    FILE *fileUser = fopen("user.txt", "r");

    fscanf(fileUser," %s",&nome);
    fscanf(fileUser," %d",&CPF);
    fscanf(fileUser," %f",&saldo);
    fscanf(fileUser," %d",&senha);

    strcpy(u.nome, nome);
    u.CPF = CPF;
    u.saldo = saldo;
    u.senha = senha;

    return u;
}

int main() {
    struct Usuario u;
    FILE *p_user = fopen("user.txt", "r");;

    if(p_user == NULL)
    {
        p_user = fopen("user.txt", "a");
        criaUsuario(p_user, &(u));
        main();
    }
    else {
        struct Usuario a = retornaUsuario();
        FILE *pont_arq;
        pont_arq = fopen("financas.txt", "a");

        while (1) {
            int op = menu();
            if (op == 1) {
                Inserir(pont_arq, p_user, &a);
            } else if (op == 2) {
                // Remover();
            } else if (op == 3) {

            } else if (op == 0) {
                puts("Fechando o sistema....");
                fclose(pont_arq);
                break;
            } else {
                puts("Operação Inválida, fechando o sistema....");
                fclose(pont_arq);
                break;
            }
        }
    }


    return 0;
}
