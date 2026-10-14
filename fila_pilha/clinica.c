#include <stdio.h>
#include "lista_com_cabeca.h"
#include "lista_circular.h"
#include "fila.h"
#include "pilha.h"

static void menu(void) {
  printf("\n=== Clinica VidaSaudavel ===\n");
  printf(" 1 - Cadastrar paciente\n");
  printf(" 2 - Buscar paciente\n");
  printf(" 3 - Remover paciente\n");
  printf(" 4 - Listar pacientes\n");
  printf(" 5 - Cadastrar medico de plantao\n");
  printf(" 6 - Avancar plantao\n");
  printf(" 7 - Remover medico atual\n");
  printf(" 8 - Listar escala medica\n");
  printf(" 9 - Colocar paciente na fila\n");
  printf("10 - Atender proximo paciente\n");
  printf("11 - Desfazer ultimo atendimento\n");
  printf("12 - Listar sala de espera\n");
  printf("13 - Listar historico\n");
  printf(" 0 - Sair\n");
  printf("Opcao: ");
}

static int ler_inteiro(const char *mensagem) {
  int valor;
  printf("%s", mensagem);
  while (scanf("%d", &valor) != 1) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("Entrada invalida. %s", mensagem);
  }
  return valor;
}

static void listar_fila(Fila *fila) {
  if (fila_tamanho(fila) == 0) {
    printf("Sala de espera vazia.\n");
    return;
  }
  printf("Sala de espera (FIFO): ");
  imprimir_lista(fila->L);
}

static void listar_historico(Pilha *historico) {
  if (pilha_tamanho(historico) == 0) {
    printf("Historico vazio.\n");
    return;
  }
  printf("Historico (topo primeiro): ");
  lista_imprimir_lista(historico->L);
}

int main(void) {
  ListaNo *pacientes = lista_criar_lista();
  CircularNo *medicos = criar_lista();
  Fila *espera = fila_criar();
  Pilha *historico = pilha_criar();
  int opcao;

  do {
    menu();
    opcao = ler_inteiro("");
    switch (opcao) {
      case 1: {
        int id = ler_inteiro("ID do paciente: ");
        if (id < 0 || lista_buscar_valor(pacientes, id))
          printf("ID invalido ou ja cadastrado.\n");
        else {
          lista_adicionar_final(pacientes, id);
          printf("Paciente %d cadastrado.\n", id);
        }
        break;
      }
      case 2: {
        int id = ler_inteiro("ID do paciente: ");
        printf(lista_buscar_valor(pacientes, id) ?
          "Paciente encontrado.\n" : "Paciente nao encontrado.\n");
        break;
      }
      case 3: {
        int id = ler_inteiro("ID do paciente: ");
        if (lista_buscar_valor(pacientes, id)) {
          lista_remover_valor(pacientes, id);
          printf("Paciente removido do cadastro.\n");
        } else printf("Paciente nao encontrado.\n");
        break;
      }
      case 4:
        printf("Pacientes cadastrados: ");
        lista_imprimir_lista(pacientes);
        break;
      case 5: {
        int id = ler_inteiro("ID do medico: ");
        if (id < 0 || (tamanho_lista(medicos) > 0 && buscar_valor(medicos, id)))
          printf("ID invalido ou medico ja cadastrado.\n");
        else {
          adicionar_final(&medicos, id);
          printf("Medico %d entrou na escala.\n", id);
        }
        break;
      }
      case 6:
        if (tamanho_lista(medicos) == 0) printf("Nao ha medicos na escala.\n");
        else { avancar_lista(&medicos); printf("Plantao avancado. Atual: %d\n", acessar_primeiro(medicos)); }
        break;
      case 7:
        if (tamanho_lista(medicos) == 0) printf("Nao ha medicos na escala.\n");
        else { printf("Medico %d removido da escala.\n", acessar_primeiro(medicos)); remover_inicio(&medicos); }
        break;
      case 8:
        printf("Escala (a partir do plantonista atual): ");
        imprimir_lista(medicos);
        break;
      case 9: {
        int id = ler_inteiro("ID do paciente: ");
        if (!lista_buscar_valor(pacientes, id)) printf("Paciente nao cadastrado.\n");
        else { fila_adicionar(&espera, id); printf("Paciente %d entrou na fila.\n", id); }
        break;
      }
      case 10:
        if (fila_tamanho(espera) == 0) printf("Sala de espera vazia.\n");
        else if (tamanho_lista(medicos) == 0) printf("Nao ha medico de plantao.\n");
        else {
          int paciente = fila_topo(espera), medico = acessar_primeiro(medicos);
          fila_remover(&espera);
          pilha_adicionar(&historico, paciente);
          printf("Paciente %d atendido pelo medico %d.\n", paciente, medico);
          avancar_lista(&medicos);
        }
        break;
      case 11:
        if (pilha_tamanho(historico) == 0) printf("Nao ha atendimento para desfazer.\n");
        else {
          int paciente = pilha_topo(historico);
          pilha_remover(&historico);
          fila_adicionar(&espera, paciente);
          printf("Atendimento do paciente %d desfeito; paciente voltou para a fila.\n", paciente);
        }
        break;
      case 12: listar_fila(espera); break;
      case 13: listar_historico(historico); break;
      case 0: printf("Encerrando.\n"); break;
      default: printf("Opcao invalida.\n");
    }
  } while (opcao != 0);

  lista_destruir_lista(&pacientes);
  destruir_lista(&medicos);
  fila_destruir(&espera);
  pilha_destruir(&historico);
  return 0;
}
