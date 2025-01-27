#include "Compartimento/TAD_Compartimento.h"

void Particao(int Esq, int Dir, int* i, int* j, GerenciadorCompartimento* gerenciadorCompartimento, int* comparacoes, int* movimentacoes) {
    Compartimento pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = gerenciadorCompartimento->compartimentos[(*i + *j) / 2];

    do {
        while (pivo._RochaMineral.Peso > gerenciadorCompartimento->compartimentos[*i]._RochaMineral.Peso) {
            (*comparacoes)++;
            (*i)++;
        }

        while (pivo._RochaMineral.Peso < gerenciadorCompartimento->compartimentos[*j]._RochaMineral.Peso) {
            (*comparacoes)++;
            (*j)--;
        }

        if (*i <= *j) {
            aux = gerenciadorCompartimento->compartimentos[*i];
            gerenciadorCompartimento->compartimentos[*i] = gerenciadorCompartimento->compartimentos[*j];
            gerenciadorCompartimento->compartimentos[*j] = aux;
            (*movimentacoes) ++;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, GerenciadorCompartimento* gerenciadorCompartimento, int* comparacoes, int* movimentacoes) {
    int i, j;
    Particao(Esq, Dir, &i, &j, gerenciadorCompartimento, comparacoes, movimentacoes);
    if (Esq < j) Ordena(Esq, j, gerenciadorCompartimento, comparacoes, movimentacoes);
    (*comparacoes)++;
    if (i < Dir) Ordena(i, Dir, gerenciadorCompartimento, comparacoes, movimentacoes);
    (*comparacoes)++;
}

void QuickSort(GerenciadorCompartimento* gerenciadorCompartimento, int ultimo, int* comparacoes, int* movimentacoes) {
    Ordena(0, ultimo - 1, gerenciadorCompartimento, comparacoes, movimentacoes);
}
