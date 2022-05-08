#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_binaria {
    int info;
    struct arvore_binaria *esquerda, *direita;
} AB;

//Inicializa uma árvore vazia.
AB * AB_inicializar(void) {
    return NULL;
}

//Cria uma novo árvore contendo a raiz passada e os nodes esquerda e direita fornecidos.
AB * AB_criar(int raiz, AB *esquerda, AB *direita) {
    AB *novo = (AB*)malloc(sizeof(AB));
    
    novo->info = raiz;
    novo->esquerda = esquerda;
    novo->esquerda = direita;

    return novo;
}

//Recebe um vetor e seu tamanho.
AB *vet2ab (int *vet, int n) {
    if (n <= 0) {
        return NULL;
    }

    //A raiz será o meio do vetor, a esquerda será o lado esquerdo que sobrar do meio do vetor.
    return AB_criar(vet[n/2], vet2ab(vet, n/2), vet2ab(&vet[n/2 + 1], n-n/2-1));
}

int main(void) {
    AB *a = AB_inicializar();
}