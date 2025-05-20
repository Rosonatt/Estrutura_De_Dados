#include <stdio.h>

typedef struct {
    int chave;
} Elemento;

void descer(Elemento T[], int i, int n) {
    int j = 2 * i;
    while (j <= n) {
        if (j < n && T[j + 1].chave > T[j].chave) {
            j = j + 1;
        }
        if (T[i].chave < T[j].chave) {
            Elemento temp = T[i];
            T[i] = T[j];
            T[j] = temp;
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
}

void subir(Elemento T[], int i) {
    while (i > 1 && T[i/2].chave < T[i].chave) {
        Elemento temp = T[i];
        T[i] = T[i/2];
        T[i/2] = temp;
        i = i/2;
    }
}

void imprimirHeap(Elemento T[], int n) {
    printf("\nRepresentacao  do heap:\n");
    printf("        %d\n", T[1].chave);
    printf("      /   \\\n");
    printf("     %d     %d\n", T[2].chave, T[3].chave);
    printf("    / \\   / \\\n");
    printf("   %d %d %d %d\n\n", T[4].chave, T[5].chave, T[6].chave, T[7].chave);
}

int main() {
    Elemento heap[8]; // Indices de 1 a 7
    int n = 7;

    printf("Digite 7 numeros inteiros (maximo):\n");
    for (int i = 1; i <= n; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &heap[i].chave);
    }

    // Construir heap
    for (int i = n/2; i >= 1; i--) {
        descer(heap, i, n);
    }

    printf("\nHeap construido:");
    imprimirHeap(heap, n);

    // Operacao de subida no ultimo elemento
    subir(heap, n);
    printf("Apos subir o ultimo elemento (%d):", heap[n].chave);
    imprimirHeap(heap, n);

    // Operacao de descida no primeiro elemento
    descer(heap, 1, n);
    printf("Apos descer o primeiro elemento (%d):", heap[1].chave);
    imprimirHeap(heap, n);

    printf(" Array Final: [");
    for (int i = 1; i <= n; i++) {
        printf("%d", heap[i].chave);
        if (i < n) printf(", ");
    }
    printf("]\n");

    return 0;
}
