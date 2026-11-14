#include <iostream>
using namespace std;

#define TAXA_JUROS 0.05

int main() {
    
    const int ANOS = 3;
    double capitalInicial;

    cout << "Digite o valor do capital inicial (R$): ";
    cin >> capitalInicial;

    double montanteFinal = capitalInicial * (1 + TAXA_JUROS * ANOS);
    double diferencaJuros = montanteFinal - capitalInicial;

    
    cout << "\n--- Resumo da Aplicacao Financeira ---" << endl;
    cout << "Capital Inicial: R$ " << capitalInicial << endl;
    cout << "Taxa de Juros: 5% ao ano" << endl;
    cout << "Periodo: " << ANOS << " anos" << endl;
    cout << "Montante Final: R$ " << montanteFinal << endl;
    cout << "Lucro (Diferenca): R$ " << diferencaJuros << endl;

    return 0;
}