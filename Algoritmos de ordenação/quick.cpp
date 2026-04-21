#include <iostream>
#include <algorithm>
using namespace std;

int mediana(int array[], int a, int b, int c) {
    if ((array[a] <= array[b] && array[b] <= array[c]) || (array[c] <= array[b] && array[b] <= array[a])) return b;
    if ((array[b] <= array[a] && array[a] <= array[c]) || (array[c] <= array[a] && array[a] <= array[b])) return a;
    return c;
}

int particionar(int array[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    int pivo = mediana(array, inicio, meio, fim);

    swap(array[pivo], array[fim]);

    int i = inicio;
    
    for (int j = inicio; j < fim; j++) {
        if (array[j] >= array[fim]) {
            swap(array[j], array[i]);
            i++;
        }
    }
    /* Se a ordem for crescente, usar o código abaixo:
    for (int j = inicio; j < fim; j++) {
        if (array[j] <= array[fim]) {
            swap(array[j], array[i]);
            i++;
        }
    }
    */
    swap(array[i], array[fim]);

    return i;
}

void quickSort(int array[], int esquerda, int direita) {
    if (esquerda >= direita) return;

    int p = particionar(array, esquerda, direita);

    quickSort(array, esquerda, p - 1);
    quickSort(array, p + 1, direita);
}

void imprimirArray(int arr[], int tamanho) {
    cout << "[";

    for (int i = 0; i < tamanho; i++) {
        cout << arr[i];
        if (i < tamanho - 1) cout << ", ";
    }

    cout << "]" << endl;
}

int main() {
    int arr1[] = {3, 1, 2, 5, 4, 7}; 
    int arr2[] = {5, 4, 7, 8, 9, 1}; 
    int arr3[] = {0, 1, 0, 0, 1, 1, 1}; 
    int arr4[] = {5, 4, 3, 2, 1};
    int arr5[] = {7, 8, 9, 15, 1, 80, -8}; 
    
    quickSort(arr1, 0, 6 - 1);
    quickSort(arr2, 0, 6 - 1);
    quickSort(arr3, 0, 7 - 1);
    quickSort(arr4, 0, 5 - 1);
    quickSort(arr5, 0, 7 - 1);

    cout << "Teste 1: O resultado esperado é [1, 2, 3, 4, 5, 7] e o valor retornado foi ";
    imprimirArray(arr1, 6); 
    
    cout << "Teste 2: O resultado esperado é [1, 4, 5, 7, 8, 9] e o valor retornado foi ";
    imprimirArray(arr2, 6);
    
    cout << "Teste 3: O resultado esperado é [0, 0, 0, 1, 1, 1, 1] e o valor retornado foi ";
    imprimirArray(arr3, 7);
     
    cout << "Teste 4: O resultado esperado é [1, 2, 3, 4, 5] e o valor retornado foi ";
    imprimirArray(arr4, 5);
    
    cout << "Teste 5: O resultado esperado é [-8, 1, 7, 8, 9, 15, 80] e o valor retornado foi ";
    imprimirArray(arr5, 7);

    return 0;
}