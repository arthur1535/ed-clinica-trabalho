#include "lista_dupla.h"
#include <stdlib.h>
#include <stdio.h>

No* criar_lista() {
  return NULL; 
} 

void destruir_lista(No **p) {//versão iterativa
  if(*p == NULL) return;// lista vazia
  No *q = (*p)->prox, *aux;
  while(q != *p){
    aux = q;
    q = q->prox;
    free(aux);
  }
  free(*p);
  *p = NULL;
}

//Inserção

void adicionar_inicio(No** p, int x){//p recebe |$\&$|L
  No *q = (No*) malloc(sizeof(No));
  q->dado = x;
  if(*p == NULL){ //lista vazia
    *p = q;
    q->prox = q->ant = q;
  }
  else{
    No *aux = *p;
    q->ant  = aux->ant;
    q->prox = aux;
    (aux->ant)->prox = q;
    aux->ant = q;
    *p = q;
  }
}

void adicionar_final(No **p, int x) {// p recebe L
  No *q = (No*) malloc(sizeof(No));
  q->dado = x;
  if(*p == NULL){ //lista vazia
    *p = q;
    q->prox = q->ant = q;
  }
  else{
    No *aux = (*p)->ant;
    (*p)->ant = q;
    q->prox = *p;
    aux->prox = q;
    q->ant  = aux;
  }
}

//Imprimir

void imprimir_lista(No *p) { // p recebe L
  No* q;
  if(p!=NULL){
    No *aux = p->ant; 
    for (q = p; q != aux; q = q->prox) printf("%d -> ", q->dado);
    printf("%d -> ", q->dado);
  }
  printf("NULL\n");
}

//Buscar
int buscar_valor(No *p, int x) {// q recebe L
  if(p==NULL) return -1; //lista vazia
  No *q = p->ant;
  while(p != q){
    if(p->dado == x) return 1; //true!
      p = p->prox;
  }
  if(p->dado == x) return 1; //true!
  return 0;//false == não encontrou
}

//Remoção

void remover_inicio(No **p) {// p recebe L
  if(*p==NULL) return; //lista vazia
  No* q = *p; 
  if(q->prox==q){//1 único nó
    free(q); *p = NULL;
    return;
  }    
  *p = q->prox;  
  (*p)->ant = q->ant;
  (q->ant)->prox = *p;
  free(q);
}
  
void remover_final(No **p) {// p recebe L
  if(*p==NULL) return; //lista vazia
  No* q = (*p)->ant; 
  if(q==*p){//1 único nó
    free(q); *p = NULL;
    return;
  }    
  No *aux = q->ant;
  aux->prox = *p;
  (*p)->ant = aux;
  free(q);
}

void remover_valor(No **p, int x) {// p recebe |$\&$|L
  if(*p==NULL) return; //lista vazia
  No *q = *p;
  if(q->prox == q && q->dado == x){//1 único nó
    free(q); *p = NULL;
    return;
  }
  while(q != (*p)->ant && q->dado != x) q = q->prox;
  if(q->dado == x){//encontrou
    No *aux1 = q->ant;
    No *aux2 = q->prox;
    aux1->prox = aux2;
    aux2->ant  = aux1;
    if(*p == q)//primeiro elemento
      *p = aux2;
    free(q);
  }
}

int tamanho_lista(No *p){
  if(p==NULL) return 0; //lista vazia
  No *q; 
  int tam=1;
  for(q = p; q != p->ant; q = q->prox) tam++; 
  return tam;
}
























//
