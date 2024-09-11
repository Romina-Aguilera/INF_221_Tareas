#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "chrono"
using namespace std;

vector<int> Llenar_Vector(vector<int> elementos){
    ifstream MyFile("Ordenados.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}

int particion (std::vector<int>& vect, int menor, int mayor){
    int centro = menor + (mayor - menor) / 2;
    swap(vect[centro], vect[mayor]);

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

void Imprimir_vector (vector<int> vect, int tam_vector){
    for (int i = 0; i < tam_vector; i++){
        cout << vect[i] << endl;
    }
}

int main() {
    std::vector<int> vect;
    vect = Llenar_Vector(vect);
    int tam_vect = vect.size();
    //Imprimir_vector(vect, tam_vect);

    auto inicio = chrono::high_resolution_clock::now();
    QuickSort(vect, 0, tam_vect - 1);
    auto final = chrono::high_resolution_clock::now();

    auto total = chrono::duration_cast<chrono::microseconds>(final - inicio).count();
    //Imprimir_vector(vect, tam_vect);
    cout << "Se ha resuelto quickSort con exito!" <<endl;
    cout << "microsegundos" <<total << endl;

    return 0;
}