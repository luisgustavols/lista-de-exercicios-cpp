#include <iostream>
using namespace std;

int main() { 
    int n; 
    
    cout << "Digite sua idade: ";
    cin >> n;

    
    if (n < 0 || n > 120) {
        cout << "Digite uma idade válida." << endl;
    }
    else if (n < 2) {
        cout << "A pessoa tem a idade de um bebê." << endl;
    }
    else if (n < 12) {
        cout << "A pessoa tem a idade de uma criança." << endl;
    }
    else if (n < 18) {
        cout << "A pessoa tem a idade de um adolescente." << endl;
    }
    else if (n < 65) {
        cout << "A pessoa tem a idade de um adulto." << endl; 
    }
    else {
        cout << "A pessoa tem a idade de um idoso." << endl;
    }

    return 0;
}