#include <iostream>
using namespace std;

int menorDigito(int N) {
    if (N < 10) return N;
    
    int resto = menorDigito(N / 10);
    
    return ((N % 10) <= resto) ? N % 10 : resto;
}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 0 e o valor retornado foi " << menorDigito(0) << endl;
    if (menorDigito(0) == 0) testesPassados++;
    cout << "Teste 2: O resultado esperado é 9 e o valor retornado foi " << menorDigito(9) << endl;
    if (menorDigito(9) == 9) testesPassados++;
    cout << "Teste 3: O resultado esperado é 0 e o valor retornado foi " << menorDigito(10) << endl;
    if (menorDigito(10) == 0) testesPassados++;
    cout << "Teste 4: O resultado esperado é 1 e o valor retornado foi " << menorDigito(19) << endl;
    if (menorDigito(19) == 1) testesPassados++;
    cout << "Teste 5: O resultado esperado é 7 e o valor retornado foi " << menorDigito(879) << endl;
    if (menorDigito(879) == 7) testesPassados++;
    cout << "Teste 6: O resultado esperado é 2 e o valor retornado foi " << menorDigito(729) << endl;
    if (menorDigito(729) == 2) testesPassados++;
    cout << "Teste 7: O resultado esperado é 3 e o valor retornado foi " << menorDigito(8379) << endl;
    if (menorDigito(8379) == 3) testesPassados++;
    cout << "Teste 8: O resultado esperado é 2 e o valor retornado foi " << menorDigito(8729) << endl;
    if (menorDigito(8729) == 2) testesPassados++;
    cout << "Teste 9: O resultado esperado é 1 e o valor retornado foi " << menorDigito(23456178) << endl;
    if (menorDigito(23456178) == 1) testesPassados++;
    cout << "Teste 10: O resultado esperado é 1 e o valor retornado foi " << menorDigito(23145678) << endl;
    if (menorDigito(23145678) == 1) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 10 testes." << endl;
}
