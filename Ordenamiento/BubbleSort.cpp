#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "chrono"
using namespace std;

vector<int> Llenar_Vector(vector<int> elementos){
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
    vect = Llenar_Vector(vect);
    int tam_vect = vect.size();

    auto inicio = chrono::high_resolution_clock::now();
    BubbleSort(vect, tam_vect);
    auto final = chrono::high_resolution_clock::now();

    auto total = chrono::duration_cast<chrono::microseconds>(final - inicio).count();

    //Imprimir_vector(vect, tam_vect);
    cout << "Se ha resuelto Bubble sort con exito!" <<endl;
    cout << "microsegundos" <<total << endl;


    return 0;
}