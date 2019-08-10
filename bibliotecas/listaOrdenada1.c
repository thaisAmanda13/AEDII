#include <stdio.h>
#include "ListaEncadeada.h"
#include <stdio.h>
#include<stdlib.h>
void insereOrdenada(no **Lista,int num){
    no *anterior, *novoNO,*prox ;
    prox = *Lista;
    novoNO = malloc(sizeof(no));
    novoNO->valor = num;
    if(*Lista == NULL){
        novoNO->link = NULL;
        *Lista = novoNO; 
        return;
     }
    else{    
         while(prox->link != NULL){
                anterior = prox;
                prox = prox->link;
            }
    }

}
int main(){
    no *Lista;
    iniciaLista(&Lista);
    insereInicio(&Lista,5);
    insereInicio(&Lista,4);
    imprime(Lista);
    system("pause");
    system("cls");
   
}