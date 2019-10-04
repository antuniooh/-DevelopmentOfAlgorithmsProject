#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Data criadata(int dia, int mes, int ano){
    struct Data d;
    d.dia = dia;
    d.mes = mes;
    d.ano =ano;
    return d;

}

struct Receita{
    struct Data data;
    float valor;
    char categoria[200];
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

void tiraEnter(char *s){
    for (int i = 0; s[i] != '\n' ; ++i) {
        s[i] = 0;
    }
}

void Inserir(FILE *p){
    struct Receita r;

    int op;
    puts("Voce deseja inserir uma receita ou um gasto?");
    puts("1 - Receita");
    puts("2 - Gasto");
    printf("Opcao > ");
    scanf(" %d",&op);

    puts("Qual o valor? ");
    scanf(" %f",&(r.valor));
    puts("Qual a data? ");
    scanf("%d %d %d", &(r.data.dia), &(r.data.mes),&(r.data.ano));
    puts("Qual a categoria?: (Moradia, Estudos, Transporte, Alimentacao, Trabalho)");
    fflush(stdin);//limpa o enter do buffer que foi deixado
    fgets(r.categoria, 200, stdin);
    //tiraEnter(r.categoria);

    if(op == 1){
        fprintf(p, "%s", "Data: ");
        fprintf(p, " %d/%d/%d ", r.data.dia, r.data.mes, r.data.ano);
        fprintf(p, "%s", " + ");
        fprintf(p, " %f ", r.valor);
        fprintf(p, "%s\n", r.categoria);
    } else if(op == 2){
        fprintf(p, "%s", "Data: ");
        fprintf(p, " %d/%d/%d ", r.data.dia, r.data.mes, r.data.ano);
        fprintf(p, "%s", " - ");
        fprintf(p, " %f ", r.valor);
        fprintf(p, " %s \n", r.categoria);
    }
}

int main() {
    // criando a variável ponteiro para o arquivo
    FILE *pont_arq;
    char texto[2000];

    //abrindo o arquivo
    pont_arq = fopen("financas.txt", "a");

    //usando fprintf para armazenar a string no arquivo
    //fprintf(pont_arq, "%s", "Minhas Finanças Pessoais\n");
    //fprintf(pont_arq, "%s", "==============================================\n");


    // fechando arquivo



    while (1){
        int op = menu();
        if (op == 1){
            Inserir(pont_arq);
        }
        else if (op == 2){
           // Remover();
        }
        else if (op == 3){
            //e será impresso o texto
            while(fgets(texto, 2000, pont_arq) != NULL)
                printf("%s", texto);

        }
        else if (op == 0){
            puts("Fechando o sistema....");
            fclose(pont_arq);
            break;
        }
        else {
            puts("Operação Inválida, fechando o sistema....");
            break;
        }
    }


    return 0;
}