# Makefile Principal - ED Aula 02

.PHONY: all aula02 clinica filas listas clean

all: aula02 clinica filas listas

aula02:
	$(MAKE) -C lista_circular_aula
	gcc -Wall -Wextra -g -O0 lista_circular.c main.c -o main.exe

clinica:
	$(MAKE) -C fila_pilha clinica

filas:
	$(MAKE) -C fila_pilha all

listas:
	$(MAKE) -C listas_encadeadas all

clean:
	cmd /c "del /f /q *.o *.exe 2>nul || exit 0"
	$(MAKE) -C lista_circular_aula clean
	$(MAKE) -C fila_pilha clean
	$(MAKE) -C listas_encadeadas clean
