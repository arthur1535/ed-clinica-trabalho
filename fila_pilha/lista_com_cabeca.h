#ifndef LISTA_HEAD_H
#define LISTA_HEAD_H

//Dados
typedef struct no_lista {
  int dado;
  struct no_lista *prox;
} ListaNo;
 
//Fun��es
ListaNo* lista_criar_lista();
void lista_destruir_lista(ListaNo **L);

//Imprimir
void lista_imprimir_lista(ListaNo *L);

//Adicionar
void lista_adicionar_inicio(ListaNo *L, int x);
void lista_adicionar_final(ListaNo *L, int x);

//Remover
void lista_remover_inicio(ListaNo *L);
void lista_remover_final(ListaNo *L);
void lista_remover_valor(ListaNo *L, int x);

//Buscar
int lista_buscar_valor(ListaNo *L, int x);

//Extra
int lista_tamanho_lista(ListaNo *L);
int lista_acessar_primeiro(ListaNo *L);

#endif



