#include <iostream>
#include <queue>
#include <string>

using namespace std;

void exibirMenu() {
    cout << "\n======================================\n";
    cout << "      SISTEMA DE FILA DE IMPRESSAO    \n";
    cout << "======================================\n";
    cout << "1. Adicionar documento (push)\n";
    cout << "2. Processar proximo documento (pop)\n";
    cout << "3. Consultar proximo documento (front)\n";
    cout << "4. Verificar se a fila esta vazia (empty)\n";
    cout << "5. Ver quantidade de documentos (size)\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    queue<string> filaImpressao;
    int opcao = 0;

    do {
        exibirMenu();
        if (!(cin >> opcao)) {
            cout << "Entrada invalida. Tente novamente.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }

        cin.ignore();

        switch (opcao) {
            case 1: {
                string nomeDocumento;
                cout << "Digite o nome do documento a ser impresso: ";
                getline(cin, nomeDocumento);
                
                filaImpressao.push(nomeDocumento);
                cout << "Documento \"" << nomeDocumento << "\" adicionado a fila de impressao.\n";
                break;
            }
            case 2: {
                if (filaImpressao.empty()) {
                    cout << "Aviso: A fila de impressao esta vazia! Nenhum documento para processar.\n";
                } else {
                    cout << "Imprimindo e removendo: \"" << filaImpressao.front() << "\"\n";
                    filaImpressao.pop();
                }
                break;
            }
            case 3: {
                if (filaImpressao.empty()) {
                    cout << "A fila de impressao esta vazia.\n";
                } else {
                    cout << "Proximo documento na fila (aguardando): \"" << filaImpressao.front() << "\"\n";
                }
                break;
            }
            case 4: {
                if (filaImpressao.empty()) {
                    cout << "Status: A fila esta VAZIA.\n";
                } else {
                    cout << "Status: A fila NAO esta vazia. Ha documentos aguardando.\n";
                }
                break;
            }
            case 5: {
                cout << "Quantidade de documentos na fila: " << filaImpressao.size() << '\n';
                break;
            }
            case 0:
                cout << "Encerrando o sistema de impressao...\n";
                break;
            default:
                cout << "Opcao invalida! Escolha entre 0 e 5.\n";
        }
    } while (opcao != 0);

    return 0;
}