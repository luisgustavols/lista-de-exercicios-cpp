#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Veiculo {
public:
    string marca;

    // Se tirar o "virtual" daqui, vai sempre chamar o emitirSom() do Veiculo
    virtual void emitirSom() {
        cout << "Som de motor." << endl;
    }
};

class Carro : public Veiculo {
public:
    void emitirSom() override {
        cout << "Bi-bi! (carro)" << endl;
    }
};

class Motocicleta : public Veiculo {
public:
    void emitirSom() override {
        cout << "Vrum.. Vrum" << endl;
    }
};

int main() {
    Carro c1;
    c1.marca = "Fiat";

    Motocicleta m1;
    m1.marca = "Yamaha";

    Carro c2;
    c2.marca = "Chevrolet";

    vector<Veiculo*> garagem;
    garagem.push_back(&c1);
    garagem.push_back(&m1);
    garagem.push_back(&c2);

    for (int i = 0; i < garagem.size(); i++) {
        cout << garagem[i]->marca << ": ";
        garagem[i]->emitirSom();
    }

    return 0;
}