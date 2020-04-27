#include <stdio.h>
#include "ListaEncadeada.h"
#include<stdlib.h>

int main(){
    no *Lista;
    iniciaLista(&Lista);
    insereInicio(&Lista,5);
    insereInicio(&Lista,4);
    imprime(Lista);
    system("pause");
    system("cls");
    insereOrdenada(&Lista,2);
    insereOrdenada(&Lista,3);
    insereOrdenada(&Lista,7);
    insereOrdenada(&Lista,10);
    insereOrdenada(&Lista,7);
    insereOrdenada(&Lista,6);
  
    imprime(Lista);
   
}