#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
    cout << "=== COMPARACAO DE ESTRUTURAS DE DADOS ===\n\n";

    list<string> minhaLista;
    minhaLista.push_back("Item Final");
    minhaLista.push_front("Item Inicial");
    cout << "[Lista] Tamanho: " << minhaLista.size() << " (Permite inserir/remover em qualquer lugar)\n";

    queue<string> minhaFila;
    minhaFila.push("Primeiro a chegar");
    minhaFila.push("Segundo a chegar");
    cout << "[Fila - FIFO] Proximo a ser atendido: " << minhaFila.front() << "\n";

    stack<string> minhaPilha;
    minhaPilha.push("Primeiro colocado (fundo)");
    minhaPilha.push("Ultimo colocado (topo)");
    cout << "[Pilha - LIFO] Elemento no topo (sai primeiro): " << minhaPilha.top() << "\n";

    return 0;
}