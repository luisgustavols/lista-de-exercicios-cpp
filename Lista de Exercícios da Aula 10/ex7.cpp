#include <iostream>
#include <string>

using namespace std;

class Dispositivo {
public:
    string identificador;

    void exibirIdentificador() {
        cout << "Identificador do dispositivo: " << identificador << endl;
    }
};

// Sem "virtual", Impressora e Scanner levam cada um uma copia de Dispositivo.
// Com "virtual", ambos compartilham uma unica base Dispositivo dentro de Multifuncional.
class Impressora : virtual public Dispositivo {
public:
    void imprimir() {
        cout << "Imprimindo documento..." << endl;
    }
};

class Scanner : virtual public Dispositivo {
public:
    void escanear() {
        cout << "Escaneando pagina..." << endl;
    }
};

class Multifuncional : public Impressora, public Scanner {
public:
    void testarTudo() {
        imprimir();
        escanear();
        exibirIdentificador();
    }
};

int main() {
    Multifuncional mf;

    // Sem heranca virtual na base, isso daria erro de ambiguidade:
    // mf.identificador = "MF-2026";
    // mf.exibirIdentificador();

    mf.identificador = "MF-2026";
    mf.testarTudo();

    return 0;
}