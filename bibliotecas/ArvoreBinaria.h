#include<stdlib.h>
#include<stdlib.h>

typedef struct noTreeTag {
    int info;
    struct noTreeTag *esquerda;
    struct noTreeTag *direita;
}noArvore;

void iniciaArvore(noArvore ** Tree);
int insereABB(noArvore **Tree, int elemento);
int emOrdem(noArvore **Tree);
int posOrdem(noArvore **Tree);
int preOrdem(noArvore **Tree);
void exibeFolhas(noArvore **Tree);

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

int emOrdem(noArvore **Tree){
    if(*Tree == NULL)
        return 0;
    else{
        emOrdem(&((*Tree)->esquerda));
        printf("\t|%d|",(*Tree)->info);
        emOrdem(&((*Tree)->direita));
    }
}

int posOrdem(noArvore **Tree){
    if(*Tree == NULL )
        return 0;
    else{
        posOrdem(&((*Tree)->esquerda));
        posOrdem(&((*Tree)->direita));
        printf("\t|%d|",(*Tree)->info);
    }
}

void exibeFolhas(noArvore **Tree){
    if(*Tree == NULL)
       return ;
    else{
        if(((*Tree)->direita == NULL ) && ((*Tree)->esquerda == NULL))
            printf("|%d|", (*Tree)->info);
        else
           exibeFolhas(&((*Tree)->esquerda));
           exibeFolhas(&((*Tree)->direita));
    }
}