#include <stdio.h>
#include "lista_circular.h"

int main() {
    printf("=========================================\n");
    printf("   ESTRUTURA DE DADOS: LISTA CIRCULAR   \n");
    printf("=========================================\n\n");

    // 1. Criar a lista
    printf("[1] Criando lista circular vazia...\n");
    ListaCircular *lista = criar_lista();
    imprimir_lista(lista);

    // 2. Inserir elementos no fim
    printf("\n[2] Inserindo no fim: 10, 20, 30...\n");
    inserir_fim(lista, 10);
    inserir_fim(lista, 20);
    inserir_fim(lista, 30);
    imprimir_lista(lista);

    // 3. Inserir no inicio
    printf("\n[3] Inserindo no inicio: 5...\n");
    inserir_inicio(lista, 5);
    imprimir_lista(lista);

    // 4. Demonstracao da caracteristica circular
    printf("\n[4] Demonstracao do comportamento circular:\n");
    // Temos 4 nós: 5 -> 10 -> 20 -> 30. Dando 10 passos:
    simular_giros(lista, 10);

    // 5. Busca
    printf("\n[5] Buscando elemento 20: %s\n", buscar_elemento(lista, 20) ? "Encontrado!" : "Nao encontrado");
    printf("    Buscando elemento 99: %s\n", buscar_elemento(lista, 99) ? "Encontrado!" : "Nao encontrado");

    // 6. Remocao
    printf("\n[6] Removendo 20 (meio)...\n");
    remover_elemento(lista, 20);
    imprimir_lista(lista);

    printf("    Removendo 5 (inicio)...\n");
    remover_elemento(lista, 5);
    imprimir_lista(lista);

    printf("    Removendo 30 (fim)...\n");
    remover_elemento(lista, 30);
    imprimir_lista(lista);

    // 7. Liberar memoria
    printf("\n[7] Destruindo a lista e liberando memoria...\n");
    destruir_lista(lista);
    printf("Concluido com sucesso!\n");

    return 0;
}
