#ifndef MAPA_H
#define MAPA_H

#define LINHAS 15
#define COLUNAS 80

void bordas_mapa(char mapa[LINHAS][COLUNAS]);
int posicao_vazia(char mapa[LINHAS][COLUNAS], int x, int y);
void colocar_aleatorio(char mapa[LINHAS][COLUNAS], char simbolo);
int fuga_humana(char mapa[LINHAS][COLUNAS]);
void imprimir_mapa(char mapa[LINHAS][COLUNAS]);

#endif // MAPA_H