#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

#define MAX_NODES 150  // Tamanho maximo da arvore

//  Estrutura de um n� da �rvore AVL
struct Node {
    int data; //  Valor do n�
    int height; // Altura da arvore (muito importante para fazer o balanceamento)
    int left;   //�ndice do filho esquerdo
    int right;  // �ndice do filho direito
};

// Cria o vetor para  guardar os n�s  da arvore
vector<Node> tree(MAX_NODES);
int nodeCount = 0;  // Conta  quantos n�s foram inseridos
P
// Fun��o   que obtem a altura de um n�
int height(int index) {
    return (index == -1) ? 0 : tree[index].height;
}

// Fun��o que faz o calculo  do fator de balanceamento
int getBalance(int index) {
    return (index == -1) ? 0 : height(tree[index].left) - height(tree[index].right);
}

// Cria  umn� novo e adiciona ele ao vetor
int newNode(int data) {
    if (nodeCount >= MAX_NODES) return -1;
    tree[nodeCount] = {data, 1, -1, -1};
    return nodeCount++;  // para retornar o indice do n� que foi criado
}

// Faz a rota��o para a direita
int rotateRight(int y) {
    int x = tree[y].left;
    tree[y].left = tree[x].right;
    tree[x].right = y;

    //Define  a nova altura
    tree[y].height = 1 + max(height(tree[y].left), height(tree[y].right));
    tree[x].height = 1 + max(height(tree[x].left), height(tree[x].right));

    return x;
}

// Faz a rota��o para a esquerda
int rotateLeft(int x) {
    int y = tree[x].right;
    tree[x].right = tree[y].left;
    tree[y].left = x;

    tree[x].height = 1 + max(height(tree[x].left), height(tree[x].right));
    tree[y].height = 1 + max(height(tree[y].left), height(tree[y].right));

    return y;
}

// Fun��o para inserir um novo n� na �rvore AVL
int insert(int root, int data) {
    if (root == -1) return newNode(data);

    if (data < tree[root].data)
        tree[root].left = insert(tree[root].left, data);
    else if (data > tree[root].data)
        tree[root].right = insert(tree[root].right, data);
    else
        return root; // Evita  que o valor seja repetido

    // Atualiza a nova  altura
    tree[root].height = 1 + max(height(tree[root].left), height(tree[root].right));

    //Faz o fator de balanceamento
    int balance = getBalance(root);

    //   Rota��os
    if (balance > 1 && data < tree[tree[root].left].data)
        return rotateRight(root);
    if (balance < -1 && data > tree[tree[root].right].data)
        return rotateLeft(root);
    if (balance > 1 && data > tree[tree[root].left].data) {
        tree[root].left = rotateLeft(tree[root].left);
        return rotateRight(root);
    }
    if (balance < -1 && data < tree[tree[root].right].data) {
        tree[root].right = rotateRight(tree[root].right);
        return rotateLeft(root);
    }

    return root;
}

// Fun��o para remover um n� da �rvore AVL
int remove(int root, int data) {
    if (root == -1) return root;

    if (data < tree[root].data)
        tree[root].left = remove(tree[root].left, data);
    else if (data > tree[root].data)
        tree[root].right = remove(tree[root].right, data);
    else {
        // N� com apenas um filho ou com  nenhum
        if (tree[root].left == -1)
            return tree[root].right;
        else if (tree[root].right == -1)
            return tree[root].left;

        // N� com dois filhos: obtem o sucessor
        int minNode = tree[root].right;
        while (tree[minNode].left != -1) {
            minNode = tree[minNode].left;
        }

        // Troca o valor do n�  quando � removido com o sucessor
        tree[root].data = tree[minNode].data;
        // Remove o sucessor
        tree[root].right = remove(tree[root].right, tree[minNode].data);
    }

    // Atualiza altura
    tree[root].height = 1 + max(height(tree[root].left), height(tree[root].right));

    // Obt�m o fator de balanceamento
    int balance = getBalance(root);

    // Casos de rota��o
    if (balance > 1 && getBalance(tree[root].left) >= 0)
        return rotateRight(root);
    if (balance > 1 && getBalance(tree[root].left) < 0) {
        tree[root].left = rotateLeft(tree[root].left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(tree[root].right) <= 0)
        return rotateLeft(root);
    if (balance < -1 && getBalance(tree[root].right) > 0) {
        tree[root].right = rotateRight(tree[root].right);
        return rotateLeft(root);
    }

    return root;
}

// Imprime a �rvore em ordem crescente
void sortedPrint(int root) {
    if (root != -1) {
        sortedPrint(tree[root].left);
        cout << tree[root].data << " ";
        sortedPrint(tree[root].right);
    }
}

// Imprime  o a parte visual da �rvore AVL
void printTree(int root, int space) {
    if (root == -1) return;

    space += 5;
    printTree(tree[root].right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << tree[root].data << endl;

    printTree(tree[root].left, space);
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    int root = -1; // �ndice da raiz no vetor

    // Inserindo  os valores
    root = insert(root, 11);
    root = insert(root, 16);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 17);
    root = insert(root, 14);
    root = insert(root, 12);

    // Imprime lista ordenada
    cout << "\n�rvore AVL ordenada em lista: ";
    sortedPrint(root);
    cout << "\n";

    // Imprime o desenho da  estrutura �rvore
    cout << "\nEstrutura da �rvore AVL:\n";
    printTree(root, 0);

    // Remove um valor
    root = remove(root, 14);
    cout << "\nAp�s remover 14:\n";

    // Imprime a lista ordenada depois de fazer a remo��o
    cout << "�rvore AVL ordenada em lista: ";
    sortedPrint(root);
    cout << "\n";

    // Imprime  a parte visual da �rvore depois de fazer a remo��o
    cout << "\nEstrutura da �rvore AVL:\n";
    printTree(root, 0);

    return 0;
}
