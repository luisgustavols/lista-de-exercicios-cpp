#include <iostream>
using namespace std;

int main() {
    int ano;
    cout << "DIgite o ano: ";
    cin >> ano;
    if (ano >= 1930 && (ano - 1930) % 4 == 0 && ano != 1942 && ano != 1946) {
        cout << "Ano de copa do mundo" << endl;
    } else {
        cout << "Não é ano de copa do mundo." << endl;
    }
    
    
    return 0;
}