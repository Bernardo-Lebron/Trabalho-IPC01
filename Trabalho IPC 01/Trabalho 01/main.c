#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mapa.h"

int main() {
    char mapa[LINHAS][COLUNAS];
    int robos, maxrobos;

    srand(time(NULL)); // COMANDO PARA AUXILIAR NA ALOCAÇÃO ALEATÓRIA DE OBJETOS NO MAPA

    maxrobos = (LINHAS - 2) * (COLUNAS - 2) - 2; // DEFINE O NUMERO MÁXIMO DE ROBOS BASEADO NA QUANTIDADE DE LINHAS E COLUNAS

    printf("Digite quantos robos quer adicionar no mapa (max %d): ", maxrobos);
    scanf("%d", &robos);

    while (getchar() != '\n');
    
    if (robos < 0 || robos > maxrobos) {
        printf("Quantidade de robos inválida\nPressione Enter para sair! ");
        getchar();
        return 0;
    }
    
    bordas_mapa(mapa); // FUNÇÃO PARA DEFINIR AS BORDAS DO MAPA

    for (int i = 0; i < robos; i++) {
        colocar_aleatorio(mapa, 'R');
    }
    
    colocar_aleatorio(mapa, 'H');
    colocar_aleatorio(mapa, 'Z');

    if (!fuga_humana(mapa)) {
    printf("\nCaminho nao encontrado!\n");
    }

    imprimir_mapa(mapa);

    printf("Pressione Enter para sair! ");
    getchar();

    return 0;

}