#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Capacidade maxima da fila

// Estrutura  da fila
typedef struct {
    int elementos[MAX];
    int inicio;
    int fim;
} Fila;

//inicia a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

//  verifica se a fila esta vazia
int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

//  verificar se a fila esta cheia
int filaCheia(Fila *f) {
    return f->fim == MAX;
}

// Funcao para enfileirar
void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("A fila esta cheia! Nao e possivel adicionar mais elementos.\n");
    } else {
        f->elementos[f->fim] = valor;
        f->fim++;
        printf("Elemento %d enfileirado.\n", valor);
    }
}

// Funcao para desenfileirar
int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila esta vazia! Nao ha elementos para remover.\n");
        return -1; // Valor de erro
    } else {
        int valor = f->elementos[f->inicio];
        f->inicio++;
        printf("Elemento %d desenfileirado.\n", valor);
        return valor;
    }
}

//  mostra todos os elementos da fila
void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila esta vazia!\n");
    } else {
        printf("Elementos na fila: ");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("%d ", f->elementos[i]);
        }
        printf("\n");
    }
}

// Funcao principal para o menu
int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao, valor;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Mostrar fila\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Qual o valor para enfileirar: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                break;
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 4:
                printf("Saindo do codigo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

