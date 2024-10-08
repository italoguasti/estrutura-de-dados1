all: pratica.o seno.o
	@gcc pratica.o seno.o -o exe
	@rm -r pratica.o seno.o
seno.o: seno.c
	@gcc seno.c -c -lm -Wall
pratica.o: pratica.c
	@gcc pratica.c -c -lm -Wall
run:
	@./exe
