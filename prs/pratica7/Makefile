all: pratica.o hospital.o
	@gcc pratica.o hospital.o -o exe
	@rm -r pratica.o hospital.o
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
hospital.o: hospital.c
	@gcc hospital.c -c -Wall
run:
	@./exe
