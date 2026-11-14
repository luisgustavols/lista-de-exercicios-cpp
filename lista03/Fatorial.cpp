#include <iostream>

using namespace std;


long long calcularFatorial(int n) {
    if (n < 0) {
        return -1; 
    }
    
    long long fatorial = 1;
    
    for (int i = 1; i <= n; ++i) {
        fatorial *= i;
    }
    
    return fatorial;
}

int main() {
    int numero;

    cout << "Digite um numero inteiro nao negativo: ";
    cin >> numero;

    long long resultado = calcularFatorial(numero);

    if (resultado == -1) {
        cout << "\nErro: O fatorial nao e definido para numeros negativos." << endl;
    } else {
        cout << "\nO fatorial de " << numero << " (!" << numero << ") e: " << resultado << endl;
    }

    return 0;
}