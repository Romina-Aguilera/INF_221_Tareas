#include <iostream>
#include <vector>

int particion (std::vector<int>& vect, int menor, int mayor){
    int pivote = vect[mayor];
    int i = menor -1;
    for (int j = menor; j < mayor; j++){
        if(vect[j] <= pivote){
            i++;
            std::swap(vect[i], vect[j]);
        }
    }
    std::swap(vect[i+1], vect[mayor]);
    return i+1;
}

void QuickSort(std::vector<int>& vect, int menor, int mayor){
    if(menor < mayor){
        int pivote_indice = particion(vect, menor, mayor);
        QuickSort(vect, menor, pivote_indice - 1);
        QuickSort(vect, pivote_indice + 1, mayor);
    }

}

int main() {
    std::vector<int> vect = {10, 7, 8, 9, 1, 5};
    int tam_vect = vect.size();

    QuickSort(vect, 0, tam_vect - 1);

    return 0;
}