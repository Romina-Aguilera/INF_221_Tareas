#include "iostream"
#include "string"
#include "vector"
#include "climits"
#include "fstream"
#include "chrono"
using namespace std;

vector<int> Llenar_Vector(vector<int> elementos){
    ifstream MyFile("SemiOrdenados.txt");
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

void Merge(std::vector<int>& vect, int izq, int mitad, int der){
    int n_1 = mitad - izq +1;
    int n_2 = der - mitad;

    std::vector<int> IZQ(n_1 + 1);
    std::vector<int> DER(n_2 + 1);

    for (int i = 0; i < n_1; i++){
        IZQ[i] = vect[izq + i];
    }

    for (int j = 0; j < n_2; j++){
        DER[j] = vect[mitad + 1 + j];
    }

    IZQ[n_1] = INT_MAX;
    DER[n_2] = INT_MAX;

    int i = 0;
    int j = 0;

    for(int k = izq; k<= der; k++){
        if (IZQ[i] <= DER[j]){
            vect[k] = IZQ[i];
            i++;
        } else {
            vect[k] = DER[j];
            j++;
        }
    }
}

void MergeSort(std::vector<int>& vect, int izq, int der){

    if (izq < der){
        int mitad = (izq + der) / 2;

        MergeSort(vect, izq, mitad);
        MergeSort(vect, mitad + 1, der);
        Merge(vect, izq, mitad, der);
    }
}

int main(){
    std::vector<int> vect;
    vect = Llenar_Vector(vect);
    int tam_vect = vect.size();

    auto inicio = chrono::high_resolution_clock::now();
    MergeSort(vect, 0, tam_vect - 1);
    auto final = chrono::high_resolution_clock::now();
    //Imprimir_vector(vect, tam_vect);

    auto total = chrono::duration_cast<chrono::microseconds>(final - inicio).count();

    cout << "Se ha resuelto MergeSort con exito!" <<endl;
    cout << "microsegundos " <<total << endl;


    return 0;
}