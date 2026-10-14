#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

//Dados
typedef struct no_circular {
  int dado;
  struct no_circular *prox;
} CircularNo;
 
//Fun��es
CircularNo* criar_lista();
void destruir_lista(CircularNo **L);

//Imprimir
void imprimir_lista(CircularNo *L);

//Adicionar
void adicionar_inicio(CircularNo **L, int x);
void adicionar_final(CircularNo **L, int x);
void avancar_lista(CircularNo **L);

//Remover
void remover_inicio(CircularNo **L);
void remover_final(CircularNo **L);
void remover_valor(CircularNo **L, int x);

//Buscar
int buscar_valor(CircularNo *L, int x);

//Extra
int tamanho_lista(CircularNo *L);
int acessar_primeiro(CircularNo *L);


#endif



