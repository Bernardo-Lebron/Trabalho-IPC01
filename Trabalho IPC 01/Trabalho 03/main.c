#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificar_palindromo() {
    char texto[200], txlimpo[200], invertido[200];
    int i, k, j = 0;

    printf("\nDigite um texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strlen(texto)-1]='\0'; // DEFINE O ULTIMO CARACTERE DA STRING PARA '\0'


    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] != ' ' && texto[i] != ',' && texto[i] != '.' && 
            texto[i] != '!' && texto[i] != '?' && texto[i] != '-') { //BLOCO IGNORADO NÃO ENTRA NO CÓDIGO

            if (texto[i] >= 'A' && texto[i] <= 'Z') {
                txlimpo[j] = texto[i] + 32; // CONVERTE MAIÚSCULA PARA MINÚSCULA
            } else {
                txlimpo[j] = texto[i];
            }
            j++; // AVANÇA NO ÍNDICE DA STRING LIMPA
        }
    }
    txlimpo[j] = '\0'; // DEFINE O ÚLTIMO CARACTERE DA STRING COMO '\0'

    printf("\nTexto limpo normal: %s\n", txlimpo); // MOSTRA O TEXTO LIMPO NA ORDEM NORMAL

    /*--- INVERTENDO O TEXTO ---*/
    for ( k = 0, i = j-1; i >= 0; k++, i--) {
        invertido[k] = txlimpo[i];
    }
    invertido[k] = '\0'; // DEFINE O ULTIMO CARACTERE DA STRING PARA '\0'

    printf("Texto limpo invertido: %s\n\n", invertido); // MOSTRA O TEXTO LIMPO NA ORDEM INVERTIDA

    /*--- COMPARA A STRING TXLIMPO COM A STRING INVERTIDO ---*/
    if (strcmp(txlimpo, invertido) == 0) {
        printf("True\n\n");
    } else {
        printf("False\n\n");
    }
}

int main() {
    verificar_palindromo();

    printf("\nPressione Enter para sair! ");
    getchar();
    
    return 0;
}