#include <stdio.h> 
#include<stdlib.h>
typedef struct noTag{
    int valor;
    struct noTag *link;
}no;
void iniciaLista(no **Lista){
    *Lista = NULL;
}
void imprime(no *lista){
    if(lista == NULL)
        printf("\nLista vazia!\n");
    else{
        while(lista != NULL){
            printf("|%d|",lista->valor);
            lista= lista->link;
        }
    }
}
void insereInicio(no **lista,int num){
    no *novo;
    novo = malloc(sizeof(no));
    novo->valor = num;
    if(*lista == NULL)
      novo->link = NULL;
    else
        novo->link = *lista;
    *lista = novo;  
}
int removeFinal(no **lista){
    int valorRemovido;
    if(*lista != NULL){
        if((*lista)->link == NULL){
            valorRemovido = (*lista)->valor;
            free(*lista);
            *lista = NULL;
        }
        else{
            no *aux=  *lista, *anterior;
            while(aux->link != NULL){
                anterior = aux;
                aux = aux->link;
            }
            valorRemovido = aux->valor;
            anterior->link = NULL;
            free(aux);
        }
    }
}
void imprimeInverso(no **lista){
    no *ant ;
    no * prox = *lista;
    while(prox->link != NULL)
        prox = prox->link;
    
    while(prox != *lista){
        ant = *lista;
        printf("|%d|",prox->valor);
        while(ant != prox)
            ant = ant->link;
        prox = ant;
    }
}
int removeInicio(no **lista){
    no *aux = *lista;
    int valorRemovido;
    if(*lista  != NULL){
        if((*lista)->link == NULL ){
             valorRemovido = (*lista)->valor;
             free(*lista);
             *lista = NULL;
        }
        else{
            valorRemovido = aux->valor;
            *lista = aux->link;
            free(aux);
        }
    }
}
void mediaLista(no **lista){
    no *aux = *lista;
    int qtdNos = 0;
    float media = 0;
    if(*lista != NULL){
        if((*lista)->link == NULL)
            media = (*lista)->valor/1;
        else{
            while(aux != NULL){
                media += aux->valor;
                qtdNos++;
                aux= aux->link;  
            }
           
            printf("\nA media:%f",media/qtdNos);
        }
       
    }
}
void maiorValor(no **lista){
    no *aux = *lista;
    int maior = -1;
    if (aux != NULL){
        if(aux -> link == NULL)
            maior = aux->valor;
        else
        {
            while(aux != NULL){
                if(maior < aux->valor)
                    maior = aux->valor;
                aux = aux->link;
            }
        }
        printf("\no maior valor da lista e: %d",maior);
    }
    else 
        printf("lista vazia");
    
}
int main (){
    no *l;
    iniciaLista(&l);
    //insereInicio(&l,1);
   // insereInicio(&l,5);
    //insereInicio(&l,5);
    //insereInicio(&l,3);
    imprime(l);
    printf("\n");
    maiorValor(&l);


}