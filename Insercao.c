#include "Insercao.h"

void Insercao(GerenciadorCompartimento* gerenciadorCompatimento, int ultimoElemento, int* comparacoes, int* movimentacoes) {
    int i, j;
    Compartimento aux;

    for (i = 1; i < ultimoElemento; i++) {
        aux = gerenciadorCompatimento->compartimentos[i];
        j = i - 1;

        while ((j >= 0) && (aux._RochaMineral.Peso < gerenciadorCompatimento->compartimentos[j]._RochaMineral.Peso)) {
            (*comparacoes)+= 2;
            (*movimentacoes)++;
            gerenciadorCompatimento->compartimentos[j + 1] = gerenciadorCompatimento->compartimentos[j];
            j--;
        }
        (*movimentacoes)++;
        gerenciadorCompatimento->compartimentos[j + 1] = aux;
        
    }
}
