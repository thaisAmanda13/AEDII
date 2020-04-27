#include <stdio.h>
#include <stdlib.h>

typedef struct noTag{
    int valor;
    struct noTag *link;
}no;
void iniciaLista(no **Lista){
    *Lista = NULL;
}
void imprime(no *Lista){
    if(Lista == NULL){
        printf("A lista está vazia!");
        return;
    }
    else{
        do{
            printf("|%d|",Lista->valor);
            Lista = Lista->link;
        }while(Lista->link != NULL);
        printf("|%d|",Lista->valor);
    }
}
 void insereInicio(no **Lista,int num){ 
    no *novoNo;
    novoNo = malloc(sizeof(no));
    novoNo->valor=  num;
    if(*Lista == NULL){
        novoNo->link = NULL;
        *Lista = novoNo;
    }
    else{
        novoNo->link = *Lista;
        *Lista = novoNo;
    }
 }
 
 int main(){
     no *lista;
     iniciaLista(&lista);
     insereInicio(&lista,8);
     insereInicio(&lista,6);
     insereInicio(&lista,10);
     imprime(lista);

 }