#include <iostream>
using namespace std;

int acharPico(int array[], int esquerda, int direita) {
    if (esquerda == direita) return esquerda;
    if (direita == esquerda + 1) return (array[esquerda] > array[direita]) ? esquerda : direita;

    int meio = (esquerda + direita) / 2;
    
    if (array[meio] > array[meio - 1] && array[meio] > array[meio + 1]) return meio;
    if (array[meio] < array[meio + 1]) return acharPico(array, meio + 1, direita);

    return acharPico(array, esquerda, meio - 1);
}

int main() {
    int testesPassados = 0;

    int array1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 95, 85, 75, 65, 55, 45};
    int array2[] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95};
    int array3[] = {95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10};

    int tamanho1 = sizeof(array1) / sizeof(int);
    int tamanho2 = sizeof(array2) / sizeof(int);
    int tamanho3 = sizeof(array3) / sizeof(int);

    cout << "Teste 1: O resultado esperado é 9 e o valor retornado foi " << acharPico(array1, 0, tamanho1 - 1) << endl;
    if (acharPico(array1, 0, tamanho1 - 1) == 9) testesPassados++;
    cout << "Teste 2: O resultado esperado é 17 e o valor retornado foi " << acharPico(array2, 0, tamanho2 - 1) << endl;
    if (acharPico(array2, 0, tamanho2 - 1) == tamanho2 - 1) testesPassados++;
    cout << "Teste 3: O resultado esperado é 0 e o valor retornado foi " << acharPico(array3, 0, tamanho3 - 1) << endl;
    if (acharPico(array3, 0, tamanho3 - 1) == 0) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 3 testes." << endl;
}