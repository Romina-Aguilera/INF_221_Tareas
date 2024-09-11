#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "fstream"
#include "chrono"

using namespace std;

/*
Llenar_Vector

Parametros:
- vector<int> elementos = vector que se desea llenar de elementos

Retorno:
- vector<int> elementos = vector con elementos

Funcionamiento:
- La función se encarga de leer el archivo txt y almacenar los elementos en el vector
*/
vector<int> LlenarVector(vector<int> elementos){
    ifstream MyFile("Desordenados.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}

/*
Imprimir_vector

Parametros:
vector<int> matriz = vector que desea visualizarse impreso
int tam_vector = tamaño del vector

Retorno:
No retorna nada

Funcionamiento:
- La función se encarga de leer el vector e imprimir cada elemento por consola
*/
void Imprimir_vector (vector<int> vect, int tam_vector){
    for (int i = 0; i < tam_vector; i++){
        cout << vect[i] << endl;
    }
}

/*
Complejidad
- Peor Caso O(n log n)
- Caso Promedio O(n log n)
- Mejor Caso O(n)
*/
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