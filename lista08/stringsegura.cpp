#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

class StringSegura {
private:
    char* dados;
    size_t tamanho;

public:
    StringSegura() = default;

    StringSegura(const char* texto) {
        if (texto) {
            tamanho = strlen(texto);
            dados = new char[tamanho + 1];
            strcpy(dados, texto);
        } else {
            tamanho = 0;
            dados = nullptr;
        }
    }

    ~StringSegura() {
        delete[] dados;
    }

    // Construtor de cópia impedido (= delete)
    StringSegura(const StringSegura&) = delete;

    // Cópia por atribuição tradicional impedida (= delete)
    StringSegura& operator=(const StringSegura&) = delete;

    // Construtor de movimentação (Move Constructor) para permitir transferência de posse
    StringSegura(StringSegura&& outra) noexcept : dados(outra.dados), tamanho(outra.tamanho) {
        outra.dados = nullptr;
        outra.tamanho = 0;
    }

    // Atribuição por movimentação (Move Assignment)
    StringSegura& operator=(StringSegura&& outra) noexcept {
        if (this != &outra) {
            delete[] dados;
            dados = outra.dados;
            tamanho = outra.tamanho;

            outra.dados = nullptr;
            outra.tamanho = 0;
        }
        return *this;
    }

    void exibir() const {
        if (dados) {
            cout << dados << "\n";
        } else {
            cout << "[Vazia / Recurso Movido]\n";
        }
    }

private:
    // Inicialização padrão dos membros para dar suporte seguro ao construtor = default
    // (Declarações movidas para o topo na prática, mas mantidas consistentes com a estrutura)
};

// Nota: Para que StringSegura() = default inicialize ponteiros com segurança sem lixo,
// os atributos privados são declarados com inicializadores padrão abaixo:
class StringSeguraCompleta {
private:
    char* dados = nullptr;
    size_t tamanho = 0;

public:
    StringSeguraCompleta() = default;

    // Construtor parametrizado
    StringSeguraCompleta(const char* texto) {
        if (texto) {
            tamanho = strlen(texto);
            dados = new char[tamanho + 1];
            strcpy(dados, texto);
        }
    }

    // Destrutor
    ~StringSeguraCompleta() {
        delete[] dados;
    }

    StringSeguraCompleta(const StringSeguraCompleta&) = delete;
    StringSeguraCompleta& operator=(const StringSeguraCompleta&) = delete;

    StringSeguraCompleta(StringSeguraCompleta&& outra) noexcept
        : dados(outra.dados), tamanho(outra.tamanho) {
        outra.dados = nullptr;
        outra.tamanho = 0;
    }

    StringSeguraCompleta& operator=(StringSeguraCompleta&& outra) noexcept {
        if (this != &outra) {
            delete[] dados;
            dados = outra.dados;
            tamanho = outra.tamanho;
            outra.dados = nullptr;
            outra.tamanho = 0;
        }
        return *this;
    }

    void exibir() const {
        cout << (dados ? dados : "[Vazia / Recurso Movido]") << "\n";
    }
};

int main() {
    //Usos permitidos
    StringSeguraCompleta s1; // Usa o construtor padrão (= default)
    StringSeguraCompleta s2("Recurso Gerenciado com Seguranca");

    cout << "s1 inicial: "; s1.exibir();
    cout << "s2 inicial: "; s2.exibir();

    s1 = move(s2);

    cout << "\nApos s1 = move(s2):\n";
    cout << "s1: "; s1.exibir();
    cout << "s2: "; s2.exibir();

    StringSeguraCompleta s3 = move(s1);
    cout << "\nApos s3 = move(s1):\n";
    cout << "s3: "; s3.exibir();

//USOS REJEITADOS PELO COMPILADOR ---
// StringSeguraCompleta s4 = s3; // ERRO DE COMPILACAO: construtor de copia deletado (= delete)
// s1 = s3;                      // ERRO DE COMPILACAO: operador de atribuicao por copia deletado (= delete)

    return 0;
}