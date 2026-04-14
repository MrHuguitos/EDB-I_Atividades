#include <iostream>
using namespace std;

void swap(int arr[], int indexMenor, int indexMaior) {
    int temp = arr[indexMaior];

    arr[indexMaior] = arr[indexMenor];
    arr[indexMenor] = temp;
}

void selectionSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++){
        int indexMenor = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[indexMenor]) {
                indexMenor = j;
            }
        }
        
        swap(arr, indexMenor, i);
    }
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
    
    selectionSort(arr1, 6);
    selectionSort(arr2, 6);
    selectionSort(arr3, 7);
    selectionSort(arr4, 5);
    selectionSort(arr5, 7);

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