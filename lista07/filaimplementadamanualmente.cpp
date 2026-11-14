#include <iostream>

using namespace std;

const int CAPACIDADE_MAXIMA = 5;

class FilaManual {
private:
    int dados[CAPACIDADE_MAXIMA];
    int inicio;
    int fim;
    int tamanho;

public:
    FilaManual() {
        inicio = 0;
        fim = 0;
        tamanho = 0;
    }

    bool estaVazia() const {
        return tamanho == 0;
    }

    bool estaCheia() const {
        return tamanho == CAPACIDADE_MAXIMA;
    }

    void inserir(int valor) {
        if (estaCheia()) {
            cout << "Erro: Fila cheia (Overflow)! Nao e possivel inserir " << valor << ".\n";
            return;
        }
        dados[fim] = valor;
        fim = (fim + 1) % CAPACIDADE_MAXIMA;
        tamanho++;
        cout << "Valor " << valor << " inserido na fila com sucesso.\n";
    }

    void remover() {
        if (estaVazia()) {
            cout << "Erro: Fila vazia (Underflow)! Nao ha elementos para remover.\n";
            return;
        }
        cout << "Removendo da fila (atendimento): " << dados[inicio] << "\n";
        inicio = (inicio + 1) % CAPACIDADE_MAXIMA;
        tamanho--;
    }

    int consultarProximo() const {
        if (estaVazia()) {
            cout << "Aviso: A fila esta vazia. Nenhum proximo elemento.\n";
            return -1;
        }
        return dados[inicio];
    }

    void exibir() const {
        if (estaVazia()) {
            cout << "Fila vazia.\n";
            return;
        }
        cout << "Fila (do primeiro ao ultimo): ";
        for (int i = 0; i < tamanho; i++) {
            int indice = (inicio + i) % CAPACIDADE_MAXIMA;
            cout << dados[indice] << " ";
        }
        cout << "\n";
    }
};

void exibirMenu() {
    cout << "\n======================================\n";
    cout << "     FILA MANUAL COM ARRAY (Cap: 5)   \n";
    cout << "======================================\n";
    cout << "1. Inserir elemento (enqueue)\n";
    cout << "2. Remover proximo (dequeue)\n";
    cout << "3. Consultar proximo (front)\n";
    cout << "4. Verificar se esta vazia (empty)\n";
    cout << "5. Exibir fila\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    FilaManual minhaFila;
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
                cout << "Digite o valor inteiro para inserir: ";
                cin >> valor;
                minhaFila.inserir(valor);
                break;
            }
            case 2: {
                minhaFila.remover();
                break;
            }
            case 3: {
                int p = minhaFila.consultarProximo();
                if (!minhaFila.estaVazia()) {
                    cout << "Proximo elemento a ser atendido: " << p << "\n";
                }
                break;
            }
            case 4: {
                if (minhaFila.estaVazia()) {
                    cout << "Status: A fila esta VAZIA.\n";
                } else {
                    cout << "Status: A fila NAO esta vazia.\n";
                }
                break;
            }
            case 5: {
                minhaFila.exibir();
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