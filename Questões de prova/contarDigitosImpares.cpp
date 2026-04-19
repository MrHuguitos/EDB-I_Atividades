#include <iostream>
using namespace std;

int contarDigitosImpares(int N) {
    if (N < 10) return (N % 2 == 0) ? 0 : 1;
    
    return ((N % 10) % 2 != 0) ? 1 + contarDigitosImpares(N / 10) : 0 + contarDigitosImpares(N / 10);
}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 0 e o valor retornado foi " << contarDigitosImpares(0) << endl;
    if (contarDigitosImpares(0) == 0) testesPassados++;
    cout << "Teste 2: O resultado esperado é 1 e o valor retornado foi " << contarDigitosImpares(9) << endl;
    if (contarDigitosImpares(9) == 1) testesPassados++;
    cout << "Teste 3: O resultado esperado é 6 e o valor retornado foi " << contarDigitosImpares(111111) << endl;
    if (contarDigitosImpares(111111) == 6) testesPassados++;
    cout << "Teste 4: O resultado esperado é 0 e o valor retornado foi " << contarDigitosImpares(24680) << endl;
    if (contarDigitosImpares(24680) == 0) testesPassados++;
    cout << "Teste 5: O resultado esperado é 6 e o valor retornado foi " << contarDigitosImpares(1267774613) << endl;
    if (contarDigitosImpares(1267774613) == 6) testesPassados++;
    cout << "Teste 6: O resultado esperado é 5 e o valor retornado foi " << contarDigitosImpares(1234567890) << endl;
    if (contarDigitosImpares(1234567890) == 5) testesPassados++;
    cout << "Teste 7: O resultado esperado é 5 e o valor retornado foi " << contarDigitosImpares(987654321) << endl;
    if (contarDigitosImpares(987654321) == 5) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 7 testes." << endl;
}
