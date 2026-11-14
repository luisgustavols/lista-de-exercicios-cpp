#include <iostream>

using namespace std;

class Vetor3D {
private:
    double x;
    double y;
    double z;

public:
    Vetor3D(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}

    Vetor3D operator+(const Vetor3D& outro) const {
        return Vetor3D(x + outro.x, y + outro.y, z + outro.z);
    }

    double operator*(const Vetor3D& outro) const {
        return (x * outro.x) + (y * outro.y) + (z * outro.z);
    }

    void exibir() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

int main() {
    Vetor3D v1(2.0, 3.0, 4.0);
    Vetor3D v2(1.0, -2.0, 5.0);

    Vetor3D soma = v1 + v2;
    double produtoEscalar = v1 * v2;

    cout << "v1 = "; v1.exibir(); cout << "\n";
    cout << "v2 = "; v2.exibir(); cout << "\n\n";

    cout << "Soma vetorial (v1 + v2) = ";
    soma.exibir();
    cout << "\n";

    cout << "Produto escalar (v1 * v2) = " << produtoEscalar << "\n";

    return 0;
}