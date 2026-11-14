#include <iostream>
#include <typeinfo> 

using namespace std;

int main () {

    char letra = 'a';
    float flutuante = 5.5;
    bool booleano = true;
    double dflutuante = 10.9444;
    int inteiro = 10;
    short pequeno = 1;
    long longo = 100000;
    unsigned int semNEGATIVO = 100; 

    
    cout << typeid(letra).name() << "  Valor: " << letra << "  Tamanho: " << sizeof(letra) << endl;
    cout << typeid(flutuante).name() << "  Valor: " << flutuante << "  Tamanho: " << sizeof(flutuante) << endl;
    cout << typeid(booleano).name() << "  Valor: " << booleano << "  Tamanho: " << sizeof(booleano) << endl;
    cout << typeid(dflutuante).name() << "  Valor: " << dflutuante << "  Tamanho: " << sizeof(dflutuante) << endl;
    cout << typeid(inteiro).name() << "  Valor: " << inteiro << "  Tamanho: " << sizeof(inteiro) << endl;
    cout << typeid(pequeno).name() << "  Valor: " << pequeno << "  Tamanho: " << sizeof(pequeno) << endl;
    cout << typeid(longo).name() << "  Valor: " << longo << "  Tamanho: " << sizeof(longo) << endl;
    cout << typeid(semNEGATIVO).name() << "  Valor: " << semNEGATIVO << "  Tamanho: " << sizeof(semNEGATIVO) << endl;

    return 0;
}