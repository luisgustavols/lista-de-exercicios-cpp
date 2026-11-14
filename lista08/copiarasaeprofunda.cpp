#include <iostream>

using namespace std;

class NumeroDinamico {
private:
    int* valor;

public:
    NumeroDinamico(int v) {
        valor = new int(v);
    }

    NumeroDinamico(const NumeroDinamico& outro) {
        valor = new int(*outro.valor);
    }

    ~NumeroDinamico() {
        delete valor;
    }

    void setValor(int v) {
        *valor = v;
    }

    int getValor() const {
        return *valor;
    }

    int* getEndereco() const {
        return valor;
    }
};

int main() {
    NumeroDinamico original(10);
    NumeroDinamico copia = original; 

    copia.setValor(50);

    cout << "Original -> Valor: " << original.getValor() << " | Endereco: " << original.getEndereco() << "\n";
    cout << "Copia    -> Valor: " << copia.getValor()    << " | Endereco: " << copia.getEndereco()    << "\n";

    return 0;
}