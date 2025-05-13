#include <iostream>

// deque para caracteres
class Deque {
private:
    // estrutura de n�
    struct No {
        char letra;
        No* anterior;
        No* proximo;

        No(char l) : letra(l), anterior(nullptr), proximo(nullptr) {}
    };

    No* frente;
    No* tras;
    int tamanho;

public:
//     inicializa deque vazio
    Deque() : frente(nullptr), tras(nullptr), tamanho(0) {}

    // libera toda a mem�ria alocada
    ~Deque() {
        while (!vazio()) {
            removerFrente();
        }
    }

    // verifica se o deque est� vazio
    bool vazio() const {
        return frente == nullptr;
    }

    // insere um caractere no final do deque
    void inserirTras(char l) {
        No* novo = new No(l);

        if (vazio()) {
            // Se deque vazio, novo n� � a frente e o tr�s
            frente = tras = novo;
        } else {
            // faz aliga��o entre o novo no e o no final
            novo->anterior = tras;
            tras->proximo = novo;
            tras = novo;       // faz a atualiza��o do onteio de tras
        }
        tamanho++;
    }

    // faz a remo��oe retorna o char de tras
    char removerFrente() {
        if (vazio()) return '\0';

        No* temp = frente;
        char l = temp->letra;
        if (frente == tras) {
            // ultimo elemento deque fica vazio
            frente = tras = nullptr;
        } else {
            // atualiza frente para o pr�ximo n�
            frente = frente->proximo;
            frente->anterior = nullptr;
        }

        delete temp;
        tamanho--;
        return l;
    }

    // remove e retorna o caractere do final do deque
    char removerTras() {
        if (vazio()) return '\0';  // Retorna nulo se vazio

        No* temp = tras;
        char l = temp->letra;

        if (frente == tras) {
            // ultimo elemento: deque fica vazio
            frente = tras = nullptr;
        } else {
            // atualiza tr�s para o n� anterior
            tras = tras->anterior;
            tras->proximo = nullptr;
        }

        delete temp;
        tamanho--;
        return l;
    }
};

// verifica se uma palavra � pal�ndromo
bool ehPalindromo(const std::string& palavra) {
    Deque dq;

    // Preenche o deque com todos os caracteres da palavra
    for (size_t i = 0; i < palavra.size(); ++i) {
        dq.inserirTras(palavra[i]);
    }

    // Compara os caracteres das extremidades
    while (!dq.vazio()) {
        // Remove caractere da frente
        char frente = dq.removerFrente();

        // Se ainda h� elementos remove do final tamb�m
        if (!dq.vazio()) {
            char tras = dq.removerTras();

            // Se diferentes n�o � pal�ndromo
            if (frente != tras) {
                return false;
            }
        }
    }

    // todos os pares foram iguais
    return true;
}

int main() {
    std::string entrada;

    std::cout << "digite a palavra que voce gostaria  de verificar: ";
    std::cin >> entrada;

    if (ehPalindromo(entrada)) {
        std::cout << "\"" << entrada << "\" sua palavra e um palindromo\n";
    } else {
        std::cout << "\"" << entrada << "\" sua palavra nao e um palindromo.\n";
    }

    return 0;
}
