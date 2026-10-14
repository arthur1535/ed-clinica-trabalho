#include "lista_circular.h"
#include <stdlib.h>
#include <stdio.h>

CircularNo* criar_lista() {
  return NULL; 
} 

void destruir_lista(CircularNo **p) {//vers�o iterativa
  if(*p == NULL) return;// lista vazia
  CircularNo *q = (*p)->prox, *aux;
  while(q != *p){
    aux = q;
    q = q->prox;
    free(aux);
  }
  free(*p);
  *p = NULL;
}

//Inser��o

void adicionar_inicio(CircularNo** p, int x){//p recebe |$\&$|L
  CircularNo *q = (CircularNo*) malloc(sizeof(CircularNo));
  q->dado = x;
  if(*p == NULL){ //lista vazia
    *p = q;
    q->prox = q;
  }
  else{
    q->prox = (*p)->prox;
    (*p)->prox = q;
  }
}

void adicionar_final(CircularNo **p, int x) {// p recebe L
  CircularNo *q = (CircularNo*) malloc(sizeof(CircularNo));
  q->dado = x;
  if(*p == NULL){ //lista vazia
    *p = q;
    q->prox = q;
  }
  else{
    q->prox = (*p)->prox;
    (*p)->prox = q;
    *p = q;
  }
}

//Imprimir

void imprimir_lista(CircularNo *p) { // p recebe L
  CircularNo* q, *aux = p;
  if(p!=NULL){
    for (q = p->prox; q != aux; q = q->prox) printf("%d -> ", q->dado);
    printf("%d -> ", q->dado);
  }
  printf("NULL\n");
}

//Buscar
int buscar_valor(CircularNo *p, int x) {// q recebe L
  if(p==NULL) return -1; //lista vazia
  CircularNo *q = p;
  p = p->prox;
  while(p != q){
    if(p->dado == x) return 1; //true!
      p = p->prox;
  }
  if(p->dado == x) return 1; //true!
  return 0;//false == n�o encontrou
}

//Remo��o

void remover_inicio(CircularNo **p) {// p recebe L
  if(*p==NULL) return; //lista vazia
  CircularNo* q = *p; 
  if(q->prox==q){//1 �nico n�
    free(q); *p = NULL;
    return;
  }    
  q = q->prox;  
  (*p)->prox = q->prox;
  free(q);
}
  
void remover_final(CircularNo **p) {// p recebe L
  if(*p==NULL) return; //lista vazia
  CircularNo* q = *p; 
  if(q->prox==q){//1 �nico n�
    free(q); *p = NULL;
    return;
  }    
  CircularNo *aux = q;
  while(q->prox != aux) q = q->prox;  
  q->prox = aux->prox;
  *p = q;
  free(aux);
}

void remover_valor(CircularNo **p, int x) {// p recebe |$\&$|L
  if(*p==NULL) return; //lista vazia
  CircularNo *q = *p;
  if(q->prox == q && q->dado == x){//1 �nico n�
    free(q); *p = NULL;
    return;
  }
  while(q->prox != *p && (q->prox)->dado != x) q = q->prox;
  if((q->prox)->dado == x){//encontrou
    CircularNo *aux = q->prox;
    q->prox = aux->prox;
    if(*p == aux)//�ltimo elemento
      *p = q;
    free(aux);
  }
}

int tamanho_lista(CircularNo *p){
  if(p==NULL) return 0; //lista vazia
  CircularNo *q = p; 
  int tam=1;
  for(p = p->prox; p != q; p = p->prox) tam++;
return tam;
}

int acessar_primeiro(CircularNo *p){
  if(p==NULL) return -1; //lista vazia
  CircularNo *q = p->prox; 
return q->dado;
}

void avancar_lista(CircularNo **p) {
  if (*p != NULL) *p = (*p)->prox;
}
























//


