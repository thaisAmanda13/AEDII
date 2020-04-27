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
    apagaArvore(&arvore);
    /*
    int qtdnos = 0;
    contaNosArvore(&arvore,&qtdnos);
    printf("Existem %d nos nessa arvore!",qtdnos);
    */
    system("pause");
    return 0;
    
}