#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "fstream"

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

void Imprimir_vector (vector<int> vect, int tam_vector){
    for (int i = 0; i < tam_vector; i++){
        cout << vect[i] << endl;
    }
}

int main(){
    vector<int> vect;
    vect = pobladorVector(vect);

    int tam_vect = vect.size();
    sort(vect.begin(), vect.end());

    Imprimir_vector(vect, tam_vect);

    return 0;
}