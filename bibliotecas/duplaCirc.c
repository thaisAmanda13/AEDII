#include <stdio.h> 
#include<stdlib.h>
typedef struct noTag{
    int valor;
    struct noTag *link;
    struct noTag *anterior;
}no;
void insereInicio(no **lista, int num){
    no *novoNo;
    novoNo = malloc(sizeof(no));
    novoNo->valor = num;
    if(*lista == NULL){
        *lista = novoNo;
        novoNo->link = *lista;
        novoNo->anterior = *lista;
    }
    else{
       // no *aux = *lista;
        novoNo->link = *lista;
        novoNo->anterior = (*lista)->anterior;
        (*lista)->anterior->next = novoNo;
        (*lista)->anterior = novoNo;
    }
}