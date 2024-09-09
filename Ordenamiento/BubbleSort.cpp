#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& vect, int tam_vect){
    for (int i = 0; i < tam_vect - 1; i++){

        for(int j = 0; j < tam_vect - i -1; j++){

            if (vect[j+1] < vect [j]){
                int temp = vect[j];
                vect[j] = vect[j+1];
                vect[j+1] = temp;
            }
        }
    }
}

int main() {
    std::vector<int> vect = {5,3,8,4,2};
    int tam_vect = vect.size();

    BubbleSort(vect, tam_vect);

    return 0;
}