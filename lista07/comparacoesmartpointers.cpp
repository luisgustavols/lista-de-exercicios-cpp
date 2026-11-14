#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {

    auto exclusivo = make_unique<string>("Objeto com posse exclusiva");
    cout << "unique_ptr: " << *exclusivo << '\n';

    auto novoDono = move(exclusivo);
    cout << "Posse transferida: " << (exclusivo == nullptr ? "sim" : "nao")
              << "\nNovo dono: " << *novoDono << "\n\n";

    auto compartilhado = make_shared<string>("Objeto compartilhado");
    cout << "Antes da copia: use_count() = "
              << compartilhado.use_count() << '\n';
    {
        auto outraReferencia = compartilhado;
        cout << "Durante a copia: use_count() = "
                  << compartilhado.use_count() << '\n';
    }
    cout << "Depois da copia: use_count() = "
              << compartilhado.use_count() << "\n\n";

    weak_ptr<string> observador = compartilhado;
    if (auto objeto = observador.lock()) {
        cout << "lock(): objeto ainda existe: " << *objeto << '\n';
    }

    compartilhado.reset();
    if (auto objeto = observador.lock()) {
        cout << "lock(): objeto ainda existe: " << *objeto << '\n';
    } else {
        cout << "lock(): objeto observado nao existe mais.\n";
    }

    return 0;
}