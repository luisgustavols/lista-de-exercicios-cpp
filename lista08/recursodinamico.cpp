#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

class Buffer {
private:
    int* dados;
    size_t tamanho;

public:
    Buffer(size_t tam, int valorInicial = 0) : tamanho(tam) {
        if (tamanho == 0) {
            throw invalid_argument("O tamanho do buffer deve ser maior que zero.");
        }
        dados = new int[tamanho];
        for (size_t i = 0; i < tamanho; ++i) {
            dados[i] = valorInicial;
        }
    }

    ~Buffer() {
        delete[] dados;
    }

    Buffer(const Buffer& outro) : tamanho(outro.tamanho) {
        dados = new int[tamanho];
        for (size_t i = 0; i < tamanho; ++i) {
            dados[i] = outro.dados[i];
        }
    }

    Buffer& operator=(const Buffer& outro) {
        if (this != &outro) {
            delete[] dados;
            tamanho = outro.tamanho;
            dados = new int[tamanho];
            for (size_t i = 0; i < tamanho; ++i) {
                dados[i] = outro.dados[i];
            }
        }
        return *this;
    }

    Buffer(Buffer&& outro) noexcept : dados(outro.dados), tamanho(outro.tamanho) {
        outro.dados = nullptr;
        outro.tamanho = 0;
    }

    Buffer& operator=(Buffer&& outro) noexcept {
        if (this != &outro) {
            delete[] dados;
            dados = outro.dados;
            tamanho = outro.tamanho;
            outro.dados = nullptr;
            outro.tamanho = 0;
        }
        return *this;
    }

    Buffer operator+(const Buffer& outro) const {
        if (tamanho != outro.tamanho) {
            throw invalid_argument("Erro: Os buffers possuem tamanhos diferentes e nao podem ser somados.");
        }

        Buffer resultado(tamanho);
        for (size_t i = 0; i < tamanho; ++i) {
            resultado.dados[i] = dados[i] + outro.dados[i];
        }
        return resultado; 
    }

    void definir(size_t indice, int valor) {
        if (indice >= tamanho) {
            throw out_of_range("Indice fora dos limites do buffer.");
        }
        dados[indice] = valor;
    }

    void imprimir() const {
        cout << "[ ";
        for (size_t i = 0; i < tamanho; ++i) {
            cout << dados[i] << " ";
        }
        cout << "]\n";
    }
};

int main() {
    try {
        Buffer b1(4, 10);
        Buffer b2(4, 5);
        b2.definir(1, 20);

        cout << "Buffer 1: "; b1.imprimir();
        cout << "Buffer 2: "; b2.imprimir();

        Buffer b3 = b1 + b2;
        cout << "Soma (b1 + b2): "; b3.imprimir();

        Buffer b4 = b1;
        b4.definir(0, 999);
        cout << "\nBuffer 1 (original inalterado): "; b1.imprimir();
        cout << "Buffer 4 (copia alterada):      "; b4.imprimir();

        Buffer b5 = move(b3);
        cout << "\nBuffer 5 (recebeu recurso movido): "; b5.imprimir();

        cout << "\nTentando somar buffers de tamanhos diferentes:\n";
        Buffer bInvalido(2, 1);
        Buffer bErro = b1 + bInvalido;
    }
    catch (const exception& e) {
        cerr << e.what() << "\n";
    }

    return 0;
}