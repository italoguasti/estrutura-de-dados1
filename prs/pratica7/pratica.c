#include <stdio.h>
#include "hospital.h"

int main() {
    Hospital hospital, aux;
    int comp, mov;

    // Ler a quantidade de pacientes no hospital
    scanf("%d", &hospital.n);

    // Ler as informacoes dos pacientes
    lePacientes(hospital.pacientes, hospital.n);

    printf("Analise.....: Comp | Movi\n");

    // Copiar os dados de um hospital e executar o bubble sort
    aux = hospital;
    bubblesort(&aux, &comp, &mov);

    printf("- Bubble....: %04d | %04d\n", comp, mov);

    // Copiar os dados de um hospital e executar o selection sort
    aux = hospital;
    selectionsort(&aux, &comp, &mov);
    printf("- Selection.: %04d | %04d\n", comp, mov);

    // Copiar os dados de um hospital e executar o insertion sort
    aux = hospital;
    insertionsort(&aux, &comp, &mov);
    printf("- Insertion.: %04d | %04d\n", comp, mov);

    return 0;
}
