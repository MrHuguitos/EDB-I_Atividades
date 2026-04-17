#include <iostream>
using namespace std;

/* 
int buscaBinaria(int arr[], int inicio, int fim, int alvo) {
    if (inicio > fim) return -1;

    int meio = (inicio + fim) / 2;

    if (arr[meio] == alvo) return meio;
    return (arr[meio] > alvo) ? buscaBinaria(arr, inicio, meio - 1, alvo) : buscaBinaria(arr, meio + 1, fim, alvo);
}

int busca(int arr[], int tamanho, int alvo) {
    return buscaBinaria(arr, 0, tamanho -1, alvo);
}
*/

int buscaBinaria(int arr[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (fim >= inicio) {
        int meio = (inicio + fim) / 2;

        if (arr[meio] == alvo) return meio;
        (arr[meio] > alvo) ? fim = meio - 1 : inicio = meio + 1;
    }

    return -1;
}

int main() {
    int testesPassados = 0;
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Teste 1: O resultado esperado é 2 e o valor retornado foi " << buscaBinaria(arr, 5, 3) << endl;
    if (buscaBinaria(arr, 5, 3) == 2) testesPassados++;
    cout << "Teste 2: O resultado esperado é -1 e o valor retornado foi " << buscaBinaria(arr, 5, 6) << endl;
    if (buscaBinaria(arr, 5, 6) == -1) testesPassados++;
    cout << "Teste 3: O resultado esperado é 0 e o valor retornado foi " << buscaBinaria(arr, 5, 1) << endl;
    if (buscaBinaria(arr, 5, 1) == 0) testesPassados++;
    cout << "Teste 4: O resultado esperado é 4 e o valor retornado foi " << buscaBinaria(arr, 5, 5) << endl;
    if (buscaBinaria(arr, 5, 5) == 4) testesPassados++;
    cout << "Teste 5: O resultado esperado é -1 e o valor retornado foi " << buscaBinaria(arr, 5, -2) << endl;
    if (buscaBinaria(arr, 5, -2) == -1) testesPassados++;
    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}