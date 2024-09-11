#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "fstream"
#include "chrono"

using namespace std;

vector<int> LlenarVector(vector<int> elementos){
    ifstream MyFile("Desordenados.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}

void Imprimir_vector (vector<int> vect, int tam_vector){
    for (int i = 0; i < tam_vector; i++){
        cout << vect[i] << endl;
    }
}

int main(){
    vector<int> vect;
    vect = LlenarVector(vect);

    //int tam_vect = vect.size();
    auto inicio = chrono::high_resolution_clock::now();
    sort(vect.begin(), vect.end());
    auto final = chrono::high_resolution_clock::now();

    auto total = chrono::duration_cast<chrono::microseconds>(final - inicio).count();

    //Imprimir_vector(vect, tam_vect);

    cout << "Se ha resuelto Sort con exito!" <<endl;
    cout << "microsegundos" <<total << endl;

    return 0;
}