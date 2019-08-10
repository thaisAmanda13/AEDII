#include <stdio.h>
#include "ListaEncadeada.h"
#include <stdio.h>
#include<stdlib.h>
int main(){
    no *Lista;
    iniciaLista(&Lista);
    printf("apos a inserir inicio!\n");
    insereInicio(&Lista,5);
    insereInicio(&Lista,6);
    insereInicio(&Lista,7);
    
    imprime(Lista);
    system("pause");
    removeInicio(&Lista);
    imprime(Lista);
}