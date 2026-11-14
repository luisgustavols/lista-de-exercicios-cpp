#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class ArquivoTexto {
private:
    ofstream arquivo;
    string caminho;

public:
    // Construtor: adquire o recurso (abre o arquivo para escrita)
    ArquivoTexto(const string& caminhoArquivo) : caminho(caminhoArquivo) {
        arquivo.open(caminho);
        if (!arquivo.is_open()) {
            throw runtime_error("Erro: Nao foi possivel abrir o arquivo '" + caminho + "' para escrita.");
        }
        cout << "[Construtor] Arquivo '" << caminho << "' aberto com sucesso.\n";
    }

    // Destrutor: libera o recurso automaticamente (fecha o arquivo)
    ~ArquivoTexto() {
        if (arquivo.is_open()) {
            arquivo.close();
            cout << "[Destrutor] Arquivo '" << caminho << "' fechado automaticamente.\n";
        }
    }

    void escreverLinha(const string& texto) {
        if (arquivo.is_open()) {
            arquivo << texto << "\n";
        }
    }
};

int main() {
    cout << "Iniciando o programa principal...\n\n";

    try {
        // Bloco de escopo delimitado por chaves
        {
            cout << "--- Entrando no bloco de escopo ---\n";
            ArquivoTexto doc("saida.txt");
            doc.escreverLinha("Primeira linha gravada com seguranca.");
            doc.escreverLinha("Demonstracao do padrao RAII em C++.");
            cout << "--- Saindo do bloco de escopo ---\n";
        } // O objeto 'doc' sai de escopo aqui e seu destrutor é invocado imediatamente

        cout << "\nExecucao continua apos o fechamento automatico do arquivo.\n";

        // Teste de falha na abertura (caminho inválido/inexistente)
        cout << "\nTestando caminho invalido:\n";
        ArquivoTexto docInvalido("/diretorio_inexistente/teste.txt");
    }
    catch (const exception& e) {
        cerr << e.what() << "\n";
    }

    return 0;
}