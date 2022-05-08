#include <stdio.h>
#include <stdlib.h>

typedef struct lse {
    int info;
    struct lse *prox;
} TLSE;

TLSE *TLSE_retira (TLSE *l, int elemento) {
    TLSE *ponteiro = l, *ant = NULL;

    while((ponteiro != NULL) && (ponteiro->info != elemento)) {
        ant = ponteiro;
        ponteiro = ponteiro->prox;
    }

    //caso o elemento não exista
    if (ponteiro == NULL) {
        return l;
    }

    //caso seja o primeiro elemento da lista
    if (ant == NULL) {
        l = l->prox;
    }

    else {
        ant->prox = ponteiro->prox;
    } 

    free(ponteiro);
    return l;
}

TLSE *TLSE_retira_recursivo(TLSE *l, int elemento) {
    if (l == NULL) {
        return l;
    }

    if (l->info == elemento) {
        TLSE *ponteiro = l;
        l = l->prox;
        free(ponteiro);
    }
    else {
        l->prox = TLSE_busca_recursivo(l->prox, elemento);
    }

    return l;
}

TLSE *TLSE_insere_ordenado(TLSE *l, int elemento) {
    TLSE *p = l, *anterior = NULL;

    while ((p != NULL) && (p->info < elemento)) {
        anterior = p;
        p = p->prox;
    }

    if (anterior = NULL) {
        return TLSE_inserir_inicio(l, elemento);
    }

    p = TLSE_inserir_inicio(p, elemento);
    anterior->prox = p;
    return l;
}

TLSE *TLSE_insere_ordenado_recursivo(TLSE *l, int elemento) {
    if ((l == NULL) || (l->info >= elemento)) {
        return TLSE_inserir_inicio(l, elemento);
    }

    l->prox = TLSE_insere_ordenado_recursivo(l->prox, elemento);
    return l;
}

TLSE *TLSE_inicializa(void) {
    return NULL;
}

TLSE *TLSE_inserir_inicio(TLSE *l, int elemento) {
    TLSE *novo = (TLSE *) malloc(sizeof(TLSE));

    novo->info = elemento;
    novo->prox = l;
    return novo;
}

TLSE *TLSE_busca (TLSE *l, int elemento) {
    TLSE *resposta = l;

    while ((resposta != NULL) && (resposta->info != elemento)) {
        resposta = resposta->prox;
    }

    return resposta;
}

TLSE *TLSE_busca_recursivo (TLSE *l, int elemento) {
    if ((l == NULL) || (l->info == elemento)) {
        return ;
    }

    return TLSE_busca_recursivo(l->prox, elemento);
}

TLSE *TLSE_inserir_fim(TLSE *l, int elemento) {
    TLSE *p = l, *novo;
    p = l;
    novo ->info = elemento;
    novo ->prox = NULL;

    if (l == NULL) {
        return novo;
    }

    while (p -> prox != NULL) {
        p = p->prox;
    }

    p ->prox = novo;
    return l;
}

TLSE *TLSE_inserir_fim_recursivo(TLSE *l, int elemento) {
    if (l == NULL) {
        return TLSE_inserir_inicio(l, elemento);
    }

    TLSE_inserir_fim_recursivo(l->prox, elemento);
    return l; 
}

void imprime_lista(TLSE *l) {
    TLSE *p = l;

    while (p ->prox != NULL) {
        printf("%d \n", p->info);
        p = p->prox;
    }
    printf("%d \n", p->info);
}

void imprime_lista_recursivo(TLSE *l) {
    if (l != NULL) {
        printf("%d \n", l->info);
        imprime_lista_recursivo(l->prox);
    }
}

void imprime_lista_recursivo_reverso(TLSE *l) {
    if (l != NULL) {
        imprime_lista_recursivo_reverso(l->prox);
        printf("%d \n", l->info);
    }
}

void main() {
    int n;
    TLSE *l = TLSE_inicializa();
    do {
        printf("Digite um número inteiro: \n");
        scanf("%d", &n);

        if(n < 0) {
            imprime_lista(l);
            printf("Fim do programa. \n");
            break;
        }

        l = TLSE_inserir_inicio(l, n);

    } while(1);
}