#include <stdio.h>
#include <stdlib.h>
typedef struct noTag{
    int valor;
    struct noTag *next;
    struct noTag *prev;
}no;
void iniciaLD(no **Lista){
    *Lista = NULL;
}
void imprime(no *Lista){
    if(Lista ==  NULL){
        printf("A lista esta vazia!\n");
    }
    while(Lista != NULL){
        printf("|%d|\t",Lista->valor);
        Lista = Lista->next;
    }
}
 void insereOrdenada(no **Lista, int num){
    no *aux = *Lista, *novoNo;
    novoNo = malloc(sizeof(no));
    novoNo->valor = num;
    novoNo->next = NULL;
    novoNo->prev = NULL;
    if(*Lista == NULL)// lista vazia, apenas insiro
        *Lista = novoNo;
    else{
        if(num < aux->valor){
            aux->prev = novoNo; // menor valor, insiro no inicio
            novoNo->next = aux;
            *Lista = novoNo;
        }
        else{
            while((aux->valor < num)&&(aux->next != NULL)){
                aux = aux->next;  // procurando onde inserir o valor
            }
            if((aux->next == NULL) && (aux->valor < num)){
                aux->next = novoNo;
                novoNo->prev = aux;
            }
            else{
                novoNo->prev = aux->prev;
			    novoNo->next = aux;
				aux->prev = novoNo;
				novoNo->prev->next = novoNo;		
            }

        }
    }   
 }
 void removeEspecifico(no **Lista, int num){
     no *aux = *Lista;
     no *temp = aux;
     if(*Lista == NULL){
        printf("Impossivel remover, sua lista nao tem elementos\n");
        return;
     }
     else{  // caso seja o primeiro valor 
         if(aux->next!=NULL){
			if(aux->valor == num){
				temp =aux;
				*Lista = aux->next;
				aux->prev = NULL;
				free(temp);
                printf("\n O valor escolhido foi removido com sucesso!!!\n Veja como sua lista ficou:\n");
                imprime(*Lista);
                return;
			}
        
            // removendo do meio
            while (aux->next != NULL){
                if(aux->valor == num){
                    temp = aux;
                    aux->prev->next = aux-> next;
                    aux->next->prev=aux->prev;
                    aux=aux->prev;
                    free(temp);
                    printf("\n O valor escolhido foi removido com sucesso!!!\n");
                    imprime(*Lista);
                    return;
                }
                aux = aux->next;
            } 
            if(aux->next == NULL){ // se o valor a ser removido for o ultimo da lista
                if(num == aux->valor){
                    temp = aux;
                    aux->prev->next = NULL; // faço o anterior do valor removido apontar pra nulo
                    free(temp);
                    printf("\n O valor escolhido foi removido com sucesso!!!\n");
                    imprime(*Lista);
                }
            }
        }
        else
            printf("O valor que voce quer remover nao existe na Lista!\n");
    }
 }
 int main(){
     no *Lista;
     iniciaLD(&Lista);
     //insereOrdenada(&Lista,2);
     //insereOrdenada(&Lista,7);
     //insereOrdenada(&Lista,1);
     //insereOrdenada(&Lista,10);
     printf("Esta e sua lista ordenada!!\n");
     imprime(Lista);
     system("pause");
     system("cls");
     removeEspecifico(&Lista,3);
     return 0;
 }