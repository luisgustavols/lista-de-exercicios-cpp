#include <iostream>

using namespace std;

struct No {
    int valor;
    No* proximo;

    No(int val) {
        valor = val;
        proximo = nullptr;
    }
};

int main() {
    No* cabeca = new No(10);
    
    cabeca->proximo = new No(20);
    cabeca->proximo->proximo = new No(30);
    cabeca->proximo->proximo->proximo = new No(40);
    cabeca->proximo->proximo->proximo->proximo = new No(50);

    cout << "--- ELEMENTOS DA LISTA ENCADEADA ---\n";
    No* atual = cabeca;
    int posicao = 1;
    
    while (atual != nullptr) {
        cout << "No " << posicao++ << ": " << atual->valor << "\n";
        atual = atual->proximo;
    }

    cout << "\nLiberando a memoria dos nos...\n";
    while (cabeca != nullptr) {
        No* proximoNo = cabeca->proximo;
        delete cabeca;
        cabeca = proximoNo;
    }
    cout << "Memoria liberada com sucesso!\n";

    return 0;
}