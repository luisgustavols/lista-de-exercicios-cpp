#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Produto {
private:
    const int codigo;
    string nome;
    double preco;

public:
    Produto(int cod, const string& n, double p) : codigo(cod), nome(n), preco(p) {
        if (codigo <= 0) {
            throw invalid_argument("O codigo do produto deve ser positivo.");
        }
        if (preco < 0) {
            throw invalid_argument("O preco nao pode ser negativo.");
        }
    }

    int getCodigo() const { return codigo; }
    string getNome() const { return nome; }
    double getPreco() const { return preco; }

    void setPreco(double novoPreco) {
        if (novoPreco < 0) {
            throw invalid_argument("O preco nao pode ser negativo.");
        }
        preco = novoPreco;
    }

    void exibir() const {
        cout << "Codigo: " << codigo
             << " | Produto: " << nome
             << " | Preco: R$ " << fixed << setprecision(2) << preco << "\n";
    }
};

int main() {
    Produto p1(101, "Teclado Mecanico", 350.00);
    Produto p2(102, "Mouse Sem Fio", 120.50);

    p1.exibir();
    p2.exibir();

    p2.setPreco(99.90);
    cout << "\nApos atualizacao de preco:\n";
    p2.exibir();

    return 0;
}