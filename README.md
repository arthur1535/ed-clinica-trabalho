# Estruturas de Dados - Sistema Clínico VidaSaudável & Módulos Didáticos

Repositório acadêmico desenvolvido para a disciplina de **Estruturas de Dados** da **Faculdade de Computação (FACOM) - Universidade Federal de Uberlândia (UFU)**.

O projeto principal consiste no desenvolvimento do **Sistema Clínico VidaSaudável**, integrando de maneira coesa e modular quatro estruturas de dados lineares clássicas, complementado por módulos práticos e documentação técnica formal.

📄 **Relatório Técnico Completo:** [`relatorio_clinica.pdf`](./relatorio_clinica.pdf) (14 páginas detalhando arquitetura, gerenciamento de memória, rastreamento passo a passo e análise assintótica).

---

## 🏥 Sistema Clínico VidaSaudável (Trabalho Principal)

O sistema gerencia o fluxo de atendimento em uma clínica médica, desde a triagem até a consulta com o médico plantonista e histórico auditável reversível.

### 📐 Arquitetura das Quatro Coleções Integradas

| Coleção / Módulo | Estrutura Subjacente | Disciplina | Papel no Sistema | Complexidade |
| :--- | :--- | :--- | :--- | :--- |
| **Pacientes Cadastrados** | Lista Encadeada com Cabeça | Linear com Sentinela | Cadastro permanente de pacientes por ID | Busca: $O(n)$, Rem: $O(n)$ |
| **Escala Médica** | Lista Circular Simples | Anel Cíclico | Plantonistas rotativos da clínica | Inserir/Avançar: $O(1)$ |
| **Sala de Espera** | TAD Fila (composição) | FIFO (First-In, First-Out) | Ordem de atendimento médico | Enfileirar/Desenfileirar: $O(1)$ |
| **Histórico de Consultas** | TAD Pilha (composição) | LIFO (Last-In, First-Out) | Auditoria e reversão de atendimentos (*Undo*) | Empilhar/Desempilhar: $O(1)$ |

### 🔄 Destaques de Engenharia e Design em C
- **Composição de TADs:** O TAD Fila encapsula internamente a Lista Circular (`CircularNo *L`), e o TAD Pilha encapsula internamente a Lista com Cabeça (`ListaNo *L`), garantindo separação rigorosa de interface (`.h`) e implementação (`.c`).
- **Lista com Nó Sentinela:** Elimina casos especiais na manipulação da cabeça da lista encadeada e mantém contador de nós em $O(1)$.
- **Escala Circular em $O(1)$:** A lista circular mantém apenas um ponteiro para a cauda (`*p`), permitindo acessar o primeiro elemento (`(*p)->prox`), inserir no fim e rotacionar o plantão (`*p = (*p)->prox`) em tempo constante.
- **Validação de Entrada (`stdin`):** Tratamento resiliente contra entradas alfanuméricas inválidas, prevenindo *buffer poisoning* ou loops infinitos de `scanf`.
- **Gerenciamento Estrito de Memória:** Zero vazamento de memória (*zero memory leaks*), com funções dedicadas de desalocação por ponteiro duplo (`T**`).

---

## 📋 As 13 Operações do Sistema Clínico

O sistema conta com um menu interativo com 13 funcionalidades completas:

```text
=== Clinica VidaSaudavel ===
 1 - Cadastrar paciente
 2 - Buscar paciente
 3 - Remover paciente
 4 - Listar pacientes
 5 - Cadastrar medico de plantao
 6 - Avancar plantao
 7 - Remover medico atual
 8 - Listar escala medica
 9 - Colocar paciente na fila
10 - Atender proximo paciente
11 - Desfazer ultimo atendimento
12 - Listar sala de espera
13 - Listar historico
 0 - Sair
```

