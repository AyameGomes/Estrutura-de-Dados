#include <stdio.h>
#include <stdlib.h>

//É uma árvore de busca binária balanceada (tem a quantidade de elementos aproximadamente igual em cada lado).
//A altura da subárvore esquerda difere da altura da subárvore direita em, no máximo, 1 nível.

typedef struct avl {
    int info;
    struct avl *esquerda, *direita;
    int alt;
} AVL;

//Operações válidas:
//Busca (de abb).
//Libera (de ab).
//Impressão (de ab).
//Inicialização (de ab).

int getHeight(AVL *n){
    if(n==NULL)
        return 0;
    return n->alt;
}

//Rotação simpls à esquerda(RSE).
//FB(p) = -2.
//FB(d) = -1.
AVL *RSE (AVL *p) {
    AVL *novo = p->direita;

    p->direita = novo->esquerda;
    novo->esquerda = p;

    p->alt = max(getHeight(p->direita), getHeight(p->esquerda)) + 1;
    novo->alt = max(getHeight(novo->direita), p->alt) + 1;

    return novo;
}

//Rotação simpls à direita(RSD).
//FB(p) = 2.
//FB(e) = 1.
AVL *RSD (AVL *p) {
    AVL *novo = p->esquerda;

    p->esquerda = novo->direita;
    novo->direita = p;

    p->alt = max(getHeight(p->esquerda), getHeight(p->direita)) + 1;
    novo->alt = max(getHeight(novo->esquerda), p->alt);

    return novo;
}

//Rotação direita-esquerda(RDE).
//FB(p) = 2.
//FB(d) = 1.
AVL *RDE (AVL *p) {
    p->direita = RSD(p->direita);
    p = RSE(p);

    return p;
}

//Rotação esquerda-direita(RED).
//FB(p) = 2.
//FB(d) = -1.
AVL *RED (AVL *p) {
    p->esquerda = RSE(p->esquerda);
    p = RSD(p);

    return p;
}
 
AVL *insere(AVL *a, int x) {
    //Se a raíz for nula, chama a função de criação.
    if (a == NULL) {
        return AVL_cria(x, NULL, NULL);
    }

    //Se o elemento for menor que a raíz, significa que o elemento está à esquerda.
    if (x < a->info) {
        a->esquerda = insere(a->esquerda, x);

        if(FB(a) == 2) {
            if (a < a->esquerda->info) {
                a = RSD(a);
            }
            else {
                a = RED(a);
            }
        }
    }

    //Se o elemento é maior que a raíz, significa que está à direita.
    else if (x > a->info) {
        a->direita = insere(a->direita, x);

        if(FB(a) == 2) {
            if (x > a->direita->info) {
                a = RES(a);
            }
            else {
                a = RDE(a);
            }
        }
    }

    a->alt = max(getHeight(a->esquerda), getHeight(a->direita)) + 1;

    return a;
}

//Remoção:
//Folha: free no nó e retorna NULL.
//1 filho: free no pai e retorna o filho.
//2 filhos: ida para à esquerda.
//Obter o elemento mais à direita substituindo à raíz.
//Chamada recursiva à partir de a->esquerda para retirar o elemento. 