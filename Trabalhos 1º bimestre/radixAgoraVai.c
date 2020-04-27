#include "pilhanario.h"
#include <stdlib.h>
#include <stdio.h>
#define LINHA 10
#define COLUNA 4
 // prototipos

void ordena(char lin[LINHA][COLUNA],int coluna);

void ordena(char lin[LINHA][COLUNA],int coluna){
	int i,j,r;
	char aux;
  for(i=0;i<LINHA; i++ ){
    for(j=i+1;j<LINHA; j++ ){
      if (lin[i][coluna]>lin[j][coluna] )
      {
      	for(r=0;r<COLUNA;r++){
      		aux=lin[i][r];
      		lin[i][r]=lin[j][r];
      		lin[j][r]= aux;
		  }
      }
    }
  }
}


int main(){
	char String[LINHA][COLUNA]={"COW","DOG","SEA","RUG","BOX","TAB","BAR","BIG","TEA","NOW"};
	int i,j;
	
	for(i=COLUNA-1;i>-1;i--){
		ordena(String,i);
	}
	
	for(i=0;i<LINHA;i++){
		for(j=0;j<COLUNA-1;j++){
			printf("%c",String[i][j]);
		}
		printf("\n");
	}

	    return 0;          
}