#include <stdio.h>
#include <stdlib.h>
#include "TAD_Compartimento.h"

void InicializaCompatimento(GerenciadorCompartimento* gerenciadorCompartimento){
    gerenciadorCompartimento->primeiro = InicioDoCompatimento;
    gerenciadorCompartimento->ultimo = gerenciadorCompartimento->primeiro;
}

int VerificaSeEstaVazio(GerenciadorCompartimento* gerenciadorCompartimento){
    return (gerenciadorCompartimento->ultimo == gerenciadorCompartimento->primeiro);
}

int InsereRochaNoCompatimento(GerenciadorCompartimento* gerenciadorCompartimento, Compartimento compartimento){
    if(gerenciadorCompartimento->ultimo == TamanhoMaximo) return 0;

    gerenciadorCompartimento->compartimentos[gerenciadorCompartimento->ultimo++] = compartimento;
    return 1;
}

int RetiraRochaDoCompatimento(GerenciadorCompartimento* gerenciadorCompartimento, int apontador, Compartimento *pX){
    int contador;

    if(VerificaSeEstaVazio(gerenciadorCompartimento) || apontador >= gerenciadorCompartimento->ultimo || apontador < 0) return 0;

    *pX = gerenciadorCompartimento->compartimentos[apontador];

    gerenciadorCompartimento->ultimo--;

    for (contador = 0; contador < gerenciadorCompartimento->ultimo; contador++)
    {
        gerenciadorCompartimento->compartimentos[contador - 1] = gerenciadorCompartimento->compartimentos[contador];

        return 1;
    }
    
}

void ImprimeRochasDoCompatimento(GerenciadorCompartimento* gerenciadorCompartimento){
    for (int i = gerenciadorCompartimento->primeiro; i < gerenciadorCompartimento->ultimo; i++)
    {
        TransformarCategoria(&gerenciadorCompartimento->compartimentos[i]._RochaMineral);
        printf(" %.1f", gerenciadorCompartimento->compartimentos[i]._RochaMineral.Peso);
        printf("\n");
    }
    printf("\n");   
}
