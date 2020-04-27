#include<stdio.h>
#include<stdlib.h>
#include "pilha1.h"
 void binario(pilha *vetorBin,int valorDec){
    while(valorDec>=1){
           if(valorDec%2 == 0){
               push(vetorBin,0);
               valorDec = valorDec/2;
           }
           else{
              push(vetorBin,1);
              valorDec = valorDec/2;
          }
      }
       printf("O numero %d fica assim em binario:\n",valorDec);
      exibePilha(vetorBin);
 }
void VerificaDecimal(pilha *guardaBinario)
{
    int valorDec;
    printf("\nDigite um inteiro decimal para ser convertido.\n");

    scanf("%d", &valorDec);
    system("pause");
    system("cls");
    if(valorDec == 0){
    	while(cheiaPilha(guardaBinario) !=1){
            push(guardaBinario,0);
        }
         exibePilha(guardaBinario);
    }
    else if(valorDec > 255 ){
        printf("nao foi possivel representar este valor em 8 bits\n OVERFLOOOW!");
    }
    else{
       binario(guardaBinario,valorDec);
  }

}
int main(){
	pilha vetorBin;
	char sair;
	int aux = 0;

    	iniciaPilha(&vetorBin);

    	VerificaDecimal(&vetorBin);
       
    
    return 0;
}