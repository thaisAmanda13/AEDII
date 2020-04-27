#define TAM 8
typedef struct {
    int vet[TAM] ;
    int  topo;
}pilha;

void exibePilha(pilha *pilha1);
void msgMenu();
void menu(pilha * pilha1);
int vaziaPilha(pilha *pilha1);
int cheiaPilha(pilha *pilha1);
int pop(pilha *pilha1);
int push(pilha *pilha1, int num);


/*
void msgMenu(){
    printf("_________________________________________________________________\n");
    printf("               MENU\n");
    printf("Digite o numero referente a operacao que deseja fazer\n");
    printf("(1)-push\n");
    printf("(2)- pop\n");
    printf("(3)- Exibe itens\n");
    printf("(4)- sair\n");
    printf("_________________________________________________________________\n");


}
void menu(pilha * pilha1){
    msgMenu();
    int opcao, num;
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
        printf("Digite o numero para inserir na pilha\n");
        scanf("%d",&num);
         if( push(pilha1, num) == -1)
            printf("a pilha esta cheia\n");

        break;
        case 2:
           if(pop(pilha1) == -2 )
            printf("A pilha esta vazia\n");
             
        case 3:
            exibePilha(pilha1);
            break;
        case 4:
            break;
        default:
         printf("Erro, impossivel realizar\n");
         break;

    }
}*/
int vaziaPilha(pilha *pilha1){
    if(pilha1->topo == 0)
        return (1);
    else
        return 0;
}
int cheiaPilha(pilha *pilha1){
    if(pilha1->topo == (TAM))
        return 1;
    else
        return 0;
}


void iniciaPilha(pilha *pilha1){
    pilha1->topo = 0;
}

int push(pilha *pilha1, int num){
    if(cheiaPilha(pilha1) == 1){
        return -1;
    }
    else{
        pilha1->vet[pilha1-> topo] = num;
        pilha1->topo++;
        return (pilha1->topo);
    }
}
int pop(pilha *pilha1){
    if(vaziaPilha(pilha1)!= 1){
        pilha1->topo--;
        return (pilha1->vet[pilha1->topo]);
    }
    else
        return -2; 
}
void exibePilha(pilha *pilha1){
    int i = 0;
    pilha pilhaAux;
    iniciaPilha(&pilhaAux);
    while(pop(pilha1) != -2){
        pilha1->topo++;
        push(&pilhaAux,pop(pilha1));
    }
   // system("cls");
    printf("\n__________Valores da Pilha______________\n");
      for(i = 0; i < pilhaAux.topo; i++)
    {
        printf("|%d|\t", pilhaAux.vet[i]);
    }
    printf("\n\n");
}