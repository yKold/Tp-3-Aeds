#include "ArquivoDeEntrada.c"
#include "Compartimento/TAD_Compartimento.h"
#include "Insercao.h"
#include "QuickSort.c"
#include "string.h"
#include <time.h>

int main(){
    clock_t inicio, fim;
    double tempoDeExecucao;

    GerenciadorCompartimento* gerenciadorCompartimento;
    gerenciadorCompartimento = malloc(sizeof(GerenciadorCompartimento));

    int valorDeEntrada;
    int QuantidadeRochas;

    int *comparacoes = malloc(sizeof(int));
    int *movimentacoes = malloc(sizeof(int)); 
    char algoritmo[15];
    printf("Deseja realizar o teste com quantas rochas?\nDigite 1 para 250 Rochas\nDigite 2 para 1000 Rochas\nDigite 3 para 10000 Rochas\n");
    scanf("%d", &QuantidadeRochas);
    switch (QuantidadeRochas)
    {
    case 1:
        LerArquivo("Arquivos/250Rochas.txt", gerenciadorCompartimento);
        break;
    case 2:
        LerArquivo("Arquivos/1000Rochas.txt", gerenciadorCompartimento);
        break;
    case 3:
        LerArquivo("Arquivos/10000Rochas.txt", gerenciadorCompartimento);
        break;
    default:
        break;
    }
    
    printf("Qual metodo de ordenacao voce deseja usar?\nDigite 1 para Insercao.\nDigite 2 para QuickSort.\n");
    scanf("%d", &valorDeEntrada);
    
    
    switch (valorDeEntrada)
    {
    case 1:
        inicio = clock();
        Insercao(gerenciadorCompartimento, gerenciadorCompartimento->ultimo, comparacoes, movimentacoes);
        fim = clock();
        ImprimeRochasDoCompatimento(gerenciadorCompartimento);
        strcpy(algoritmo, "Insercao");
        break;
    case 2:
        inicio = clock();
        QuickSort(gerenciadorCompartimento, gerenciadorCompartimento->ultimo, comparacoes, movimentacoes);
        fim = clock();
        ImprimeRochasDoCompatimento(gerenciadorCompartimento);
        strcpy(algoritmo, "QuickSort");
        break;
    default:
        printf("Este valor nao e valido, digite outro");
        break;
    }
    tempoDeExecucao = (double)(fim - inicio);
    printf("Comparacoes: %d \nMovimentacoes: %d \nTempo de execucao: %.4fs\nAlgoritmo: %s\n", *comparacoes, *movimentacoes, tempoDeExecucao, algoritmo);
    printf("\n");

    return 0;
}