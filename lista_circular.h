#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

// Estrutura de um nó da lista encadeada circular
typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Estrutura descritora da Lista Circular Simplesmente Encadeada
// Mantemos ponteiro para o 'fim' (cauda), pois fim->proximo aponta diretamente para o 'inicio'.
// Isso permite inserções no início e no fim em O(1).
typedef struct {
    No *fim;
    int tamanho;
} ListaCircular;

// Cria e inicializa uma lista circular vazia
ListaCircular* criar_lista();

// Insere elemento no início da lista
void inserir_inicio(ListaCircular *l, int valor);

// Insere elemento no fim da lista
void inserir_fim(ListaCircular *l, int valor);

// Remove elemento com valor específico (retorna 1 se sucesso, 0 se não encontrou/vazia)
int remover_elemento(ListaCircular *l, int valor);

// Busca um valor na lista circular (retorna 1 se encontrou, 0 caso contrário)
int buscar_elemento(ListaCircular *l, int valor);

// Imprime os elementos completando 1 volta inteira
void imprimir_lista(ListaCircular *l);

// Demonstra a circularidade dando voltas contínuas (passos) na lista
void simular_giros(ListaCircular *l, int total_passos);

// Retorna a quantidade de elementos
int tamanho_lista(ListaCircular *l);

// Libera toda memória alocada pela lista
void destruir_lista(ListaCircular *l);

#endif // LISTA_CIRCULAR_H
