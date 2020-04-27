#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#include "pilha.h"

int main(){
	pilha pilha2, pilha1, auxPilha;
	int num;
	srand(time(NULL));
	num  = rand()%37;

	iniciaPilha(&pilha1);
	iniciaPilha(&auxPilha);
	iniciaPilha(&pilha2);

	while(push(&pilha1, num) != -1 ){
		num  = (rand() % 99 + 1) ;
	}
	printf("Pilha 1______________________\n");
	exibePilha(&pilha1);

	while(pop(&pilha1) != -2){
		pilha1.topo++;
		push(&pilha2,pop(&pilha1));
	}
	while(pop(&pilha2)!= -2){
		auxPilha.topo++;
		push(&auxPilha,pop(&pilha2));
	}
	printf("\nPilha 2______________________\n");
	exibePilha(&auxPilha);
}