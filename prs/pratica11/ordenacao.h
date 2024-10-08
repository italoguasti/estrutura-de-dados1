# ifndef ordena_linear_h
# define ordena_linear_h

#define MAX_M 7
#define MAX_N 10000

typedef struct {
    int senha;
    char nome[21];
} Paciente;

/** 
 * Manter como especificado
 * Funcao auxiliar para converter um char em um inteiro
 * Args:
 *   pacientes = vetor onde devem ser salvos os valores lidos
 *   n = tamanho do vetor pacientes
 **/ 
void le(Paciente* pacientes, int n);

/** 
 * Manter como especificado
 * Imprime a saida 
 * Args:
 *   pacientes = vetor onde devem ser salvos os valores lidos
 *   n = tamanho do vetor pacientes
 **/ 
void imprime(Paciente* pacientes, int n);

/** 
 * Manter como especificado
 * Ordena o vetor
 * Args:
 *   pacientes = vetor onde devem ser salvos os valores lidos
 *   n = tamanho do vetor pacientes
 *   m = numero de digitos
 **/ 
void ordenar(Paciente* pacientes, int n);

# endif // ordena_linear_h
