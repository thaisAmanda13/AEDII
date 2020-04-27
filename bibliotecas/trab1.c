#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define TAM 4 //numero aleatorio, pode mudar kskssk
typedef struct noPalavra{
    int qtdVezes;
    char valor[5]; //texto de ate 500 letras
    struct noPalavra *link;
   
}noStr;

void exibeConteudo(char Palavra[]){
    for(int x = 0; Palavra[x] != '\0'; x++)
        printf("%c ",Palavra[x]);
}

void insereInicioString(noStr **Lista, char Palavra[]){
     noStr *novoNO;
    novoNO = malloc(sizeof(noStr));
    strcpy(novoNO->valor, Palavra); //copia palavra para valor
    if(*Lista == NULL){
        novoNO->link = NULL;
        *Lista = novoNO;
    }  
    (*Lista)->qtdVezes++;  
}
int calcularHashTexto_Insere(char Texto[], noStr **Classes){
    int PosicaoAtual = 0, x = 0;

        while(Texto[PosicaoAtual] != '\0'){
            int soma = 0;
            for(x = PosicaoAtual ; Texto[x] != ' '; x++){
                soma += Texto[x];
            }
            insereInicioString(&Classes[soma % TAM], Texto);
            PosicaoAtual = x + 1 + 1; 
        }
}
void imprimeVetorHash(noStr *Classes){
    for(int i  = 0; i < 6; i++){ // coloquei 6 pq é a qtd de classes
        printf("\nA palavra %s apareceu %d vezes\n",Classes->valor[i],Classes->qtdVezes);
    }
}

int main(){
    char texto[]={'t','e','x','t','o',' ','a','l','e','a','t','o','r','i','o',' ','p','a','r','a',' ','t','e','s','t','e'};
    noStr *Classes[6]; //numero aleatorio, pode mudar kskssk
    for(int i = 0; i< 6; i++){
        Classes[i] = NULL;
        Classes[i]->qtdVezes = 0;
    }
    calcularHashTexto_Insere(texto,&Classes);
    imprimeVetorHash(Classes);
    system("pause");
}



//Incompleta
// void comparaHash (){
//     no *percorre;
//     if(tabela[hash] != NULL){
//         percorre = tabela[hash]->link;
//         while((!strcmp(percorre->valor, Palavra->Valor) && percorre->link != NULL)
//             percorre = percorre->link;
//     }
// }