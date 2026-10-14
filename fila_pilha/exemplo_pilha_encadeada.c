#include <stdio.h>
#include "pilha.h"

int main(){
  int i, num;
  Pilha *F = pilha_criar();
  printf("%p\n", F);
  scanf("%d", &num);
  for(i=1; i<=num; i++) pilha_adicionar(&F, i);
  while(pilha_tamanho(F) > 0){
    printf("%d\n", pilha_topo(F));
    pilha_remover(&F);
  }
  printf("%p\t%p\n", F, &(F->L));
  pilha_destruir(&F); //testar valgrind!! 
return 0;
}
