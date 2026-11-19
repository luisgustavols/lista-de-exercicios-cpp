#include <iostream>
#include <string>

using namespace std;

class Funcionario {
public:
    string nome;

protected:
    double salario;

private:
    string documento;

public:
    // So pra gente conseguir dar um valor inicial pro documento no teste
    void setDocumento(string doc) {
        documento = doc;
    }
};

class Gerente : public Funcionario {
public:
    void configurarGerente(double novoSalario) {
        nome = "Carlos";       
        salario = novoSalario; 
    }

    void mostrarDados() {
        cout << "Nome (via Gerente): " << nome << endl;
        cout << "Salario (via Gerente): " << salario << endl;
    }
};

int main() {
    Gerente g;
    g.configurarGerente(8500.0);
    g.setDocumento("123.456.789-00");

    // Fora da classe (no main):
    cout << "Nome no main: " << g.nome << endl; // OK: e public

    // As linhas abaixo dao erro de compilacao se descomentar:
    // cout << g.salario;   // ERRO: protected nao e acessivel fora da classe/heranca
    // cout << g.documento; // ERRO: private nao e acessivel fora de Funcionario

    g.mostrarDados();

    return 0;
}