#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mapa.h"

void bordas_mapa(char mapa[LINHAS][COLUNAS]) { // PREENCHE AS BORDAS DO MAPA COM OS CARACTERES '-' E '|'
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == 0 || i == LINHAS -1) {
                mapa[i][j] = '-';
            } else if (j == 0 || j == COLUNAS - 1) {
                mapa[i][j] = '|';
            } else {
                mapa[i][j] = ' ';
            }
        }
    }
}

int posicao_vazia(char mapa[LINHAS][COLUNAS], int x, int y) {
    return mapa[x][y] == ' '; // VERIFICA SE A POSIÇÃO NA MATRIZ ESTÁ VAZIA PARA PODER ALOCAR O OBJETO
}

void colocar_aleatorio(char mapa[LINHAS][COLUNAS], char simbolo) {
    int x, y;
    do {
        x = rand() % (LINHAS - 2) + 1;
        y = rand() % (COLUNAS - 2) + 1;
    } while (!posicao_vazia(mapa, x, y));
    mapa[x][y] = simbolo; // ALOCA OS OBJETOS ALEATORIAMENTE EM LUGARES NO MAPA
}

int fuga_humana(char mapa[LINHAS][COLUNAS]) {
    int visitado[LINHAS][COLUNAS] = {0};
    int anterior_x[LINHAS][COLUNAS];
    int anterior_y[LINHAS][COLUNAS]; //Matrizes que guardam de onde você veio para cada célula.

    int fila_x[LINHAS * COLUNAS]; 
    int fila_y[LINHAS * COLUNAS];
    int inicio = 0, fim = 0;

    int hx = -1, hy = -1, zx = -1, zy = -1; // Variáveis que guardarão as posições do humano e da zona segura

    // Encontrar posições do humano (H) e da zona de evacuação (Z)
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (mapa[i][j] == 'H') {
                hx = i;
                hy = j;
            } else if (mapa[i][j] == 'Z') {
                zx = i;
                zy = j;
            }
        }
    }

    if (hx == -1 || zx == -1) {
        return 0; // Não há humano ou zona de evacuação
    }

    // Inicializa BFS
    fila_x[fim] = hx; // Adiciona a posição do humano na fila
    fila_y[fim] = hy;
    fim++;

    visitado[hx][hy] = 1; // Marca a posição inicial como visitada

    /* Define que o ponto de origem veio de si */
    anterior_x[hx][hy] = hx;
    anterior_y[hx][hy] = hy;

    int dx[] = {-1, 1, 0, 0}; // Possíveis movimentos que podem ser feitos
    int dy[] = {0, 0, -1, 1}; 


    /* LOOP DO BFS */ 
    while (inicio < fim) { 
        int x = fila_x[inicio]; 
        int y = fila_y[inicio];
        inicio++;

        if (x == zx && y == zy) {
            //Reconstrói o caminho voltando de Z até H usando os vetores anterior_x e anterior_y
            while (!(x == hx && y == hy)) {
                if (mapa[x][y] != 'Z') {
                    mapa[x][y] = '*'; //A cada passo, marca o caminho no mapa com '*'
                }
                int px = anterior_x[x][y]; 
                int py = anterior_y[x][y]; // Volta para a célula anterior no caminho
                x = px;
                y = py;
            }
            printf("\nCaminho encontrado:\n");
            return 1;
        }

        // Explora os 4 vizinhos
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Verifica se a célula vizinha está dentro dos limites, ainda não foi visitada e é livre ou é a zona de evacuação
            if (nx >= 0 && nx < LINHAS && ny >= 0 && ny < COLUNAS &&
                !visitado[nx][ny] &&
                (mapa[nx][ny] == ' ' || mapa[nx][ny] == 'Z')) {
                
                // Adiciona vizinho à fila
                fila_x[fim] = nx;
                fila_y[fim] = ny;
                fim++;

                // Marca como visitado e registra o caminho de onde veio
                visitado[nx][ny] = 1;
                anterior_x[nx][ny] = x;
                anterior_y[nx][ny] = y;
            }
        }
    }

    return 0;
}

void imprimir_mapa(char mapa[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}