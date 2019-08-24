#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
    noArvore *arvore;
    iniciaArvore(&arvore);
    insereABB(&arvore, 10);
    insereABB(&arvore, 8);
    insereABB(&arvore, 20);
    insereABB(&arvore,2 );
    insereABB(&arvore, 9);
    insereABB(&arvore, 30);
    printf("\n\n");  
    exibeFolhas(&arvore);
    system("pause");
    exibeFolhas(&arvore);
    return 0;
}