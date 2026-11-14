#include <iostream>
#include <string>

using namespace std;

double calcularArea(double lado) {
    return lado * lado;
}
double calcularArea(double largura, double altura) {
    return largura * altura;
}
double calcularArea(double base, double altura, const string& forma) {
    if (forma == "triangulo") {
        return (base * altura) / 2.0;
    }
    return 0.0;
}

int main() {
    double areaQuadrado  = calcularArea(5.0);
    double areaRetangulo = calcularArea(4.0, 6.0);
    double areaTriangulo = calcularArea(4.0, 6.0, "triangulo");

    cout << "Area do Quadrado:  " << areaQuadrado  << "\n";
    cout << "Area do Retangulo: " << areaRetangulo << "\n";
    cout << "Area do Triangulo: " << areaTriangulo << "\n";

    return 0;
}