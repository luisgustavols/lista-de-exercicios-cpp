#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class MatrizDinamica {
private:
    int linhas;
    int colunas;
    int** dados;

public:
    MatrizDinamica(int l, int c) : linhas(l), colunas(c) {
        if (linhas <= 0 || colunas <= 0) {
            throw invalid_argument("As dimensoes da matriz devem ser maiores que zero.");
        }

        dados = new int*[linhas];

        for (int i = 0; i < linhas; ++i) {
            dados[i] = new int[colunas]();
        }
    }

    MatrizDinamica(const MatrizDinamica& outra) : linhas(outra.linhas), colunas(outra.colunas) {
        dados = new int*[linhas];
        for (int i = 0; i < linhas; ++i) {
            dados[i] = new int[colunas];
            for (int j = 0; j < colunas; ++j) {
                dados[i][j] = outra.dados[i][j];
            }
        }
    }

    ~MatrizDinamica() {
        for (int i = 0; i < linhas; ++i) {
            delete[] dados[i];
        }
        delete[] dados;
    }

    void definirValor(int i, int j, int valor) {
        if (i < 0 || i >= linhas || j < 0 || j >= colunas) {
            throw out_of_range("Indice fora dos limites da matriz.");
        }
        dados[i][j] = valor;
    }

    int obterValor(int i, int j) const {
        if (i < 0 || i >= linhas || j < 0 || j >= colunas) {
            throw out_of_range("Indice fora dos limites da matriz.");
        }
        return dados[i][j];
    }

    void imprimir() const {
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                cout << setw(4) << dados[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    MatrizDinamica original(3, 3);
    int contador = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            original.definirValor(i, j, contador * 10);
            contador++;
        }
    }

    MatrizDinamica copia = original;

    copia.definirValor(0, 0, 999);
    copia.definirValor(1, 1, 888);
    copia.definirValor(2, 2, 777);

    cout << "Matriz Original (inalterada):\n";
    original.imprimir();

    cout << "\nMatriz Copia (modificada):\n";
    copia.imprimir();

    return 0;
}