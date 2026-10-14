CC = gcc
CFLAGS = -Wall -Wextra -g

all: clinica exemplo_fila exemplo_pilha_vetor exemplo_pilha_encadeada

clinica: clinica.c fila.o pilha.o lista_circular.o lista_com_cabeca.o
	$(CC) $(CFLAGS) $^ -o $@.exe

exemplo_fila: exemplo_fila.c fila.o lista_circular.o
	$(CC) $(CFLAGS) $^ -o $@.exe

exemplo_pilha_vetor: exemplo_pilha_vetor.c pilha_vetor.o
	$(CC) $(CFLAGS) $^ -o $@.exe

exemplo_pilha_encadeada: exemplo_pilha_encadeada.c pilha.o lista_com_cabeca.o
	$(CC) $(CFLAGS) $^ -o $@.exe

# Regra genérica para compilação dos módulos
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Aliases de compatibilidade
exemplo1: exemplo_fila
exemplo2: exemplo_pilha_vetor
exemplo3: exemplo_pilha_encadeada

clean:
	cmd /c "del /f /q *.o *.exe 2>nul || exit 0"
