#include <iostream>
#include <string>

using namespace std;

class Recurso {
public:
    Recurso() {
        cout << "[Recurso] Criado." << endl;
    }

    // Sem "virtual" aqui, deletar via Recurso* nao chamaria o destrutor de RecursoArquivo
    virtual ~Recurso() {
        cout << "[Recurso] Destruido." << endl;
    }
};

class RecursoArquivo : public Recurso {
private:
    string nomeArquivo;
    int* buffer;

public:
    RecursoArquivo(string nome) {
        nomeArquivo = nome;
        buffer = new int[100];
        cout << "[RecursoArquivo] Abriu '" << nomeArquivo << "' e alocou buffer." << endl;
    }

    ~RecursoArquivo() {
        delete[] buffer;
        cout << "[RecursoArquivo] Liberou buffer e fechou '" << nomeArquivo << "'." << endl;
    }
};

int main() {
    Recurso* r = new RecursoArquivo("dados.txt");

    cout << "--- Deletando pelo ponteiro da classe base ---" << endl;
    delete r;

    return 0;
}