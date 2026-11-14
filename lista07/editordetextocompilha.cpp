#include <iostream>
#include <stack>
#include <string>

using namespace std;

void exibirMenu() {
    cout << "\n======================================\n";
    cout << "     SIMULADOR DE EDITOR DE TEXTO     \n";
    cout << "======================================\n";
    cout << "1. Digitar palavra (push)\n";
    cout << "2. Desfazer ultima palavra (pop)\n";
    cout << "3. Consultar palavra no topo (top)\n";
    cout << "4. Verificar se o historico esta vazio (empty)\n";
    cout << "5. Ver quantidade de palavras no historico (size)\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    stack<string> historicoTexto;
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
                string palavra;
                cout << "Digite a palavra para adicionar ao texto: ";
                cin >> palavra; 
                
                historicoTexto.push(palavra);
                cout << "Palavra \"" << palavra << "\" adicionada com sucesso.\n";
                break;
            }
            case 2: {
                if (historicoTexto.empty()) {
                    cout << "Aviso: O historico esta vazio! Nao ha o que desfazer.\n";
                } else {
                    cout << "Desfazendo (removendo do topo): \"" << historicoTexto.top() << "\"\n";
                    historicoTexto.pop();
                }
                break;
            }
            case 3: {
                if (historicoTexto.empty()) {
                    cout << "O historico esta vazio. Nenhuma palavra no topo.\n";
                } else {
                    cout << "Ultima palavra digitada (topo): \"" << historicoTexto.top() << "\"\n";
                }
                break;
            }
            case 4: {
                if (historicoTexto.empty()) {
                    cout << "Status: O historico esta VAZIO.\n";
                } else {
                    cout << "Status: O historico NAO esta vazio.\n";
                }
                break;
            }
            case 5: {
                cout << "Quantidade de palavras no historico: " << historicoTexto.size() << '\n';
                break;
            }
            case 0:
                cout << "Encerrando o editor de texto...\n";
                break;
            default:
                cout << "Opcao invalida! Escolha entre 0 e 5.\n";
        }
    } while (opcao != 0);

    return 0;
}