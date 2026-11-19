#include <iostream>
#include <string>

using namespace std;

class Veiculo {
public:
    string marca;

    virtual void emitirSom() {
        cout << "Som generico de motor..." << endl;
    }
};

class Carro : public Veiculo {
public:
    int numeroPortas;

    void emitirSom() override {
        cout << "Bi-bi! (buzina de carro)" << endl;
    }
};

class Motocicleta : public Veiculo {
public:
    void emitirSom() override {
        cout << "Randandandan! (som de moto)" << endl;
    }
};

int main() {
    Carro c;
    c.marca = "VW";
    c.numeroPortas = 2;

    Motocicleta m;
    m.marca = "Honda";

    c.emitirSom();
    m.emitirSom();

    Veiculo* v1 = &c;
    Veiculo* v2 = &m;

    v1->emitirSom();
    v2->emitirSom();

    return 0;
}