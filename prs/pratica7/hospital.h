#ifndef HOSPITAL_H
#define HOSPITAL_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[21];
    Data nascimento;
} Paciente;

typedef struct {
    Paciente pacientes[1000];
    int n;
} Hospital;

void lePacientes(Paciente*, int);

void bubblesort(Hospital*, int*, int*);
void selectionsort(Hospital*, int*, int*);
void insertionsort(Hospital*, int*, int*);
void mergesort(Hospital*, int*, int*);

#endif // !HOSPITAL_H