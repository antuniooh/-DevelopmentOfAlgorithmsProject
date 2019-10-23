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

void Inserir(FILE *p, FILE* p_user, struct Usuario u){

    void criaReceita(){
        struct Receita r;

        int op;
        puts("Voce deseja inserir uma receita ou um gasto?");
        puts("1 - Receita");
        puts("2 - Gasto");
        printf("Opcao > ");
        scanf("%d",&op);

        puts("Qual o valor? ");
        scanf(" %f",&(r.valor));
        puts("Qual a data? (dd mm aa)");
        scanf("%d %d %d", &(r.data.dia), &(r.data.mes),&(r.data.ano));
        puts("Qual a categoria?: (Moradia, Estudos, Transporte, Alimentacao, Trabalho)");
        fflush(stdin);//limpa o enter do buffer que foi deixado
        fgets(r.categoria, 200, stdin);

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

    int senha;
    puts("Necessario a senha para fazer movimentacoes! ");
    scanf("%d", &senha);


     printf("A senha: %d\n", u.senha);
     printf("A senha: %d\n", senha);

     if(senha ==  (u.senha)) {
         printf("A senha está correta\n");
         criaReceita();

     } else{
         printf("As senhas não coincidem\n");
     }
}
