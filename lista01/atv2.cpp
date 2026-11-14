#include <iostream>
using namespace std;

int main() {
    
    double celsius;

    cout << "Digite a temperatura em graus Celsius: ";
    cin >> celsius;

    double fahrenheit = celsius * 1.8 + 32;
    double kelvin = celsius + 273.15;
    int fahrenheitInteiro = static_cast<int>(fahrenheit);

    cout << "Temperatura em Celsius: " << celsius << " C" << endl;
    cout << "Temperatura em Fahrenheit: " << fahrenheit << " F" << endl;
    cout << "Temperatura em Kelvin: " << kelvin << " K" << endl;
    cout << "Fahrenheit convertido para inteiro (static_cast): " << fahrenheitInteiro << endl;

    return 0;
}