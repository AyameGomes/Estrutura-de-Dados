#include <stdio.h>
#include <stdlib.h>

//Vizinhos aos quais os nós do grafo estão ligados. 
typedef struct vizinho {
    int id;
    struct no *prox_vizinho;
} VIZINHO;

//Nós do grafo. 
typedef struct grafo {
    int no;
    VIZINHO *primeiro_vizinho;
    struct grafo * prox_no;
} GRAFO;

GRAFO * grafo_inicializa (void) {
    return NULL;
}

GRAFO * grafo_busca_no (GRAFO *g, int elemento) {
    GRAFO *resposta = g;

    while ((resposta) && (resposta->no != elemento)) {
        resposta = resposta->prox_no;
    }

    return resposta;
} 

VIZINHO *vizinho_busca_aresta (GRAFO *g, int elemento, int elemento2) {
    GRAFO *p = grafo_busca_no(g, elemento);

    if (!p) {
        return NULL;
    }

    VIZINHO *vizinho = p->primeiro_vizinho;

    while ((vizinho) && (vizinho->id != elemento2)) {
        vizinho = vizinho->prox_vizinho;
    }

    return vizinho;
}

GRAFO *grafo_insere_no (GRAFO *g, int elemento ) {
    GRAFO *p = g;

    //Verifica se o elemento já existe no grafo.
    while ((p != NULL) && (p->no != elemento)) {
        p = p->prox_no;
    }

    //Caso o nó não exista.
    if (p == NULL) {
        GRAFO *novo = (GRAFO*)malloc(sizeof(GRAFO));
        novo->no = elemento;
        novo->primeiro_vizinho = NULL;
        novo->prox_no = g;
        return novo;
    }

    //Caso o nó já exista.
    return g;
} 