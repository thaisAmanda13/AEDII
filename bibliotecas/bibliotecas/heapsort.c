#include <stdio.h>
#include <stdlib.h>

void troca (int A,int B) {
    int t = A;
    A = B;
    B = t;
}
void constroiHeap (int m, int v[]){
   for (int k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (v[f/2], v[f]);          // 6
         f /= 2;                        // 7
      }
   }
}
void peneira (int m, int v[]){ 
   int p = 1, f = 2, x = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1]) ++f;
      if (x >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = x;
}
void heapsort (int n, int v[]){
   constroiHeap (n, v);
   for (int m = n; m >= 2; --m) {
      troca (v[1], v[m]);
      peneira (m-1, v);
   }
}
int main(){
    int v[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4};
    constroiHeap(7, v);
    printf("apos usar a funcao:");
    for(int i = 0; i< 8;i++)
        printf("%d\t",v[i]);
    system("pause");
}

