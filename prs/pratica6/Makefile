all: pratica.o lista.o pilha.o
	@gcc pratica.o lista.o pilha.o -o exe
	@rm -r pratica.o lista.o pilha.o
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
lista.o: lista.c
	@gcc lista.c -c -Wall
pilha.o: pilha.c
	@gcc pilha.c -c -Wall
run:
	@./exe