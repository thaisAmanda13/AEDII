#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define TAM 4 //numero aleatorio, pode mudar kskssk
typedef struct noPalavra{
    int qtdVezes ;
    char valor[100]; //texto de ate 500 letras
    struct noPalavra *link;
   
}noStr;

int compararPalavras(char vetor[], char vetor2[]){
    for(int i = 0; vetor[i] != '\0' && vetor2[i] != '\0' && vetor[i] != ' ' && vetor2[i] != ' '; i++){
        if(vetor[i] != vetor2[i]){
            printf("%c %c ", vetor[i], vetor2[i]);
            return 1;
        }
    }
        return 0;
}

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
}
int inserirPalavra(noStr **Classe, char Palavra[], int Hash){
    noStr *aux;
    aux = *Classe;
    printf("ENTREI\n");
    // if (aux == NULL){
    //     (*Classe)->qtdVezes = 0;
    // }

    printf("passei if");
    while(aux != NULL){
        printf("Entrei while\n");
        if (compararPalavras(aux->valor ,Palavra) == 0){//se a palavra for igual incrementa
            printf("entrei if\n");
            //aux->qtdVezes ++;
            return 0;
        }
        aux = aux->link;
    }//senao tem nenhum igual inserir o nó no Hash correspondente
    printf("Vou inserir \n");
    system("pause");
    insereInicioString(Classe, Palavra);
}
int calcularHashTexto_Insere(char Texto[], noStr **Classes){
 
    int PosicaoAtual = 0, x = 0, cont2 = 0;
   
        while(Texto[PosicaoAtual] != '\0'){
        
           
            int soma = 0;
            for(x = PosicaoAtual ; Texto[x] != ' ' && Texto[x] != '\0'; x ++){
                printf("%c ",Texto[x]);
                soma += Texto[x];
            }
            printf("\n\n soma %d",soma);
            printf(" \n");
           inserirPalavra(Classes, Texto, soma % TAM);
           printf("inseri e vortei ");
            PosicaoAtual = x + 1; 
            
           
        }
        printf("Sai do for");
        system("pause");
}
int main(){
    char texto[]={'t','e','x','t','o',' ','a','l','e','a','t','o','r','i','o',' ','p','a','r','a',' ','t','e','s','t','e'};
    noStr *Classes[10]; 
    noStr *aux = Classes[0];
    
    for(int i = 0; i < 10; i ++)
        Classes[i] = NULL;

    system("pause");
    calcularHashTexto_Insere(texto, Classes);
    

    for(int j = 0; j < 10; j++ ){
        printf("entrei primeiro for\n");
        for(int i  = 0; i < 6; i++){ 
            while(aux != NULL){
                printf("Passei while \n");
               // printf("\nA palavra %c\n",aux->valor[i]);
                aux = aux->link;
                 printf("passei aux \n");
            }
        }
        aux = Classes[j];
    }
        system("pause");

printf("\n\nsai\n");
system("pause");}