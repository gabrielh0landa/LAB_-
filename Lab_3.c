#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 100 // Segunda Questão
#define limite_total 1000 // Segunda Questão

int tirar_repetidos(){
    int n = 0;
    int j = 1;
    int troca;

    printf("Qual o tamanho do seu vetor?\n");
    scanf("%d", &n);
    int vetor[n];

    printf("Preencha seu vetor de %d posições\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Seu %d elemento vale:\n", j++);
        scanf("%d", &vetor[i]);
    }
    printf("Seu vetor:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d]\n ", vetor[i]);   
    }
    
    //Colocando em Ordem
    for (int i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                troca = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = troca;
            }
        }
    }
    printf("Seu vetor organizado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d]\n ", vetor[i]);   
    }

    //Tirando os repetidos
    printf("Seu vetor sem números repetidos:");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vetor[i] == vetor[j]) { 
                for (int k = j; k < n - 1; k++) {
                    vetor[k] = vetor[k + 1];
                }
                n--; 
                j--; 
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("[%d]\n ", vetor[i]);   
    }
        
}

int verificar_sorteio(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return 1; 
        }
    }
    return 0; 
}

void sortear_numeros(int vetor[], int tamanho, int limite) {
    int sorteados = 0;

    while (sorteados < tamanho) {
        int numero = rand() % limite; 

        
        if (!verificar_sorteio(vetor, sorteados, numero)) {
            vetor[sorteados] = numero;
            sorteados++;
        }
    }
}

void embaralhar(int *vetor, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % (n - i);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
        
        for (int k = i + 1; k < n; k++) {
            vetor[k] = vetor[k + 1];
        }
    }
}


int main (){
int escolha = 0;
int vetor[tam];
    do{
        
        printf("Escolha uma função:\n 1 - Retirar os elementos repetidos de um vetor.\n 2 - Imprimir 100 números que não se repetem.\n 3 - Emparalhar um vetor.\n Qualquer outra para sair!\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1: 
            tirar_repetidos();
            break;
            
        case 2: 
            srand(time(NULL));
            sortear_numeros(vetor, tam, limite_total);
            printf("Números sorteados:\n");
            for(int i = 0; i < tam; i++){
                printf("[%d]", vetor[i]);
            }
            break;
            
        case 3: 
            for(int i = 0; i < 10; i++){
                vetor[i] = i - i%3;
            }
            printf("Seu vetor:");

            for(int i = 0; i < 10; i++){
                printf("%d", vetor[i]);
            }
            embaralhar(vetor, 100);
             for(int i = 0; i < 10; i++){
                printf("%d", vetor[i]);
            }
            break;
         
        default: 
            break;
            
        }
    }while(escolha > 1 || escolha < 3);

    
}