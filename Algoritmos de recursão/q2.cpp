#include <iostream>
using namespace std;

bool verificarPrimo(int numero, int divisor) {
    if (divisor <= 1) return true;
    if (numero % divisor == 0) return false;
        
    return verificarPrimo(numero, (divisor - 1)); 
}

bool ehPrimo(int numero) {
    if (numero <= 1) return false;
    if (verificarPrimo(numero, (numero - 1)) == false) return false;

    return true;
}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(5) << endl;
    if (ehPrimo(5) == true) testesPassados++;
    cout << "Teste 2: O resultado esperado é 0 e o valor retornado foi " << ehPrimo(10) << endl;
    if (ehPrimo(10) == false) testesPassados++;
    cout << "Teste 3: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(13) << endl;
    if (ehPrimo(13) == true) testesPassados++;
    cout << "Teste 4: O resultado esperado é 0 e o valor retornado foi " << ehPrimo(1) << endl;
    if (ehPrimo(1) == false) testesPassados++;
    cout << "Teste 5: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(17) << endl;
    if (ehPrimo(17) == true) testesPassados++;
    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}