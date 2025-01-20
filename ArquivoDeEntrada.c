#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento/TAD_Compartimento.h"
#include "Compartimento/Rocha_Mineral/TAD_RochaMineral.h"
#include "Compartimento/Rocha_Mineral/Lista_Minerais/TAD_ListaMineral.h"
#include "Compartimento/Rocha_Mineral/Lista_Minerais/Mineral/TAD_Mineral.h"
#define tamanhoMaximoDaLinha 100

void LerArquivo(char* link, GerenciadorCompartimento* gerenciadorCompartimento){

    FILE *arquivoDeEntrada = fopen(link, "r");

    char linhaDoArquivo[tamanhoMaximoDaLinha];

    int numeroDeRochas;

    fscanf(arquivoDeEntrada, "%d", &numeroDeRochas);

    printf("%d\n", numeroDeRochas);

    Mineral mineral;
    ListaMineral listaMineral;
    RochaMineral rochaMineral;
    Localizacao localizacao;

    for (int i = 0; i < numeroDeRochas; i++)
    {
        float lon, lat, peso;

        fscanf(arquivoDeEntrada ,"%f %f %f", &lat, &lon, &peso);  
        
        fgets(linhaDoArquivo, sizeof(linhaDoArquivo), arquivoDeEntrada);

        char* nome1 = strtok(linhaDoArquivo, " ");
        char* nome2 = strtok(NULL, " ");
        char* nome3 = strtok(NULL, " ");


        localizacao.Latitude = lat;
        localizacao.Longitude = lon;

        InicializaListaMineral(&listaMineral);

        int tamanho = 1;

        InicializaMineral(&mineral, nome1);
        InsereListaMineral(&listaMineral, mineral);
        if(nome2 != NULL){
            InicializaMineral(&mineral, nome2);
            InsereListaMineral(&listaMineral, mineral);
            tamanho = 2;
        }
        if(nome3 != NULL){
            InicializaMineral(&mineral, nome3);
            InsereListaMineral(&listaMineral, mineral);
            tamanho = 3;
        }
        
        InicializaRochaMineral(&rochaMineral, peso, listaMineral, localizacao);
        ClassificaCategoria(&rochaMineral, tamanho);
        
        Compartimento compatimento;
        compatimento._RochaMineral = rochaMineral;

        InsereRochaNoCompatimento(gerenciadorCompartimento, compatimento);
    }
}