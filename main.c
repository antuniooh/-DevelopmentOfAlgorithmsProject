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

struct Usuario{
    char nome[200];
    int CPF ;
    float saldo;
    char senha[4];
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

void Inserir(FILE *p, FILE* p_user, struct Usuario u){
    struct Receita r;

    void criaReceita(){

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

    char senha[4];
    puts("Necessario a senha para fazer movimentacoes! ");
    fflush(stdin);//limpa o enter do buffer que foi deixado
    fgets(senha, 4, stdin);

    printf("A senha: %s\n", u.senha);
    printf("A senha: %s\n", senha);

    if(senha ==  (u.senha)) {
        printf("senhas coincidem\n");
        //criaReceita();

    } else{
        printf("n senhas coincidem\n");
    }

}

void criaUsuario(FILE *p, struct Usuario* u){

    puts("=================");
    puts("Criacao de Conta");
    puts("=================");
    puts("Qual o seu nome? ");
    fflush(stdin);//limpa o enter do buffer que foi deixado
    fgets(u->nome, 200, stdin);
    puts("Qual seu CPF? ");
    scanf("%d", u->CPF);
    fflush(stdin);//limpa o enter do buffer que foi deixado
    u->saldo = 0.0;
    puts("Qual a sua senha? (deve ter 4 digitos");
    fflush(stdin);//limpa o enter do buffer que foi deixado
    fgets(u->senha, 4, stdin);
    fflush(stdin);//limpa o enter do buffer que foi deixado


    //adiciona no arquivo
    fprintf(p, " %s", u->nome);
    fprintf(p, "%d\n", u->CPF);
    fprintf(p, " %f\n", u->saldo);
    fprintf(p, "%s\n", u->senha);

    //fecha o arquiv
    fclose(p);


}

int main() {
    //iniciar um usuário
    struct Usuario u;
    FILE *p_user = fopen("user.txt", "r");;

    if(p_user == NULL)
    {
        p_user = fopen("user.txt", "a");
        criaUsuario(p_user, &(u));
        main();
    } else {
        // criando a variável ponteiro para o arquivo
        FILE *pont_arq;

        //abrindo o arquivo
        pont_arq = fopen("financas.txt", "a");

        while (1) {
            int op = menu();
            if (op == 1) {
                printf("%s\n", u.nome);
                printf("%f\n", u.saldo);
                printf("%s\n", u.senha);
                printf("%d\n", u.CPF);

                Inserir(pont_arq, p_user, u);
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