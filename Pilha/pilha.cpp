#include <iostream>
using namespace std;

const int MAX_SIZE = 50; // tamanho máximo fixo em 50

 //estrutura da pilha
struct Pilha {
    int elementos[MAX_SIZE];
    int topo;
    int capacidade;
};

// inicializa a pilha
void inicializar(Pilha &p, int tamanho) {
    if (tamanho > MAX_SIZE) {
        cout << "O tamanho  que voce solicitou ultrapassou o maximo permitido que e de (50). ajustando  para 50." << endl;
        tamanho = MAX_SIZE;
    }
    p.topo = -1;
    p.capacidade = tamanho;
}

//  faz  verificação se a pilha esta realmente vazia
bool estaVazia(Pilha &p) {
    return p.topo == -1;
}

// faz a vereificação se apilha esta cheia
bool estaCheia(Pilha &p) {
    return p.topo == p.capacidade - 1;
}

// faz a inserção na pilha no caso um Push
bool inserir(Pilha &p, int valor) {
    if (estaCheia(p)) {
        return false;
    }
    p.elementos[++p.topo] = valor;
    return true;
}

// remoção na pilha no  faz um pop
bool remover(Pilha &p, int &valorRemovido) {
    if (estaVazia(p)) {
        return false;
    }
    valorRemovido = p.elementos[p.topo--];
    return true;
}

// mostra todos os elementos que a pilha possui
void mostrarPilha(Pilha &p) {
    if (estaVazia(p)) {
        cout << "a sua pilha esta vazia!" << endl;
        return;
    }

    cout << "Elementos da pilha  indo do topo para a base: ";
    for (int i = p.topo; i >= 0; i--) {
        cout << p.elementos[i] << " ";
    }
    cout << endl;
}

int main() {
    Pilha minhaPilha;
    int tamanho, valor, opcao;
    int valorRemovido;

    cout << "digite o tamanho da pilha (maximo 50): ";
    cin >> tamanho;

    inicializar(minhaPilha, tamanho);

    // inserção de n-1 elementos
    cout << "\nInserindo " << minhaPilha.capacidade-1 << " elementos na pilha:" << endl;
    for (int i = 0; i < minhaPilha.capacidade-1; i++) {
        cout << "qual o o elemento " << i+1 << ": ";
        cin >> valor;
        inserir(minhaPilha, valor);
    }

    // Menu aonde faremos as operações
    do {
        cout << "\MENU " << endl;
        cout << "1. Mostrar pilha" << endl;
        cout << "2. Verificar se esta vazia" << endl;
        cout << "3. Verificar se esta cheia" << endl;
        cout << "4. Inserir elemento" << endl;
        cout << "5. Remover elemento" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opçao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                mostrarPilha(minhaPilha);
                break;
            case 2:
                if (estaVazia(minhaPilha)) {
                    cout << "A pilha esta vazia!" << endl;
                } else {
                    cout << "A pilha NAO esta vazia." << endl;
                }
                break;
            case 3:
                if (estaCheia(minhaPilha)) {
                    cout << "A pilha esta cheia!" << endl;
                } else {
                    cout << "A pilha NAO esta cheia." << endl;
                }
                break;
            case 4:
                if (estaCheia(minhaPilha)) {
                    cout << "Pilha cheia! Nao e possivel inserir." << endl;
                } else {
                    cout << "Digite o valor a ser inserido: ";
                    cin >> valor;
                    if (inserir(minhaPilha, valor)) {
                        cout << "Elemento foi inserido com sucesso!" << endl;
                        mostrarPilha(minhaPilha);
                    }
                }
                break;
            case 5:
                if (remover(minhaPilha, valorRemovido)) {
                    cout << "Elemento  foi removido: " << valorRemovido << endl;
                    mostrarPilha(minhaPilha);
                } else {
                    cout << " Infelizmente a pilha esta vazia! Nao poeremos remover." << endl;
                }
                break;
            case 0:
                cout << "Saindo do  programa..." << endl;
                break;
            default:
                cout << "esta opçao invalida e invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
