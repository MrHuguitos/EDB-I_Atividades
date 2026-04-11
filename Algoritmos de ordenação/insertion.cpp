#include <iostream>
using namespace std;

void swap(int arr[], int indexMenor, int indexMaior) {
    int temp = arr[indexMaior];

    arr[indexMaior] = arr[indexMenor];
    arr[indexMenor] = temp;
}

void insertionSort(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++){
        int j = i - 1;

        while (j >= 0) {
            if (arr[j + 1] < arr[j]) {
                swap(arr, j, j + 1);
                j--;
            }
            else break;
        }
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
    
    insertionSort(arr1, 6);
    insertionSort(arr2, 6);
    insertionSort(arr3, 7);
    insertionSort(arr4, 5);
    insertionSort(arr5, 7);

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