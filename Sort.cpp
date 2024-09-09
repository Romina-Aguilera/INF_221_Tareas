#include "iostream"
#include "algorithm"

int main(){
    int arreglo[]= {5, 2, 8, 1, 9};
    int tam_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);

    std::sort(arreglo, arreglo + tam_arreglo);

    return 0;
}