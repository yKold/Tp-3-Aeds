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
        (*comparacoes)++;

        while (pivo._RochaMineral.Peso < gerenciadorCompartimento->compartimentos[*j]._RochaMineral.Peso) {
            (*comparacoes)++;
            (*j)--;
        }
        (*comparacoes)++;

        if (*i <= *j) {
            aux = gerenciadorCompartimento->compartimentos[*i];
            gerenciadorCompartimento->compartimentos[*i] = gerenciadorCompartimento->compartimentos[*j];
            gerenciadorCompartimento->compartimentos[*j] = aux;
            (*movimentacoes) += 3;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, GerenciadorCompartimento* gerenciadorCompartimento, int* comparacoes, int* movimentacoes) {
    int i, j;
    Particao(Esq, Dir, &i, &j, gerenciadorCompartimento, comparacoes, movimentacoes);
    if (Esq < j) Ordena(Esq, j, gerenciadorCompartimento, comparacoes, movimentacoes);
    if (i < Dir) Ordena(i, Dir, gerenciadorCompartimento, comparacoes, movimentacoes);
}

void QuickSort(GerenciadorCompartimento* gerenciadorCompartimento, int ultimo, int* comparacoes, int* movimentacoes) {
    *comparacoes = 0;
    *movimentacoes = 0;
    Ordena(0, ultimo - 1, gerenciadorCompartimento, comparacoes, movimentacoes);
}
