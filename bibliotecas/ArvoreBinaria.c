#include <stdio.h>
#include <stdlib.h>
typedef struct noTreeTag {
    int info;
    struct noTreeTag *esquerda;
    struct noTreeTag *direita;
}noArvore;
void iniciaArvore(noArvore ** Tree){
        (*Tree) = NULL;
}
int insereABB(noArvore **Tree, int elemento){
    if(*Tree == NULL){
        *Tree = malloc(sizeof(noArvore));
        if(*Tree != NULL){
            (*Tree)->info = elemento;
            (*Tree)->esquerda = NULL;
            (*Tree)->direita = NULL;
            return 1;// deu certo a inserção
        }
        else{
            return 2;// nao havia memoria para alocar entao nao foi possivel inserir
        }
    }
    else{
        if(elemento < (*Tree)->info)
            insereABB(&((*Tree)->esquerda), elemento);
        else{
            if(elemento > (*Tree)->info)
                insereABB(&((*Tree)->direita), elemento);
            else
                return 3; // valor repetido nao é permitido por isso nao insere
        }
    }

}

// Exemplo de função – Exibe nós da ABB
void ExibeOrdem_AB(noArvore **T) {
    if(*T != NULL) {
    ExibeOrdem_AB(& ((*T)->esquerda));
    printf("\t |%d|", (*T)->info);
    ExibeOrdem_AB(& ((*T)->direita));
    }
}
int main(){
    noArvore *arvore;
    iniciaArvore(&arvore);
    insereABB(&arvore, 15);
    insereABB(&arvore, 18);
    insereABB(&arvore, 11);
    insereABB(&arvore, 1);
    insereABB(&arvore, 19);
       
       
    ExibeOrdem_AB(&arvore);
    system("pause");
    return 0;
}