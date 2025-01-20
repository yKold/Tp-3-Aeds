#include "ArquivoDeEntrada.c"
#include "Compartimento/TAD_Compartimento.h"
#include "Insercao.c"
#include "QuickSort.c"
#include "string.h"
#include <time.h>

int main(){
    clock_t inicio, fim;
    double tempoDeExecucao;

    GerenciadorCompartimento* gerenciadorCompartimento;
    gerenciadorCompartimento = malloc(sizeof(GerenciadorCompartimento));

    int valorDeEntrada = 3;

    int *comparacoes = malloc(sizeof(int));
    int *movimentacoes = malloc(sizeof(int)); 
    char algoritmo[15];
    
    printf("Qual método de ordenação você deseja usar?\nDigite 1 para Inserção.\nDigite 2 para QuickSort.\n");
    scanf("%d", &valorDeEntrada);
    
    LerArquivo("Entradas.txt", gerenciadorCompartimento);
    switch (valorDeEntrada)
    {
    case 1:
        inicio = clock();
        Insercao(gerenciadorCompartimento, gerenciadorCompartimento->ultimo, comparacoes, movimentacoes);
        fim = clock();
        ImprimeRochasDoCompatimento(gerenciadorCompartimento);
        strcpy(algoritmo, "Inserção");
        break;
    case 2:
        inicio = clock();
        QuickSort(gerenciadorCompartimento, gerenciadorCompartimento->ultimo, comparacoes, movimentacoes);
        fim = clock();
        ImprimeRochasDoCompatimento(gerenciadorCompartimento);
        strcpy(algoritmo, "QuickSort");
        break;
    default:
        printf("Este valor não é valido, digite outro");
        break;
    }
    tempoDeExecucao = (double)(fim - inicio);
    printf("Comparações: %d \nMovimentações: %d \nTempo de execução: %.1f\nAlgoritmo: %s\n", *comparacoes, *movimentacoes, tempoDeExecucao, algoritmo);
    printf("\n");

    return 0;
}