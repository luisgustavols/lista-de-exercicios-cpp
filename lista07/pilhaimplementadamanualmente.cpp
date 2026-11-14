#include <iostream>

using namespace std;

const int CAPACIDADE_MAXIMA = 5;

class PilhaManual {
private:
    int dados[CAPACIDADE_MAXIMA];
    int topo; 

public:
    PilhaManual() {
        topo = -1; 
    }

    bool estaVazia() const {
        return topo == -1;
    }

    bool estaCheia() const {
        return topo == CAPACIDADE_MAXIMA - 1;
    }

    void empilhar(int valor) {
        if (estaCheia()) {
            cout << "Erro: Pilha cheia (Overflow)! Nao e possivel empilhar " << valor << ".\n";
            return;
        }
        topo++;
        dados[topo] = valor;
        cout << "Valor " << valor << " empilhado com sucesso.\n";
    }

    void desempilhar() {
        if (estaVazia()) {
            cout << "Erro: Pilha vazia (Underflow)! Nao ha elementos para desempilhar.\n";
            return;
        }
        cout << "Removendo do topo: " << dados[topo] << "\n";
        topo--;
    }

    int consultarTopo() const {
        if (estaVazia()) {
            cout << "Aviso: A pilha esta vazia. Nenhum elemento no topo.\n";
            return -1; 
        }
        return dados[topo];
    }

    void exibir() const {
        if (estaVazia()) {
            cout << "Pilha vazia.\n";
            return;
        }
        cout << "Pilha (do fundo para o topo): ";
        for (int i = 0; i <= topo; i++) {
            cout << dados[i] << " ";
        }
        cout << "\n";
    }
};

void exibirMenu() {
    cout << "\n======================================\n";
    cout << "     PILHA MANUAL COM ARRAY (Cap: 5)  \n";
    cout << "======================================\n";
    cout << "1. Empilhar (push)\n";
    cout << "2. Desempilhar (pop)\n";
    cout << "3. Consultar topo (top)\n";
    cout << "4. Verificar se esta vazia (empty)\n";
    cout << "5. Exibir pilha\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    PilhaManual minhaPilha;
    int opcao = 0;

    do {
        exibirMenu();
        if (!(cin >> opcao)) {
            cout << "Entrada invalida. Tente novamente.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }

        switch (opcao) {
            case 1: {
                int valor;
                cout << "Digite o valor inteiro para empilhar: ";
                cin >> valor;
                minhaPilha.empilhar(valor);
                break;
            }
            case 2: {
                minhaPilha.desempilhar();
                break;
            }
            case 3: {
                int t = minhaPilha.consultarTopo();
                if (!minhaPilha.estaVazia()) {
                    cout << "Elemento no topo: " << t << "\n";
                }
                break;
            }
            case 4: {
                if (minhaPilha.estaVazia()) {
                    cout << "Status: A pilha esta VAZIA.\n";
                } else {
                    cout << "Status: A pilha NAO esta vazia.\n";
                }
                break;
            }
            case 5: {
                minhaPilha.exibir();
                break;
            }
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida! Escolha entre 0 e 5.\n";
        }
    } while (opcao != 0);

    return 0;
}