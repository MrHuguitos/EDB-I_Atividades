#include <iostream>
using namespace std;

bool consecutivosIguais(int N) {
    if (N <= 10) return false;
    if (((N / 10) % 10) == (N % 10)) return true;

    return consecutivosIguais(N / 10);
}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é false e o valor retornado foi " << consecutivosIguais(0) << endl;
    if (consecutivosIguais(0) == false) testesPassados++;
    cout << "Teste 2: O resultado esperado é false e o valor retornado foi " << consecutivosIguais(9) << endl;
    if (consecutivosIguais(9) == false) testesPassados++;
    cout << "Teste 3: O resultado esperado é false e o valor retornado foi " << consecutivosIguais(10) << endl;
    if (consecutivosIguais(10) == false) testesPassados++;
    cout << "Teste 4: O resultado esperado é false e o valor retornado foi " << consecutivosIguais(98) << endl;
    if (consecutivosIguais(98) == false) testesPassados++;
    cout << "Teste 5: O resultado esperado é false e o valor retornado foi " << consecutivosIguais(919) << endl;
    if (consecutivosIguais(919) == false) testesPassados++;
    cout << "Teste 6: O resultado esperado é false e o valor retornado foi " << consecutivosIguais(1919) << endl;
    if (consecutivosIguais(1919) == false) testesPassados++;
    cout << "Teste 7: O resultado esperado é true e o valor retornado foi " << consecutivosIguais(11) << endl;
    if (consecutivosIguais(11) == true) testesPassados++;
    cout << "Teste 8: O resultado esperado é true e o valor retornado foi " << consecutivosIguais(99) << endl;
    if (consecutivosIguais(99) == true) testesPassados++;
    cout << "Teste 9: O resultado esperado é true e o valor retornado foi " << consecutivosIguais(1003456789) << endl;
    if (consecutivosIguais(1003456789) == true) testesPassados++;
    cout << "Teste 10: O resultado esperado é true e o valor retornado foi " << consecutivosIguais(1123456789) << endl;
    if (consecutivosIguais(1123456789) == true) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 10 testes." << endl;
}