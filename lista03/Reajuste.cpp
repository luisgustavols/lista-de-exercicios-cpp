#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    double salarioAtual, percentual, valorReajuste, novoSalario;

    
    cout << "Digite o salario atual (R$): ";
    cin >> salarioAtual;

    
    if (salarioAtual < 3000.0) {
        percentual = 0.50; 
    } 
    else if (salarioAtual <= 10000.0) {
        percentual = 0.20; 
    } 
    else {
        percentual = 0.15; 
    }

    
    valorReajuste = salarioAtual * percentual;
    novoSalario = salarioAtual + valorReajuste;

    
    cout << fixed << setprecision(2);

   
    cout << "\nReajuste" << endl;
    cout << "Percentual aplicado: " << (percentual * 100) << "%" << endl;
    cout << "Valor do aumento: R$ " << valorReajuste << endl;
    cout << "Novo salario: R$ " << novoSalario << endl;

    return 0;
}