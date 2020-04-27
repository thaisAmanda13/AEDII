#include <stdio.h>
#include <stdlib.h>
#define TAM 16
void filhoEsquerda(int i, int vet[]){
    if((2*i) <= TAM){
        printf("o filho (%d) esta em 2 * i ( %d )\n",vet[2*i], 2*i);
    }
     if((2*i) > TAM){
        printf("Nao possui filho a Esquerda \n");
    }
    
}
void filhoDireita(int i, int vet[]){
    if( (( (2*i) + 1) ) <= TAM){
        printf("filho da direita (%d) esta em 2*i + 1 ( %d )\n",vet[(2*i)+1], (2*i)+1);
    }if( ( (2 * i)+ 1 ) > TAM){
        printf(" nao possui filho a direita\n");
    }
}

int main(){
    int vetor[]={0,20,10,30,2,12,28,42,1,8,11,18,22,29,32,59};
    int pai, no;
    printf("Digite o indice  de qual no (1 - 16) voce deseja ver os seus respectivos filhos e pai (se tiver)\n");
    scanf("%d",&no);
  
    if(no == 1)
        printf("este no nao tem pai\n");
    
    else
        printf("o pai deste no eh:%d \n",vetor[no/2]); 
    filhoEsquerda(no,vetor);
    filhoDireita(no,vetor);
    
    system("pause");
}