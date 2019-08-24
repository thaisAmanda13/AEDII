#include<stdio.h>
#include<stdlib.h>

typedef struct noTag{
    int valor;
    struct noTag *link;
}no;


void iniciaLista(no **Lista);
void imprime(no *Lista);
void insereInicio(no **Lista, int num);
int removeInicio(no **Lista);
void insereFinal(no **Lista, int num);
int removeFinal(no **Lista);
void insereOrdenada(no **Lista,int num);


void insereOrdenada(no **Lista,int num){
   no *proximo, *novoNo;
	novoNo = (no *)malloc(sizeof(no));
	novoNo->valor = num;

	if (*Lista == NULL)
	{
		*Lista = novoNo;
		novoNo->link = NULL;
		return;
	}

	proximo = *Lista;

	if (proximo->valor > num)
	{
		novoNo->link = proximo;
		*Lista = novoNo;
		return;
	}

	while (proximo->link != NULL && proximo->link->valor < num)
	{
		proximo = proximo->link;
	}
	novoNo->link = proximo->link;
	proximo->link = novoNo;
}

void iniciaLista(no **Lista){
    *Lista = NULL;   
}

void imprime(no *Lista){
    if(Lista ==  NULL){
        printf("A lista esta vazia!\n");
    }
    while(Lista != NULL){
        printf("|%d|\t",Lista->valor);
        Lista = Lista->link;
    }
}

void insereInicio(no **Lista, int num){
    no *novoNO;
    novoNO = malloc(sizeof(no));
    novoNO->valor = num;
    if(*Lista == NULL)
        novoNO->link = NULL;
    else
        novoNO->link = *Lista;
    *Lista = novoNO;       // lembrar de conferir essa linha 
}
int removeInicio(no **Lista){
    int valorRemovido;
    
    if(*Lista != NULL){
        if((*Lista)->link == NULL){ // caso tenha um unico nozinho
         no *aux = *Lista;
            valorRemovido = aux->valor;
            free(*Lista);
            *Lista = NULL;
        } 
        else{
            no *auxLista;
            auxLista = *Lista;
            valorRemovido = auxLista->valor;
            *Lista = auxLista->link;
            free(auxLista);
        }
        return valorRemovido;
    }
    else
        return -1; // lista vazia.
    
}
void insereFinal(no **Lista, int num){
    no *prox, *novoNO;
    novoNO = malloc(sizeof(no));
    novoNO->valor = num;
    novoNO->link = NULL;
    if(*Lista == NULL)
        *Lista = novoNO;
    else{
        prox = *Lista;
        while(prox->link != NULL){
            prox = prox->link;
        }
        prox->link = novoNO;
    }
}
int removeFinal(no **Lista){
    no *prox, *anterior;
    int valorRemovido;
    if(*Lista != NULL){
        if((*Lista)->link == NULL){
            valorRemovido = (*Lista)->valor;
            free(*Lista);
            *Lista = NULL;
        }
        else{
            prox = *Lista;
            while(prox->link != NULL){
                anterior = prox;
                prox = prox->link;
            }
            valorRemovido = prox->valor;
            anterior->link = NULL;
            free(prox);
        }
        return valorRemovido;
    }

}