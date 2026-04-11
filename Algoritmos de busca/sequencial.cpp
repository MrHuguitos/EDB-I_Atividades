#include <iostream>
using namespace std;

int buscaSequencial(int arr[], int tamanho, int alvo) {
    if (tamanho == 0) return -1;
    
    return (arr[tamanho - 1] == alvo) ? tamanho - 1 : buscaSequencial(arr, tamanho - 1, alvo);
}

int main() {
    int testesPassados = 0;
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Teste 1: O resultado esperado é 2 e o valor retornado foi " << buscaSequencial(arr, 5, 3) << endl;
    if (buscaSequencial(arr, 5, 3) == 2) testesPassados++;
    cout << "Teste 2: O resultado esperado é -1 e o valor retornado foi " << buscaSequencial(arr, 5, 6) << endl;
    if (buscaSequencial(arr, 5, 6) == -1) testesPassados++;
    cout << "Teste 3: O resultado esperado é 0 e o valor retornado foi " << buscaSequencial(arr, 5, 1) << endl;
    if (buscaSequencial(arr, 5, 1) == 0) testesPassados++;
    cout << "Teste 4: O resultado esperado é 4 e o valor retornado foi " << buscaSequencial(arr, 5, 5) << endl;
    if (buscaSequencial(arr, 5, 5) == 4) testesPassados++;
    cout << "Teste 5: O resultado esperado é -1 e o valor retornado foi " << buscaSequencial(arr, 5, -2) << endl;
    if (buscaSequencial(arr, 5, -2) == -1) testesPassados++;
    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}