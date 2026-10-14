#include <stdio.h>
#include "lista_dupla.h"

int main(){
  int i, num;
  No *L = criar_lista();
  scanf("%d", &num);
  for(i=1; i<=num; i++) adicionar_final(&L, i);
  imprimir_lista(L);
  while(L!=NULL){
    scanf("%d", &i); remover_valor(&L, i);
    imprimir_lista(L);
    printf("[%d]\n", tamanho_lista(L));
  }
  destruir_lista(&L); //testar valgrind!!
return 0;
}
