#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    stack<string> pilhaPalavras;
    string frase;

    cout << "Digite uma frase: ";   
    getline(cin, frase);

    stringstream ss(frase);
    string palavra;

    while (ss >> palavra) {
        pilhaPalavras.push(palavra);
    }

    cout << "\nFrase em ordem inversa:\n";
    
    while (!pilhaPalavras.empty()) {
        cout << pilhaPalavras.top() << " ";
        pilhaPalavras.pop(); 
    }
    cout << endl;

    return 0;
}