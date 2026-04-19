#include <iostream>
using namespace std;

int posicaoInsercao(int array[], int esquerda, int direita, int alvo) {
    if (alvo < array[esquerda]) return esquerda;
    if (alvo > array[direita]) return direita + 1;

    int meio = (esquerda + direita) / 2;

    if (meio == esquerda || meio == direita){
        return (array[meio] > alvo) ? meio : meio + 1;
    }

    return (array[meio] > alvo) ? posicaoInsercao(array, esquerda, meio - 1, alvo) : posicaoInsercao(array, meio + 1, direita, alvo);
}

int main() {
    int testesPassados = 0;
    int array1[] = {1, 3, 5, 7};
    int tam = sizeof(array1) / sizeof(int);

    cout << "Teste 1: O resultado esperado é 0 e o valor retornado foi " << posicaoInsercao(array1, 0, tam-1, 0) << endl;
    if (posicaoInsercao(array1, 0, tam-1, 0) == 0) testesPassados++;
    cout << "Teste 2: O resultado esperado é 1 e o valor retornado foi " << posicaoInsercao(array1, 0, tam-1, 2) << endl;
    if (posicaoInsercao(array1, 0, tam-1, 2) == 1) testesPassados++;
    cout << "Teste 3: O resultado esperado é 2 e o valor retornado foi " << posicaoInsercao(array1, 0, tam-1, 4) << endl;
    if (posicaoInsercao(array1, 0, tam-1, 4) == 2) testesPassados++;
    cout << "Teste 4: O resultado esperado é 3 e o valor retornado foi " << posicaoInsercao(array1, 0, tam-1, 6) << endl;
    if (posicaoInsercao(array1, 0, tam-1, 6) == 3) testesPassados++;
    cout << "Teste 5: O resultado esperado é 4 e o valor retornado foi " << posicaoInsercao(array1, 0, tam-1, 8) << endl;
    if (posicaoInsercao(array1, 0, tam-1, 8) == 4) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;
}