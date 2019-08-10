#include <stdlib.h>
typedef struct noTag{
    int numAviao;
    int prioridade;
    int tipo;
    struct noTag *link;
}no;

void iniciaLista(no **Lista);
void imprime(no *Lista);
void listaAvioes(no **Lista);
void insereFinal(no **Lista, int numeroAviao, int prioridade, int tipo);
int removeInicio(no **Lista);

void iniciaLista(no **Lista){
    *Lista = NULL;   
}
void listaAvioes(no **Lista){
    insereFinal(Lista,310,2,'p');  
    insereFinal(Lista,222,1,'p');
    insereFinal(Lista,430,2,'d');
    insereFinal(Lista,558,2,'p');    //aqui to so inserindo de qlq jeito na fika auxiliar pq neste momento a ordem n importa
    insereFinal(Lista,312,2,'d');

}

void insereFinal(no **Lista, int numeroAviao, int prioridade, int tipo){
    no *prox, *novoNO;
    novoNO = malloc(sizeof(no));
    novoNO->numAviao = numeroAviao;
    novoNO->link = NULL;
    novoNO->tipo = tipo;
    novoNO->prioridade = prioridade;
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
void insereOrdenada(no **Lista, no **filaAux){
   no *proximo, *novoNo;
	novoNo = (no *)malloc(sizeof(no));
    novoNo->numAviao = (*filaAux)->numAviao;
    novoNo->prioridade = (*filaAux)->prioridade;
    novoNo->tipo = (*filaAux)->tipo;
    removeInicio(filaAux);//removo o no da fila auxilar pq acima ja usei as infos necessarias dele.
    //aqui eu usei essa func de remover do inicio so por preguica d fazer outra pqp tanto faz onde removo 
    //pq essa é a auxiliar so pra guardar as infos dos avioes 
    if(novoNo->tipo == 'p')
        printf("\nO aviao de numero: %d entrou na fila de pouso!",novoNo->numAviao);
    else
        printf("\nO aviao de numero: %d entrou na fila de decolagem!",novoNo->numAviao);
    
	if (*Lista == NULL)
	{
		*Lista = novoNo;
		novoNo->link = NULL;
		return;
	}

	proximo = *Lista;

	if (proximo->prioridade > novoNo->prioridade ){

		novoNo->link = proximo;         //aqui so to inserinod na fila principal os avioes 
		*Lista = novoNo;
		return;                            //mas aqui a ordem importaa pq é na principal
	}

	while ((proximo->link != NULL) && (proximo->link->prioridade <= novoNo->prioridade))
	{
		proximo = proximo->link;
	}
	novoNo->link = proximo->link;
	proximo->link = novoNo;

  
}

void imprime(no *Lista){
    if(Lista ==  NULL){
        printf("A lista esta vazia!\n");
    }
    while(Lista != NULL){
        printf("|%d|\t",Lista->numAviao);
        Lista = Lista->link;
    }
}

int removeInicio(no **Lista){//preciso remover do inicio pq a fila principal
                                //ta em ordem de prioridade
    int valorRemovido;
    
    if(*Lista != NULL){
        if((*Lista)->link == NULL){ // caso tenha um unico nozinho
         no *aux = *Lista;
            valorRemovido = aux->numAviao;

            free(*Lista);
            *Lista = NULL;
        } 
        else{
            no *auxLista;
            auxLista = *Lista;
            valorRemovido = auxLista->numAviao;
            *Lista = auxLista->link;
            free(auxLista);
        }
        return valorRemovido;
    }
    else
        return -1; // lista vazia.
    
}