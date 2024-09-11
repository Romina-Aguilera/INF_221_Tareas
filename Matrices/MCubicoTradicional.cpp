#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "chrono"

using namespace std;

/*
MultiplicarMatrices

Parametros:
- vector<vector<int>> matriz_A = Matriz 1
- vector<vector<int>> matriz_B = Matriz 2

Retorno:
- vector<vector<int>> matriz_Resultante = Matriz obtenida de la multiplicación de la matriz A con la matriz B

Funcionamiento:
- Se compara el tamaño de las matrices, si las columas de la matriz A son distintas a las filas de la columna B, no se puede realizar la multiplicación
En caso que coincidan se realiza la multiplicación de las matrices
-Se genera una matriz resultante, la cual guardará los resultados obtenidos de A*B

-Para obtener estos elementos, multiplicaremos los elementos de la fila I de la matriz A por los elementos de la columna j de la matriz B y sumaremos los elementos

Complejidad: O(n^3)
*/
vector<vector<int>> MultiplicarMatrices(const vector<vector<int>>& Matriz_A, const vector<vector<int>>& Matriz_B){
    int filas_MA = Matriz_A.size();
    int columnas_MA = Matriz_A[0].size();

    int filas_MB = Matriz_B.size();
    int columnas_MB = Matriz_B[0].size();

    if(columnas_MA != filas_MB){
        std::cout << "Los tamaños de las matrices no coincide" << std::endl;
    }

    vector<vector<int>> Matriz_Resultante(filas_MA, vector<int>(columnas_MB, 0));

    for (int i = 0; i < filas_MA; i++){
        for(int j = 0; j < columnas_MB; j++){
            for (int k = 0; k < columnas_MA; k++){
                Matriz_Resultante[i][j] += Matriz_A[i][k] * Matriz_B[k][j];
            }
        }
    }
    return Matriz_Resultante;
}


/*
leer_y_llenar_M1 y leer_y_llenar_M2

Parametros:
No tiene

Retorno:
- vector<vector<int>> matriz = Matriz extraida del archivo txt

Funcionamiento:
- La función se encarga de leer el archivo txt y almacenar los elementos obtenidos en la matriz
*/
vector<vector<int>> leer_y_llenar_M1(){
    ifstream file("Matriz1.txt");

    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }
    string line;
    getline(file, line);
    int n = stoi(line);

    vector<vector<int>> matriz(n, vector<int>(n));

    int i = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        int num;
        int j = 0;
        while (iss >> num) {
            matriz[i][j++] = num;
        }
        i++;
    }
    
    file.close();
    return matriz;
}

vector<vector<int>> leer_y_llenar_M2(){
    ifstream file("Matriz2.txt");

    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }
    string line;
    getline(file, line);
    int n = stoi(line);

    vector<vector<int>> matriz(n, vector<int>(n));

    int i = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        int num;
        int j = 0;
        while (iss >> num) {
            matriz[i][j++] = num;
        }
        i++;
    }
    
    file.close();
    return matriz;
}

/*
ImprimirMatriz

Parametros:
vector<vector<int>> matriz = Matriz que desea visualizarse impresa

Retorno:
No retorna nada

Funcionamiento:
- La función se encarga de leer la matriz e imprimir cada elemento por consola
*/
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elem : fila) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> A;
    A = leer_y_llenar_M1();
    //imprimirMatriz(A);

    //cout << "a" << endl;

    vector<vector<int>> B;
    B = leer_y_llenar_M2 ();
    //imprimirMatriz(B);

    auto inicio = chrono::high_resolution_clock::now();
    vector<vector<int>> C =MultiplicarMatrices(A, B);
    auto final = chrono::high_resolution_clock::now();

    auto total = chrono::duration_cast<chrono::microseconds>(final - inicio).count();

    //cout << "Matriz resultante C es:" << endl;
    //imprimirMatriz(C);

    cout << "Se ha finalizado el algoritmo tradicional" << endl;
    cout << "microsegundos" <<total << endl;

    return 0;
}