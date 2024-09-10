#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "chrono"
using namespace std;

vector<int> pobladorVector(vector<int> elementos){
    ifstream MyFile("Desordenados.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}

void BubbleSort(vector<int>& vect, int tam_vect){
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

void Imprimir_vector (vector<int> vect, int tam_vector){
    for (int i = 0; i < tam_vector; i++){
        cout << vect[i] << endl;
    }
}
int main() {
    vector<int> vect;
    vect = pobladorVector(vect);
    int tam_vect = vect.size();

    BubbleSort(vect, tam_vect);

    Imprimir_vector(vect, tam_vect);

    return 0;
}