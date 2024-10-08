#ifndef duende_h
#define duende_h

typedef struct {
    char nome[21];
    int idade;
    int escalado;
} Duende;

typedef struct {
    char nomeLider[21];
    int idadeLider;
    char nomeConfeiteiro[21];
    int idadeConfeiteiro;
    char nomeEntregador[21];
    int idadeEntregador;
    char nomeEmbrulhador[21];
    int idadeEmbrulhador;
} Time;

typedef enum { NAO=0, SIM } ESCALADO;

void lerQuantidade(int*);
Duende *alocaDuendes(int);
Time *alocaTimes(int);
void desalocaDuendes(Duende**);
void desalocaTimes(Time**);
void lerDuendes(Duende*, int);
void escalarTimes(Duende*, Time*, int);
int proximoMaisVelho(Duende*, int);
void printTimes(Time*, int);

#endif
