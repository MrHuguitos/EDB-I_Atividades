#include <iostream>
using namespace std;

bool verificarPrimo(int numero, int divisor) {
    if (divisor <= 1) return true;
    if (numero % divisor == 0) return false;

    return verificarPrimo(numero, (divisor - 1));
}

int contarPrimosAteN(int N) {
    if (N <= 1) return 0;

    return (verificarPrimo(N, (N - 1)) == false) ? 0 + contarPrimosAteN(N - 1) : 1 + contarPrimosAteN(N - 1);
}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 4 e o valor retornado foi " << contarPrimosAteN(10) << endl;
    if (contarPrimosAteN(10) == 4) testesPassados++;
    cout << "Teste 2: O resultado esperado é 8 e o valor retornado foi " << contarPrimosAteN(20) << endl;
    if (contarPrimosAteN(20) == 8) testesPassados++;
    cout << "Teste 3: O resultado esperado é 3 e o valor retornado foi " << contarPrimosAteN(5) << endl;
    if (contarPrimosAteN(5) == 3) testesPassados++;
    cout << "Teste 4: O resultado esperado é 0 e o valor retornado foi " << contarPrimosAteN(1) << endl;
    if (contarPrimosAteN(1) == 0) testesPassados++;
    cout << "Teste 5: O resultado esperado é 25 e o valor retornado foi " << contarPrimosAteN(100) << endl;
    if (contarPrimosAteN(100) == 25) testesPassados++;
    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}