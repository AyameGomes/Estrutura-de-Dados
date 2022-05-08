#include <stdio.h>
#include <stdlib.h>

//Ordem de iteração dos nós.
//Pré ordem (profundidade): raiz, esquerda e direita.
//Simétrico: esquerda, raiz e direita.
//Pós-ordem: esquerda, direita e raiz.

typedef struct arvore_binaria {
    int info;
    struct arvore_binaria *esquerda, *direita;
} AB;

void imprimir_pre_ordem (AB *a) {
    //Se a existe, imprimir a e chamar a função para imprimir esquerda e em seguida direita de a.
    if (a != NULL) {
        printf("%d \n", a->info);

        imprimir_pre_ordem(a->esquerda);
        imprimir_pre_ordem(a->direita);
    }
}

void imprime_pos_ordem(AB *a) {
    //Se a existe, imprime a esquerda, em seguida a direita e ao final a raiz (a).
    if (a != NULL) {
        imprime_pos_ordem(a->esquerda);
        imprime_pos_ordem(a->direita);

        printf("%d \n", a->info);
    }
}

void imprime_ordem_simetrica(AB *a) {
    //Se a existe, imprime a esquerda de a, a(raiz) e a direita de a.
    if (a != NULL) {
        imprime_ordem_simetrica(a->esquerda);
        
        printf("%d \n", a->info);

        imprime_ordem_simetrica(a->direita);
    }
}

AB * busca (AB *raiz, int elemento) {
    //Se a raiz não existe, ou se o elemento requerido já é a raiz, retorna a raiz.
    if ((raiz == NULL) || (raiz->info == elemento)) {
        return raiz;
    }

    //Busca a esquerda, e caso o elemento requerido esteja à esquerda, retorna a resposta.
    AB *resp = busca(raiz->esquerda, elemento);
    if (resp != NULL) {
        return resp;
    }

    //Caso contrário, procura na direita.
    return busca(raiz->direita, elemento);
}


int maior(int x, int y) {
    if (x >= y) {
        return x;
    }
    return y;
}

//Calcular a altura de uma árvore dada a sua raiz.
int altura(AB *a) {
    if (a == NULL) {
        return -1;
    }

    return 1 + maior(altura(a->esquerda), altura(a->direita));

}

void libera(AB *a) {
    if (a != NULL) {
        libera(a->esquerda);
        libera(a->direita);
        free(a);
    }
}

void main() {

}



















