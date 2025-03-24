#include <stdio.h>

int main() {

    char *S[] = {"Rosonatt", "Bruno", "Ryan", "Nathalia"};
    int n = sizeof(S) / sizeof(S[0]);

    int fim = n / 2;
    for (int i = 0; i < fim; i++) {
        char *temp = S[i];
        S[i] = S[n - 1 - i];
        S[n - 1 - i] = temp;
    }

    printf("Lista invertida:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", S[i]);
    }

    return 0;
}