1. **Cadastrar paciente:** Insere novo paciente no cadastro permanente.
2. **Buscar paciente:** Localiza paciente por ID na lista encadeada com cabeça.
3. **Remover paciente:** Desaloca paciente específico do cadastro permanente.
4. **Listar pacientes:** Exibe todos os pacientes cadastrados.
5. **Cadastrar médico:** Insere novo médico no fim da escala circular em tempo $O(1)$.
6. **Avançar plantão:** Rotaciona a escala para o próximo médico em $O(1)$ sem destruir nós.
7. **Remover médico atual:** Remove o médico que está de plantão no momento e transfere o turno para o sucessor imediato.
8. **Listar escala:** Exibe o anel rotativo completo a partir do plantonista atual.
9. **Colocar paciente na fila:** Valida existência no cadastro e insere na sala de espera (Fila FIFO).
10. **Atender próximo:** Desenfileira o paciente mais antigo, encaminha ao médico da vez, empilha no histórico (LIFO) e avança a escala circular.
11. **Desfazer atendimento (Undo):** Desempilha o último paciente atendido do histórico e recoloca-o na sala de espera.
12. **Listar sala de espera:** Exibe a ordem de atendimento da fila FIFO.
13. **Listar histórico:** Exibe o histórico de consultas a partir da mais recente (topo).

---

## 📂 Estrutura das Pastas

```text
.
├── fila_pilha/                  # Sistema Principal da Clínica Médica
│   ├── clinica.c                # Programa integrador interativo
│   ├── fila.c / fila.h          # TAD Fila (implementado sobre Lista Circular)
│   ├── pilha.c / pilha.h        # TAD Pilha (implementado sobre Lista com Cabeça)
│   ├── lista_circular.c / .h    # Lista Circular simplesmente encadeada
│   ├── lista_com_cabeca.c / .h  # Lista Simplesmente Encadeada com Sentinela
│   ├── relatorio_clinica.pdf    # Relatório formal impresso (14 páginas)
│   ├── relatorio_clinica.tex    # Código fonte do relatório em LaTeX
│   └── Makefile                 # Compilação local da pasta
│
├── listas_encadeadas/           # Módulos de Estudo do Professor
│   ├── lista_circular.c / .h    # Implementação de Lista Circular
│   ├── lista_dupla.c / .h       # Implementação de Lista Duplamente Encadeada
│   ├── exemplo_lista_circular.c # Demonstração de operações na lista circular
│   ├── exemplo_lista_dupla.c    # Demonstração de operações na lista dupla
│   └── Makefile                 # Compilação local da pasta
│
├── lista_circular_aula/         # Exercício Didático da Aula 02
│   ├── lista_circular.c / .h    # Lista Circular com ponteiro para o fim (O(1))
│   ├── main.c                   # Demonstração didática com rotações contínuas
│   └── Makefile                 # Compilação local da pasta
│
├── .vscode/                     # Configurações de execução e debug (launch/tasks)
├── Makefile                     # Makefile Mestre
├── relatorio_clinica.pdf        # Relatório acadêmico na raiz do projeto
└── README.md                    # Este manual
```

---

## 🛠️ Como Compilar e Executar

### Opção 1: Usando `make` ou `mingw32-make`

```bash
# Compilar e rodar o Sistema Clínico:
make clinica
./fila_pilha/clinica.exe

# Compilar todos os módulos de uma vez:
make all

# Limpar binários e arquivos intermediários:
make clean
```

### Opção 2: Compilação direta via `gcc`

```bash
cd fila_pilha
gcc -Wall -Wextra clinica.c fila.c pilha.c lista_circular.c lista_com_cabeca.c -o clinica.exe
./clinica.exe
```

### Opção 3: No VS Code
- Abra o painel **Executar e Depurar** (`Ctrl + Shift + D`).
- Selecione o perfil **`▶️ Executar / Depurar Clínica (Clinica VidaSaudavel)`** e pressione **`F5`**.

---

## 👥 Autoria e Licença

Desenvolvido para a disciplina de **Estruturas de Dados (ED)** — Faculdade de Computação, Universidade Federal de Uberlândia (FACOM/UFU).
Distribuído sob licença acadêmica para fins educacionais.
