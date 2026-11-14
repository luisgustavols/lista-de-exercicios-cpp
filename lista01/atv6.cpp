#include <iostream>

using namespace std;

namespace Geometria {
    namespace Retangulo {
        double calcularAreaRetangulo(double b, double h) {
            return b * h;
        }
    }

    namespace Circulo {
        double calcularAreaCirculo(double r) {
            const double PI = 3.14159;
            return PI * r * r;
        }
    }
}

int main() {
    cout << "1. Usando nome totalmente qualificado:" << endl;
    cout << "Area do retangulo (base 5, altura 3): " << Geometria::Retangulo::calcularAreaRetangulo(5.0, 3.0) << endl;
    cout << "Area do circulo (raio 4): " << Geometria::Circulo::calcularAreaCirculo(4.0) << endl;

    cout << "\n2. Usando declaracao using especifica:" << endl;
    using Geometria::Retangulo::calcularAreaRetangulo;
    cout << "Area do retangulo (base 6, altura 2): " << calcularAreaRetangulo(6.0, 2.0) << endl;

    cout << "\n3. Usando diretiva using namespace:" << endl;
    {
        using namespace Geometria::Circulo;
        cout << "Area do circulo (raio 3): " << calcularAreaCirculo(3.0) << endl;
    }

    return 0;
}