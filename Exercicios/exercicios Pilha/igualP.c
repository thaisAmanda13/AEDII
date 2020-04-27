#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#include "pilha.h"

int main(){
	pilha pilha2, pilha1, auxPilha;
	int num,contador = 0;
	iniciaPilha(&pilha1);
	iniciaPilha(&pilha2);
	push(&pilha1,3);
	push(&pilha1,5);
	push(&pilha1,1);
	push(&pilha1,4);
	push(&pilha1,3);
	// pilha 2
	push(&pilha2,3);
	push(&pilha2,5);
	push(&pilha2,7);
	push(&pilha2,4);
	push(&pilha2,3);
	for(int i = 0; i < TAM; i++ ){
		if(pilha1.vet[i] == pilha2.vet[i])
			contador++;
	}
	if(contador == TAM)
		printf("As pilhas sao iguais\n");
	else
		printf("As pilhas nao sao iguais\n");
	printf("________PILHA 1___________\n");
	exibePilha(&pilha1);
	printf("\n________PILHA 2___________\n");
	exibePilha(&pilha2);
	return 0;

}




