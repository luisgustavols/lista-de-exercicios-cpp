#include <iostream>
#include <string>

using namespace std;

int main() {
    string nome;
    int idade;
    float notaFinal;

    cout << "Digite o nome completo do aluno: ";
    getline(cin, nome);

    cout << "Digite a idade do aluno: ";
    cin >> idade;

    cout << "Digite a nota final do aluno: ";
    cin >> notaFinal;

    string notaStr = to_string(notaFinal);

    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "Nota Final (convertida para string): " << notaStr << endl;

    return 0;
}