#include <stdio.h>
#include <stdlib.h>

void busca_fibonacci(int n, int x) {
    int fib[40]; // ARRAY DA SEQUENCIA
    fib[0] = 0;  // TERMO NA POSIÇÃO 0
    fib[1] = 1;  // TERMO NA POSIÇÃO 1

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // TERMOS SEGUINTES ATÉ O VALOR DE N
    }

    printf("\nSequencia de Fibonacci: \n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib[i]); // PRINTF COM OS VALORES DA SEQUENCIA
    }

    /*--- BUSCA BINÁRIA ---*/
    int inicio = 0, fim = n, meio, encontrado = 0;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (fib[meio] == x) {
            encontrado = 1;
            break;
        } else if (fib[meio] < x) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado == 1) {
        printf("\n\nO numero %d esta presente na sequencia! Indice %d\n", x, meio);
    } else {
        printf("\n\nO numero %d nao esta na sequencia! Indice -1\n", x);
    }

    printf("\n");
}

int main() {
    int n, x;

    printf("\nDigite um valor n: "); // TERMO DA SEQUENCIA DE FIBONACCI
    scanf("%d", &n);

    while (getchar() != '\n'); 

    printf("\nDigite um valor x para ser procurado na sequencia: "); // VALOR PARA SER ENCONTRADO
    scanf("%d", &x);

    while (getchar() != '\n'); 

    busca_fibonacci(n, x);
    
    printf("\nPressione Enter para sair! ");
    getchar(); 
    
    return 0;
}