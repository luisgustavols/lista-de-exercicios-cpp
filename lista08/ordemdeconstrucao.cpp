#include <iostream>
#include <string>

using namespace std;

class Registro {
private:
    string nome;

public:
    Registro(const string& n) : nome(n) {
        cout << "[Construtor] Objeto '" << nome << "' criado.\n";
    }

    ~Registro() {
        cout << "[Destrutor]  Objeto '" << nome << "' destruido.\n";
    }
};

Registro objGlobal("Global");

int main() {
    cout << "--- Inicio do main ---\n";

    Registro objMain("Local_Main");

    {
        cout << "--- Entrando no bloco interno ---\n";
        Registro objBloco("Local_Bloco");
        cout << "--- Saindo do bloco interno ---\n";

    cout << "--- Fim do main ---\n";
    return 0;
}