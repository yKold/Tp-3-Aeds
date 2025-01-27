#ifndef TAD_COMPARTIMENTO
#define TAD_COMPARTIMENTO
#include "Rocha_Mineral/TAD_RochaMineral.h"
#define InicioDoCompatimento 0
#define TamanhoMaximo 10000

typedef struct PreCelulaMineral{
    RochaMineral _RochaMineral;
} Compartimento;

typedef struct {
    Compartimento compartimentos[TamanhoMaximo];
    int primeiro, ultimo;
} GerenciadorCompartimento;

void InicializaCompatimento(GerenciadorCompartimento* gerenciadorCompartimento);

int VerificaSeEstaVazio(GerenciadorCompartimento* gerenciadorCompartimento);

int InsereRochaNoCompatimento(GerenciadorCompartimento* gerenciadorCompartimento, Compartimento compartimento);

int RetiraRochaDoCompatimento(GerenciadorCompartimento* gerenciadorCompartimento, int apontador, Compartimento *pX);

void ImprimeRochasDoCompatimento(GerenciadorCompartimento* gerenciadorCompartimento);


#endif