#include<stdio.h>
#include<stdlib.h>
#define N 25
void radixsort(int vetor[], int tamanho) {
    int i;
    int aux[tamanho];
    int maior = vetor[0];
    int exp = 1;

    //b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++){
    	    bucket[(vetor[i] / exp) % 10]++;
            printf("primeiro for , buckt %d posicao %d\n", bucket[(vetor[i] / exp) % 10],(vetor[i] / exp) % 10);
        }
        system("pause");
        system("cls");
    	for (i = 1; i < 10; i++){
    	    bucket[i] += bucket[i - 1];
            printf("\n\nfor 2, buckt[%d] %d += buckt[%d - 1] %d  \n",i, bucket[i],i, bucket[i-1]);
        }
        system("pause");
        system("cls");
    	for (i = tamanho - 1; i >= 0; i--){
    	    aux[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        printf("\n\n for 3   aux %d e vetor[i] %d e \n", aux, vetor[i]);
        }
        system("pause");
        system("cls");
    	for (i = 0; i < tamanho; i++){
    	    vetor[i] = aux[i];
            printf("for 4    vetor[i] %d aux[i] %d",vetor[i],aux[i]);
        }
        system("pause");
        system("cls");
    	exp *= 10;
    }
    for(i = 0; i < tamanho; i++){
        printf("|%d|",aux[i]);
    }
    
}
int main(){
    int tamanho = 20;
    int vetor[N]= {1,2,3,4};
    radixsort(vetor,tamanho);
    system("pause");
}