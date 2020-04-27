#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    int continuar = 1;   
    pilha pilha1;

    iniciaPilha(&pilha1);
    while(continuar == 1){
        menu(&pilha1);
        printf("\nDigite:\n(1)-para continuar\n(0)- para sair\n");
        scanf("%d",&continuar);
        system("cls");
    }

}

