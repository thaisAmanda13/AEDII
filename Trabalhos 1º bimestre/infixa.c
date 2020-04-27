#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

#define MAX 100

int precedencia (char op);

int precedencia(char op) {
    switch (op) {

    case '(': 
        return 0;
        break;

    case '+': 
    case '-':
        return 1;
        break;

    case '': 
    case '/': 
        return 2;
        break;

    default:
        fprintf(stderr, "Operandor desconhecido!\n");
        exit(1);
    }
}

/
  Conversao de notacao infixa para posfixa.

  Obs: consideramos cada caracter como um ente separado, assim essa
  calculadora burra so aceita variaveis de uma letra e operadores
  fundamentais e parenteses.
*/

int main() {
    char infixa[MAX], 
        ch; 
    int i, n;
    pilha *p;

    printf("Digite uma expressao aritmetica: ");
    scanf("%s", infixa); 
    n = strlen(infixa); 
    p = cria_pilha(n);

    for (i=0; i<n; i++)

        if ('a' <= infixa[i] && infixa[i] <= 'z')
            printf("%c ", infixa[i]);
        else 
            switch (infixa[i]) {
            case '(': 
                empilha(p, infixa[i]); 
                break;
            case ')': 
                while ((ch = desempilha(p)) != '(') 
                    printf("%c ", ch); 
                break; 
            default: 
                while (!pilha_vazia(p) && 
                       precedencia(topo_pilha(p)) >= precedencia(infixa[i]))
                    printf("%c ", desempilha(p));
                empilha(p, infixa[i]); 
            }

    while (!pilha_vazia(p)) 
        printf("%c ", desempilha(p));
    printf("\n"); 

    destroi_pilha(p);
    return 0;
}