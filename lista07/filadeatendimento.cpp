#include <iostream>
#include <queue>
#include <string>

using namespace std;

void exibirMenu() {
    cout << "\n======================================\n";
    cout << "     SISTEMA DE FILA DE ATENDIMENTO   \n";
    cout << "======================================\n";
    cout << "1. Adicionar pessoa (push)\n";
    cout << "2. Chamar proxima pessoa (pop)\n";
    cout << "3. Informar quantas aguardam (size)\n";
    cout << "4. Verificar se a fila esta vazia (empty)\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {

    queue<string> filaAtendimento;
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
                string nomePessoa;
                cout << "Digite o nome da pessoa que chegou: ";
                getline(cin, nomePessoa);
                
                filaAtendimento.push(nomePessoa);
                cout << "\"" << nomePessoa << "\" entrou na fila de atendimento com sucesso.\n";
                break;
            }
            case 2: {
                if (filaAtendimento.empty()) {
                    cout << "Aviso: A fila esta vazia! Nao ha ninguem para chamar.\n";
                } else {
                    cout << "Chamando para atendimento: \"" << filaAtendimento.front() << "\"\n";
                    filaAtendimento.pop();
                }
                break;
            }
            case 3: {
                cout << "Quantidade de pessoas aguardando na fila: " << filaAtendimento.size() << '\n';
                break;
            }
            case 4: {
                if (filaAtendimento.empty()) {
                    cout << "Status: A fila esta VAZIA.\n";
                } else {
                    cout << "Status: A fila NAO esta vazia. Ha pessoas aguardando.\n";
                }
                break;
            }
            case 0:
                cout << "Encerrando o sistema de atendimento...\n";
                break;
            default:
                cout << "Opcao invalida! Escolha entre 0 e 4.\n";
        }
    } while (opcao != 0);

    return 0;
}