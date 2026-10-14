#include "lista_circular.h"
#include <stdio.h>
#include <stdlib.h>

ListaCircular* criar_lista() {
    ListaCircular *l = (ListaCircular*) malloc(sizeof(ListaCircular));
    l->fim = NULL;
    l->tamanho = 0;
    return l;
}

void inserir_inicio(ListaCircular *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;

    if (l->fim == NULL) {
        // Caso 1: Lista vazia -> aponta para si próprio
        novo->proximo = novo;
        l->fim = novo;
    } else {
        // Caso 2: Lista com elementos -> novo aponta para o antigo início
        novo->proximo = l->fim->proximo;
        l->fim->proximo = novo;
    }
    l->tamanho++;
}

void inserir_fim(ListaCircular *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;

    if (l->fim == NULL) {
        // Lista vazia: aponta para si próprio e é o fim
        novo->proximo = novo;
        l->fim = novo;
    } else {
        // O novo aponta para o início (l->fim->proximo)
        novo->proximo = l->fim->proximo;
        // O antigo fim aponta para o novo
        l->fim->proximo = novo;
        // O ponteiro fim passa a ser o novo nó
        l->fim = novo;
    }
    l->tamanho++;
}

int remover_elemento(ListaCircular *l, int valor) {
    if (l->fim == NULL) return 0; // Lista vazia

    No *atual = l->fim->proximo; // início
    No *anterior = l->fim;

    for (int i = 0; i < l->tamanho; i++) {
        if (atual->valor == valor) {
            // Se só havia 1 elemento
            if (l->tamanho == 1) {
                l->fim = NULL;
            } else {
                anterior->proximo = atual->proximo;
                // Se removemos o nó marcado como 'fim', atualizamos l->fim
                if (atual == l->fim) {
                    l->fim = anterior;
                }
            }
            free(atual);
            l->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // Não encontrado
}

int buscar_elemento(ListaCircular *l, int valor) {
    if (l->fim == NULL) return 0;

    No *atual = l->fim->proximo; // início
    for (int i = 0; i < l->tamanho; i++) {
        if (atual->valor == valor) return 1;
        atual = atual->proximo;
    }
    return 0;
}

void imprimir_lista(ListaCircular *l) {
    if (l->fim == NULL) {
        printf("Lista vazia: []\n");
        return;
    }

    No *inicio = l->fim->proximo;
    No *atual = inicio;

    printf("[");
    do {
        printf("%d", atual->valor);
        atual = atual->proximo;
        if (atual != inicio) {
            printf(" -> ");
        }
    } while (atual != inicio);
    printf(" -> volta ao %d]\n", inicio->valor);
}

void simular_giros(ListaCircular *l, int total_passos) {
    if (l->fim == NULL) {
        printf("Lista vazia, nada para percorrer.\n");
        return;
    }

    No *atual = l->fim->proximo; // comeca pelo inicio
    printf("Percorrendo %d passos continuamente em loop circular:\n  ", total_passos);
    for (int i = 0; i < total_passos; i++) {
        printf("%d", atual->valor);
        if (i < total_passos - 1) {
            printf(" -> ");
        }
        atual = atual->proximo;
    }
    printf(" ... (continua infinitamente se quiser)\n");
}

int tamanho_lista(ListaCircular *l) {
    return l->tamanho;
}

void destruir_lista(ListaCircular *l) {
    if (l->fim != NULL) {
        No *atual = l->fim->proximo; // inicio
        No *prox = NULL;
        int tam = l->tamanho;

        for (int i = 0; i < tam; i++) {
            prox = atual->proximo;
            free(atual);
            atual = prox;
        }
    }
    free(l);
}
