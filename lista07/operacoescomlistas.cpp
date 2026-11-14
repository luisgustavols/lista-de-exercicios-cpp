#include <iostream>
#include <list>

using namespace std;

// Função para exibir o menu de opções
void exibirMenu() {
    cout << "\n======================================\n";
    cout << "    GERENCIADOR DE LISTA DE INTEIROS  \n";
    cout << "======================================\n";
    cout << "1. Inserir valor (no final)\n";
    cout << "2. Remover o primeiro elemento (pop_front)\n";
    cout << "3. Remover o ultimo elemento (pop_back)\n";
    cout << "4. Remover todas as ocorrencias de um valor\n";
    cout << "5. Exibir a lista atualizada\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    // Criação da lista de inteiros
    list<int> numeros;
    int opcao = 0;

    do {
        exibirMenu();
        if (!(cin >> opcao)) {
            cout << "Entrada invalida. Tente novamente.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }

        switch (opcao) {
            case 1: {
                int valor;
                cout << "Digite o valor inteiro para inserir: ";
                cin >> valor;
                numeros.push_back(valor);
                cout << "Valor " << valor << " inserido com sucesso!\n";
                break;
            }
            case 2: {
                if (numeros.empty()) {
                    cout << "Aviso: A lista esta vazia! Nao e possivel remover o primeiro elemento.\n";
                } else {
                    int removido = numeros.front();
                    numeros.pop_front();
                    cout << "Primeiro elemento (" << removido << ") removido com sucesso!\n";
                }
                break;
            }
            case 3: {
                if (numeros.empty()) {
                    cout << "Aviso: A lista esta vazia! Nao e possivel remover o ultimo elemento.\n";
                } else {
                    int removido = numeros.back();
                    numeros.pop_back();
                    cout << "Ultimo elemento (" << removido << ") removido com sucesso!\n";
                }
                break;
            }
            case 4: {
                if (numeros.empty()) {
                    cout << "Aviso: A lista esta vazia! Nao ha elementos para remover.\n";
                } else {
                    int valorAlvo;
                    cout << "Digite o valor que deseja remover completamente: ";
                    cin >> valorAlvo;

                    size_t tamanhoAntes = numeros.size();
                    
                    numeros.remove(valorAlvo);

                    size_t tamanhoDepois = numeros.size();
                    size_t removidos = tamanhoAntes - tamanhoDepois;

                    if (removidos > 0) {
                        cout << "Removidas " << removidos << " ocorrencia(s) do valor " << valorAlvo << ".\n";
                    } else {
                        cout << "O valor " << valorAlvo << " nao foi encontrado na lista.\n";
                    }
                }
                break;
            }
            case 5: {
                cout << "\n--- LISTA ATUALIZADA ---\n";
                if (numeros.empty()) {
                    cout << "[ Lista Vazia ]\n";
                } else {
                    cout << "Elementos: ";
                    for (int n : numeros) {
                        cout << n << " ";
                    }
                    cout << "\nTotal de elementos: " << numeros.size() << "\n";
                }
                break;
            }
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida! Escolha uma opcao entre 0 e 5.\n";
        }
    } while (opcao != 0);

    return 0;
}