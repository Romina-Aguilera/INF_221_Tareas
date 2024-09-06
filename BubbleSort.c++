#include "stdio.h"
#include "iostream"

void BubbleSort(int arreglo[], int tam_arreglo ){
    for (int i = 0; i < tam_arreglo - 1; i++)
        for(int j = 0; j < tam_arreglo - i - 1; j++){
            if (arreglo[j] <= arreglo[j+1]){
                int temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }

}

int main() {
    int arreglo[] = {5,3,8,4,2};
    int tam = sizeof(arreglo) / sizeof(arreglo[0]);
    printf("Arreglo original \n");
    for (int i = 0; i < tam; i++){
        printf("%d", arreglo[i]);
    }
    BubbleSort(arreglo, tam);
    printf("Arreglo final \n");
    for (int i = 0; i < tam; i++){
        printf("%d", arreglo[i]);
    }
    return 0;
}