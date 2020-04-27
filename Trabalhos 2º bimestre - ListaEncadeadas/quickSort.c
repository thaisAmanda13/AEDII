#include<stdio.h>
#include <stdlib.h>
#define TAM 5
void QuickSort(int vetor[TAM], int inicio, int fim);

void QuickSort(int vetor[TAM], int inicio, int fim){
    int pivo, aux, i, j, meio;
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   printf("\n O seu pivo da vez e: %d\n",pivo);
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
 
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) 
        QuickSort(vetor, inicio, j);
   if(i < fim) 
        QuickSort(vetor, i, fim);   

}
void limpaTela(){
    system("pause");
    system("cls");
}
int main(){
   
   int vetor[TAM] = { 1 , 7 , 5 , 3,  9 };
   
   int i;   
   printf("Vetor desordenado:\n");
   for(i = 0; i < TAM; i++){
      printf("|%d|\t", vetor[i]);
   } 
   limpaTela();
   QuickSort(vetor, 0, TAM-1);
   printf("\nVetor ordenado:\n");
   for(i = 0; i < TAM; i++){
      printf("|%d|\t", vetor[i]);
   }
   printf("\n");   
}

