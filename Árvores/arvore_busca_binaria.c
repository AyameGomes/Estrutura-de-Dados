#include <stdio.h>
#include <stdlib.h>

//Uma árvore binária de busca (ABB) é uma árvore binária (AB) com as seguintes propriedades:
//Todos os elementos da subárvore esquerda são menores que a sua raíz.
//Todos os elementos da direita são maiores que a sua raíz.

typedef struct arvore_binaria_de_busca {
    int info;
    struct arvore_binaria_de_busca *esquerda, *direita;
} ABB;

//Funções de inicializar, imprimir, liberar, criar e medir altura se mantem as mesmas de uma árvore binária ordinária.

ABB *ABB_busca (ABB *a, int elemento) {
    //Caso o elemento não exista ou a própria raíz recebida seja o elemento, retorna a raíz.
    if ((a == NULL) || (a->info) == elemento) {
        return a;
    }

    //Caso a raíz seja maior que o elemento, faz a busca pela esquerda.
    if (a->info > elemento) {
        return ABB_busca(a->esquerda, elemento);
    }

    //Caso a raíz seja menor que o elemento, faz a busca pela direita.
    if (a->info < elemento) {
        return ABB_busca(a->direita, elemento);
    }
}

ABB * ABB_criar(int raiz, ABB *esquerda, ABB *direita) {
    ABB *novo = (ABB*)malloc(sizeof(ABB));
    
    novo->info = raiz;
    novo->esquerda = esquerda;
    novo->esquerda = direita;

    return novo;
}

ABB *ABB_insere (ABB *a, int elemento) {
    //Caso a árvore esteja vazia, cria uma raiz com o elemento.
    if (a == NULL) {
        return ABB_criar(elemento, NULL, NULL);
    }

    //Caso a raiz seja maior que o elemento, o insere à esquerda.
    else if (a->info > elemento) {
        a->esquerda = ABB_insere(a->esquerda, elemento);
    }

    //Caso a raiz seja menor que o elemento, o insere à direita.
    else if(a->info < elemento) {
        a->direita = ABB_insere(a->direita, elemento);
    }

    return a;
}

ABB *ABB_retira(ABB *a, int elemento) {
    //Caso a raíz não exista.
    if (a == NULL) {
        return a;
    }

    //Caso a raíz seja maior que x, vai pra esquerda.
    if (a->info > elemento) {
        a->esquerda = ABB_retira(a->esquerda, elemento);
    }

    //Caso a raíz seja menor que x, vai pra direita.
    else if (a->info < elemento) {
        a->direita = ABB_retira(a->direita, elemento);
    }

    //Elemento foi encontrado.
    else {
        //Elemento é folha
        if ((a->esquerda == NULL) && (a->direita == NULL)) {
            free(a);
            a = NULL;
        }
        //Se ele é um pai com um filho.
        else if ((a->esquerda == NULL) || (a->direita == NULL)) {
            ABB *temp = a;
            if (a->esquerda) {
                a = a->esquerda;
            }

            else {
                a = a->direita;
            }

            free(temp);
        }

        else {
            ABB *filho = a->esquerda;

            while (filho->direita) {
                filho = filho->direita;
            }
            a->info = filho->info;
            filho->info = elemento;
            a->esquerda = ABB_retira(a->esquerda, elemento);
        }
    }

    return a;
}