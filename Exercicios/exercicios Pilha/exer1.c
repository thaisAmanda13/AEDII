#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#include "pilha.h"

int main(){
	pilha pilha2, pilha1;
	int num;
	srand(time(NULL));
	num  = rand()%37;
	iniciaPilha(&pilha2);

	while(push(&pilha2, num) != -1 ){
		num  = (rand() % 99 + 1) ;
	}
	printf("Pilha 1______________________\n");
	exibePilha(&pilha2);

	iniciaPilha(&pilha1);
	while(pop(&pilha2) != -2){
		pilha2.topo++;
		push(&pilha1,pop(&pilha2));
	}
	printf("\nPilha 2______________________\n");
	exibePilha(&pilha1);
}