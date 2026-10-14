#include "lista_com_cabeca.h"
#include <stdlib.h>
#include <stdio.h>

ListaNo* lista_criar_lista() {
  ListaNo *q = (ListaNo*) malloc(sizeof(ListaNo));
  q->dado = 0;
  q->prox = NULL;
return q; 
} 

void destruir_iterativo(ListaNo **p) { //vers�o iterativa
  ListaNo *q;
  while(*p != NULL){
    q = *p;
    *p = (*p)->prox;
    free(q);
  }
}

void destruir_recursivo(ListaNo *p) { //vers�o recursiva
  if (p != NULL) {
    destruir_recursivo(p->prox);
    free(p);
  }
}

void lista_destruir_lista(ListaNo **p){
  destruir_iterativo(p);
  //destruir_recursivo(*p); *p = NULL;
}

//Inser��o

void lista_adicionar_inicio(ListaNo *p, int x) {// p recebe L
  ListaNo* q = (ListaNo*) malloc(sizeof(ListaNo));
  q->dado = x;
  q->prox = p->prox;
  p->prox = q;
  p->dado++;
}

void lista_adicionar_final(ListaNo *p, int x) {// p recebe L
  ListaNo *q, *aux;
  q = (ListaNo*) malloc(sizeof(ListaNo));
  q->dado = x;
  q->prox = NULL;
  aux = p;
  while (aux->prox != NULL) aux = aux->prox;
  aux->prox = q;
  p->dado++;
}

//Imprimir

void lista_imprimir_lista(ListaNo *p) { //vers�o iterativa
  ListaNo* q;
  for (q = p->prox; q != NULL; q = q->prox) printf("%d -> ", q->dado);
  printf("NULL\n");
}

//Buscar
int lista_buscar_valor(ListaNo *p, int x) {// q recebe L
  p = p->prox;
  while(p != NULL){
    if(p->dado == x) return 1; //true!
      p = p->prox;
  }
  return 0;//false == n�o encontrou
}

//Remo��o

void lista_remover_inicio(ListaNo *p) {// p recebe L
  ListaNo* q = p->prox; 
  if(q==NULL) return; //lista vazia    
  p->prox = q->prox;  
  free(q);
  p->dado--;
}
  
void lista_remover_final(ListaNo *p) {// p recebe L
  ListaNo* q = p;
  if(q->prox!=NULL){
    while (q->prox->prox != NULL)
      q = q->prox;
    ListaNo* aux = q->prox;
    q->prox = NULL;
    free(aux);
    p->dado--;
  }
}

void lista_remover_valor(ListaNo *p, int v) {// p recebe |$\&$|L
  ListaNo* q = p;  
  while (q->prox != NULL){
    if(q->prox->dado==v) break;
    q = q->prox;
  }
  if(q->prox==NULL) return; //n�o encontrou o dado
  ListaNo* tmp = q->prox;
  q->prox = tmp->prox;
  free(tmp);
  p->dado--;
}

int lista_tamanho_lista(ListaNo *p){
  return p->dado;
}

int lista_acessar_primeiro(ListaNo *p){
  if(p->prox==NULL) return -1; //lista vazia 
  return (p->prox)->dado;
}



