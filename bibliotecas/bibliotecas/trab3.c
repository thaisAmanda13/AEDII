
#include <stdio.h> 
#include <stdlib.h>  
#include "ArvoreBinaria.h"

void printLevelOrder(noArvore *Tree);
void printNiveis(noArvore *Tree, int nivel); 
int altura(noArvore *node); 

void printLevelOrder(noArvore *Tree) 
{ 
    int h = altura(Tree); 
    int i; 

    for (i=1; i<=h; i++) 
        printNiveis(Tree, i); 
} 
  
void printNiveis(noArvore * Tree, int nivel) 
{ 
    if (Tree == NULL) 
        return; 
    if (nivel == 1) 
        printf("%d ", Tree->info); 
    else if (nivel > 1) 
    { 
        printNiveis(Tree->esquerda, nivel-1); 
        printNiveis(Tree->direita, nivel-1); 
    } 
} 
  
int altura(noArvore *node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        int alturaEsquerda = altura(node->esquerda); 
        int alturaDireita = altura(node->direita); 
        if ( alturaEsquerda > alturaDireita) 
            return(alturaEsquerda+1); 
        else 
            return(alturaDireita+1); 
    } 
} 

int main() 
{ 
    noArvore *Tree;
    iniciaArvore(&Tree);
    insereABB(&Tree,2);
    insereABB(&Tree,7); 
    insereABB(&Tree,5);
    insereABB(&Tree,2);
    insereABB(&Tree,6);
    insereABB(&Tree,9);

    
    
    printf("\nA arvore em PROFUNDIDADE: \n"); 
    
    printLevelOrder(Tree); 
    printf("\n");
    system("pause");
    
 
    //system("pause");
    return 0; 
} 
