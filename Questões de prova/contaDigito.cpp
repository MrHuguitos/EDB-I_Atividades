#include <iostream>
using namespace std;

int contaDigito(int N, int D) {
    if (N < 10) return (N == D) ? 1 : 0;
    
    return (N % 10 == D) ? 1 + contaDigito(N / 10, D) : 0 + contaDigito(N / 10, D);
}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 1 e o valor retornado foi " << contaDigito(1234, 1) << endl;
    if (contaDigito(1234, 1) == 1) testesPassados++;
    cout << "Teste 2: O resultado esperado é 1 e o valor retornado foi " << contaDigito(1234, 2) << endl;
    if (contaDigito(1234, 2) == 1) testesPassados++;
    cout << "Teste 3: O resultado esperado é 1 e o valor retornado foi " << contaDigito(1234, 3) << endl;
    if (contaDigito(1234, 3) == 1) testesPassados++;
    cout << "Teste 4: O resultado esperado é 1 e o valor retornado foi " << contaDigito(1234, 4) << endl;
    if (contaDigito(1234, 4) == 1) testesPassados++;
    cout << "Teste 5: O resultado esperado é 0 e o valor retornado foi " << contaDigito(1234, 5) << endl;
    if (contaDigito(1234, 5) == 0) testesPassados++;
    cout << "Teste 6: O resultado esperado é 0 e o valor retornado foi " << contaDigito(243434, 1) << endl;
    if (contaDigito(243434, 1) == 0) testesPassados++;
    cout << "Teste 7: O resultado esperado é 1 e o valor retornado foi " << contaDigito(243434, 2) << endl;
    if (contaDigito(243434, 2) == 1) testesPassados++;
    cout << "Teste 8: O resultado esperado é 2 e o valor retornado foi " << contaDigito(243434, 3) << endl;
    if (contaDigito(243434, 3) == 2) testesPassados++;
    cout << "Teste 8: O resultado esperado é 3 e o valor retornado foi " << contaDigito(243434, 4) << endl;
    if (contaDigito(243434, 4) == 3) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 9 testes." << endl;
}
