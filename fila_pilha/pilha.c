#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

Pilha* pilha_criar() {
  Pilha *p = (Pilha*) malloc(sizeof(Pilha));
  p->L = lista_criar_lista();
return p; 
} 

void pilha_destruir(Pilha **p) {// p recebe &F
  lista_destruir_lista(&((*p)->L));
  free(*p); //testar valgrind!
  *p = NULL;
}

//Inser��o

void pilha_adicionar(Pilha **p, int x) {// p recebe &F
  lista_adicionar_inicio((*p)->L, x);
}

//Acessar

int pilha_topo(Pilha *p) {// p recebe F
  return lista_acessar_primeiro(p->L);
}

//Remo��o

void pilha_remover(Pilha **p) {// p recebe &L
  lista_remover_inicio((*p)->L);
}

//Tamanho

int pilha_tamanho(Pilha *p) {// p recebe L
  return lista_tamanho_lista(p->L);
}


