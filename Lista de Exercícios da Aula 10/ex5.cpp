#include <iostream>
#include <vector>

using namespace std;

class FormaGeometrica {
public:
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;
};

class Retangulo : public FormaGeometrica {
private:
    double largura;
    double altura;

public:
    Retangulo(double l, double a) {
        largura = l;
        altura = a;
    }

    double calcularArea() override {
        return largura * altura;
    }

    double calcularPerimetro() override {
        return 2 * (largura + altura);
    }
};

class Circulo : public FormaGeometrica {
private:
    double raio;

public:
    Circulo(double r) {
        raio = r;
    }

    double calcularArea() override {
        return 3.14159 * raio * raio;
    }

    double calcularPerimetro() override {
        return 2 * 3.14159 * raio;
    }
};

int main() {
    // FormaGeometrica f; // ERRO: nao da pra instanciar classe abstrata

    Retangulo ret(4.0, 5.0);
    Circulo circ(3.0);

    vector<FormaGeometrica*> formas;
    formas.push_back(&ret);
    formas.push_back(&circ);

    for (int i = 0; i < formas.size(); i++) {
        cout << "Figura " << i + 1 << endl;
        cout << "  Area: " << formas[i]->calcularArea() << endl;
        cout << "  Perimetro: " << formas[i]->calcularPerimetro() << endl;
    }

    return 0;
}