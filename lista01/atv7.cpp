#include <iostream>
#include <string>

using namespace std;

int main() {
    string entrada;

    cout << "Digite um numero inteiro em formato de string: ";
    cin >> entrada;

    int numero = stoi(entrada);

    bool b = static_cast<bool>(numero);

    bool Positivo = (numero > 0);
    bool Par = (numero % 2 == 0);
    bool positivoepar = b && Positivo && Par;

    cout << boolalpha;
    cout << "Valor convertido para int: " << numero << endl;
    cout << "Convertido para bool (nao zero): " << b << endl;
    cout << "E positivo e par? " << positivoepar << endl;

    return 0;
}