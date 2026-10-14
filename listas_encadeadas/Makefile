CC = gcc
CFLAGS = -Wall -Wextra -g

all: exemplo_lista_circular exemplo_lista_dupla

exemplo_lista_circular: exemplo_lista_circular.c lista_circular.o
	$(CC) $(CFLAGS) $^ -o $@.exe

exemplo_lista_dupla: exemplo_lista_dupla.c lista_dupla.o
	$(CC) $(CFLAGS) $^ -o $@.exe

# Regra genérica para objetos
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Aliases de compatibilidade
exemplo1: exemplo_lista_circular
exemplo2: exemplo_lista_dupla

clean:
	cmd /c "del /f /q *.o *.exe 2>nul || exit 0"
