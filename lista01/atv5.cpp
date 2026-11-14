#include <iostream>
using namespace std;

int contador = 100;

int main() {
    int contador = 10;

    cout << "Valor da variavel local (main): " << contador << endl;
    cout << "Valor da variavel global: " << ::contador << endl;

    if (true) {
        int contador = 1;

        cout << "Valor da variavel do bloco (if): " << contador << endl;
        cout << "Valor da variavel local (main) dentro do bloco: nao acessivel diretamente devido ao sombreamento" << endl;
        cout << "Valor da variavel global dentro do bloco: " << ::contador << endl;
    }

    cout << "Valor da variavel local (main) apos o bloco: " << contador << endl;

    return 0;
}