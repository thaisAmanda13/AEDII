#include <stdio.h>
#include "listaAVIAO.h"
#include <stdlib.h>
 int main(){
    no *Lista, *filaAux;
    int aviaoDecolou;
    iniciaLista(&Lista);
    insereFinal(&Lista,310,2,'p');  
    insereFinal(&Lista,222,1,'p');
    insereFinal(&Lista,430,2,'d');
    insereFinal(&Lista,558,2,'p');    
    insereFinal(&Lista,312,2,'d');
    imprime(Lista);
 }