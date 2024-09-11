#include "iostream"
#include "string"
#include "vector"
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
vector<int> Llenar_Vector(vector<int> elementos){
    ifstream MyFile("Desordenados.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}

/*
BubbleSort

Parametros:
- vector<int> elementos = vector a ordenar
- int tam_vector = tamaño del vector a ordenar

Retorno:
no tiene

Funcionamiento:
- La función se encarga de comprobar si A[j] > A[j+1], en caso de cumplirse esto, se intercambian los elementos.
Se repite este procedimiento hasta que el arreglo esté ordenado totalmente

Complejidad:
- Peor Caso: O(n^2)
- Caso Promedio: O(n^2)
- Mejor Caso: O(n)
*/
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

/*
Imprimir_vector

Parametros:
vector<int> vector = vector que desea visualizarse impreso
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