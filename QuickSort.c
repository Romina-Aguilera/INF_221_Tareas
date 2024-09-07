#include "stdio.h"

int particion (int arreglo[], int menor, int mayor){
    int pivote = arreglo[mayor];
    int i = menor -1;
    for (int j = menor; j < mayor; j++){
        if(arreglo[j] <= pivote){
            i++;
            int temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
        }
    }
    int temp = arreglo[i + 1];
    arreglo[i+ 1] = arreglo[mayor];
    arreglo[mayor] = temp;
    return i+1;
}

void QuickSort(int arreglo[], int menor, int mayor){
    if(menor < mayor){
        int pivote_indice = particion(arreglo, menor, mayor);
        QuickSort(arreglo, menor, pivote_indice - 1);
        QuickSort(arreglo, pivote_indice + 1, mayor);
    }

}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arreglo[] = {10, 7, 8, 9, 1, 5};
    int tam_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);
    QuickSort(arreglo, 0, tam_arreglo - 1);
    printf("Array Ordenado: \n");
    printArray(arreglo, tam_arreglo);

    return 0;
}