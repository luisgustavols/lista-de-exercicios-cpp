#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Digite um número limite: ";
    cin >> n;
    
    int a = 0, b = 1;
    cout << "Sequência de Fibonacci: ";
    
    while (a <= n) {
        cout << a << " ";
        int temp = a + b;
        a = b;
        b = temp;
    }
    cout << endl; 
    
    return 0;
}