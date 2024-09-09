#include <iostream>
#include <vector>

using namespace std;

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

void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elem : fila) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    vector<vector<int>> C =MultiplicarMatrices(A, B);
    cout << "Matriz resultante C es:" << endl;
    imprimirMatriz(C);

    return 0;
}