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
    ifstream MyFile("Ordenados.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}

/*
particion

Parametros:
- std::vector<int>& vect: Vector que se ordenará
- int menor: Índice inicial del segmento del vector que se va a ordenar.
- int mayor: Índice final del segmento del vector que se va a ordenar.

Retorno:
- int: índice del pivote después de la partición.

Funcionamiento:
- Elige un pivote y coloca su valor al final del segmento del vector.
- Reordena los elementos del segmento del vector para que los valores menores o iguales al pivote estén a la izquierda del pivote y los mayores estén a la derecha.
- Intercambia el pivote con el primer valor mayor a él en el segmento del vector.
- Devuelve el índice donde el pivote quedó después de la partición.

*/
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

/*
QuickSort

Parametros:
- std::vector<int>& vect: Vector que será ordenado
- int menor: Índice inicial del segmento del vector que se va a ordenar.
- int mayor: Índice final del segmento del vector que se va a ordenar.

Retorno:
- No tiene retorno.

Funcionamiento:
- Verifica si el segmento del vector tiene al menos dos elementos.
- Llama a la función particion para dividir el segmento del vector en dos partes en base al pivote.
- Llama recursivamente a QuickSort para ordenar las dos partes del segmento del vector (izquierda y derecha del pivote).

Complejidad:
- Peor caso: O(n^2)
- Promedio: O(n log n)
- Mejor Caso: O(n log n)
*/
void QuickSort(std::vector<int>& vect, int menor, int mayor){
    if(menor < mayor){
        int pivote_indice = particion(vect, menor, mayor);
        QuickSort(vect, menor, pivote_indice - 1);
        QuickSort(vect, pivote_indice + 1, mayor);
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