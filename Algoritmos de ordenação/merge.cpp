#include <iostream>
#include <algorithm>
using namespace std;

void merge(int array[], int inicio, int meio, int fim) {
    int tamanho = fim - inicio + 1;
    int* temp = new int[tamanho];  
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {
        // Se quiséssemos crescente, seria array[i] <= array[j]
        if (array[i] >= array[j]) { 
            temp[k] = array[i];
            i++;
        } else {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= fim) {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        array[i] = temp[k];
    }

    delete[] temp;
}

void mergeSort(int array[], int esquerda, int direita) {
    if (esquerda >= direita) return;

    int meio = (esquerda + direita) / 2;

    mergeSort(array, esquerda, meio);
    mergeSort(array, meio + 1, direita);
    merge(array, esquerda, meio, direita);
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
    
    mergeSort(arr1, 0, 6 - 1);
    mergeSort(arr2, 0, 6 - 1);
    mergeSort(arr3, 0, 7 - 1);
    mergeSort(arr4, 0, 5 - 1);
    mergeSort(arr5, 0, 7 - 1);

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