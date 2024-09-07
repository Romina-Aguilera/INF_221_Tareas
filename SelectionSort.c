#include "stdio.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SelectionSort(int arreglo [], int tam_arreglo){

    for (int i = 0; i < tam_arreglo; i++){
        int indice_min = i;

        for(int j = i+1; j < tam_arreglo; j++){
            if(arreglo[j] < arreglo[indice_min]){
                indice_min = j;
            }

        } if (indice_min != i){
            int temp = arreglo[i];
            arreglo[i] = arreglo[indice_min];
            arreglo[indice_min] = temp;
        }
    }

}

int main() {
    int arreglo[] = {5,3,8,4,2};
    int tam_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);
    printArray(arreglo, tam_arreglo);
    SelectionSort(arreglo, tam_arreglo);
    printf("Array Ordenado: \n");
    printArray(arreglo, tam_arreglo);

    return 0;
}