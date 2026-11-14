#include <iostream>
#include <stdexcept>

using namespace std;

class Retangulo {
private:
    double largura;
    double altura;

public:
    Retangulo() : largura(1.0), altura(1.0) {}

    Retangulo(double l, double a) : largura(l), altura(a) {
        if (largura <= 0 || altura <= 0) {
            throw invalid_argument("As dimensoes devem ser maiores que zero.");
        }
    }

    Retangulo(double lado) : largura(lado), altura(lado) {
        if (lado <= 0) {
            throw invalid_argument("O lado do quadrado deve ser maior que zero.");
        }
    }

    double calcularArea() const {
        return largura * altura;
    }

    double calcularPerimetro() const {
        return 2 * (largura + altura);
    }

    void exibirDados() const {
        cout << "Dimensoes: " << largura << " x " << altura
             << " | Area: " << calcularArea()
             << " | Perimetro: " << calcularPerimetro() << "\n";
    }
};

int main() {
    Retangulo r1;
    cout << "Retangulo Padrao -> ";
    r1.exibirDados();

    Retangulo r2(4.0, 5.0);
    cout << "Retangulo Parametrizado -> ";
    r2.exibirDados();

    Retangulo r3(6.0);
    cout << "Quadrado -> ";
    r3.exibirDados();

    return 0;
}