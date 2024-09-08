#include "stdio.h"
#include "stdlib.h"
#include "limits.h"


void Merge(int arreglo[], int izq, int mitad, int der){
    int n_1 = mitad - izq +1;
    int n_2 = der - mitad;

    int *IZQ = (int *) malloc((n_1 + 1) * sizeof(int));
    int *DER = (int *) malloc((n_2 + 1) * sizeof(int));

    for (int i = 0; i < n_1; i++){
        IZQ[i] = arreglo[izq + i];
    }

    for (int j = 0; j < n_2; j++){
        DER[j] = arreglo[mitad + 1 + j];
    }

    IZQ[n_1] = INT_MAX;
    DER[n_2] = INT_MAX;

    int i = 0;
    int j = 0;

    for(int k = izq; k<= der; k++){
        if (IZQ[i] <= DER[j]){
            arreglo[k] = IZQ[i];
            i++;
        } else {
            arreglo[k] = DER[j];
            j++;
        }
    }
    free(IZQ);
    free(DER);
}

void MergeSort(int arreglo[], int izq, int der){

    if (izq < der){
        int mitad = (izq + der) / 2;

        MergeSort(arreglo, izq, mitad);
        MergeSort(arreglo, mitad + 1, der);
        Merge(arreglo, izq, mitad, der);
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    MergeSort(arr, 0, arr_size - 1);

    printf("\nArray ordenado:\n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}