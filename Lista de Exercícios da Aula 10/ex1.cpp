#include <iostream>
#include <string>

using namespace std;

class Veiculo {
public:
    string marca;
};

class Carro : public Veiculo {
public:
    int numeroPortas;
};

int main() {
    Carro meuCarro;
    meuCarro.marca = "Toyota";
    meuCarro.numeroPortas = 4;

    cout << "Marca: " << meuCarro.marca << endl;
    cout << "Portas: " << meuCarro.numeroPortas << endl;

    return 0;
}