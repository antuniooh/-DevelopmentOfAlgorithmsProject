#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "user.h"
#include "menu.h"

struct Usuario{
    char nome[200];
    int CPF ;
    float saldo;
    int senha;
};

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

void tiraEnter(char *s){
    int i;
    for (i = 0; s[i] != '\n' ; ++i) {
    }
    s[i] = 0;
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
        puts("=================================");

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
        while ((dia <= 0 || dia >= 32) || (mes <= 0 || mes >= 13) || (ano <= 0 || ano > 2019)) {
            puts("Digite uma data valida");
            scanf("%d %d %d", &dia, &mes, &ano);
        }
        fflush(stdin);
        puts("Qual a categoria?: (Moradia, Estudos, Transporte, Alimentacao, Trabalho)");
        char categoria[200];
        fflush(stdin);
        fgets(categoria, 200, stdin);
        tiraEnter(categoria);

        while ((strcmp(categoria, "Moradia") !=0) && (strcmp(categoria, "Estudos") != 0) &&
               (strcmp(categoria, "Alimentacao") != 0) && (strcmp(categoria, "Transporte") != 0) &&
               (strcmp(categoria, "Trabalho") != 0))
        {
            puts("Digite uma categoria valida");
            fgets(categoria, 200, stdin);
            tiraEnter(categoria);
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
            atualizarUser(r.valor, u, p_user);
        } else if (op == 2) {
            fprintf(p, "%s", " - ");
            atualizarUser(-r.valor, u, p_user);

        }
        fprintf(p, " %f ", r.valor);
        fprintf(p, " %s\n", r.categoria);

        puts("Transacao realizada com sucesso !");
        puts("=================================");
        fclose(p);


    } else {
        printf("As senhas nao coincidem\n");
    }
}