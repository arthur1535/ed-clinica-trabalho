CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: main

main: main.o lista_circular.o
	$(CC) $(CFLAGS) -o main.exe main.o lista_circular.o

main.o: main.c lista_circular.h
	$(CC) $(CFLAGS) -c main.c

lista_circular.o: lista_circular.c lista_circular.h
	$(CC) $(CFLAGS) -c lista_circular.c

run: main
	./main.exe

clean:
	cmd /c "del /f /q *.o *.exe 2>nul || exit 0"
