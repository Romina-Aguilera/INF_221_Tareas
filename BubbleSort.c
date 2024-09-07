#include "stdio.h"
//#include "iostream"

void BubbleSort(int arreglo[], int tam_arreglo){
    for (int i = 0; i < tam_arreglo -1; i++){

        for(int j = 0; j < tam_arreglo - i -1; j++){

            if (arreglo[j+1] < arreglo [j]){
                int temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
    }
}

int main() {
    int arreglo[] = {5,3,8,4,2};
    int tam_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);

    BubbleSort(arreglo, tam_arreglo);

    return 0;
}