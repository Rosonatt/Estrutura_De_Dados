#include <stdio.h>

#define Linhas 3
#define Colunas 4

// soma de matrizes
void somaMatrizes(int matriz1[Linhas][Colunas], int matriz2[Linhas][Colunas], int resultado[Linhas][Colunas]) {
    for (int i = 0; i < Linhas; i++) {
        for (int j = 0; j < Colunas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// multiplicação matrizes
void multiplicacaoMatrizes(int matriz1[Linhas][Colunas], int matriz2[Linhas][Colunas], int resultado[Linhas][Colunas]) {
    for (int i = 0; i < Linhas; i++) {
        for (int j = 0; j < Colunas; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < Colunas; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    int matriz1[Linhas][Colunas] = {
        {1, 5, 9, 2},
        {4, 5, 2, 7},
        {3, 10, 25, 8}
    };

    int matriz2[Linhas][Colunas] = {
        {0, 8, 1, 3},
        {5, 8, 4, 6},
        {4, 2, 4, 9}
    };

    int somaDasMatrizes[Linhas][Colunas];
    int multiplicacaoDasMatrizes[Linhas][Colunas];

    // Soma das matrizes
    somaMatrizes(matriz1, matriz2, somaDasMatrizes);

    printf("Soma das Matrizes:\n");
    for (int i = 0; i < Linhas; i++) {
        for (int j = 0; j < Colunas; j++) {
            printf("%d ", somaDasMatrizes[i][j]);
        }
        printf("\n");
    }

    // Multiplicação das matrizes
    multiplicacaoMatrizes(matriz1, matriz2, multiplicacaoDasMatrizes);

    printf("\nMultiplicação das Matrizes:\n");
    for (int i = 0; i < Linhas; i++) {
        for (int j = 0; j < Colunas; j++) {
            printf("%d ", multiplicacaoDasMatrizes[i][j]);
        }
        printf("\n");
    }

    return 0;
}
