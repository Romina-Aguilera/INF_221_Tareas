#include "iostream"
#include "string"
#include "vector"
#include "climits"
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
    ifstream MyFile("SemiOrdenados.txt");
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

/*
Merge

Parámetros:
- std::vector<int>& vect: Vector que se desea ordenar
- int izq: Índice izquierdo del subarreglo, este es el inicio de la porción que se va a fusionar
- int mitad: Índice medio del subarreglo que separa las dos mitades a fusionar.
- int der: Índice derecho del subarreglo, este es el final de la porción que se va a fusionar.

Retorno:
- No tiene retorno

Funcionamiento:
- La función se encarga de fusionar dos subarreglos ordenados, que están definidos entre los índices `izq` a `mitad` y `mitad + 1` a `der`.
- Primero, se copian los valores de ambos subarreglos en dos vectores temporales: `IZQ` y `DER`.
- Se añaden "sentinelas" (INT_MAX) al final de ambos vectores para facilitar el proceso de fusión.
- Luego, se comparan los elementos de los dos subarreglos y se van colocando en su posición correcta en el vector original.

*/
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

/*
MergeSort

Parámetros:
- std::vector<int>& vect: Vector que se ordenará
- int izq: Índice izquierdo del subarreglo que se va a ordenar.
- int der: Índice derecho del subarreglo que se va a ordenar.

Retorno:
No tiene retorno

Funcionamiento:
- La función implementa el algoritmo recursivo MergeSort. Divide el vector en dos mitades recursivamente hasta que el subarreglo tenga un solo elemento.
- Después de dividir, se llama a la función `Merge` para fusionar las dos mitades ordenadas en el vector original.

Complejidad:
- Peor Caso: O(n log n)
- Caso Promedio: O(n log n)
- Mejor Caso:  O(n log n)
*/
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