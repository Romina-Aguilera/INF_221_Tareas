#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Transponer_Matriz(const vector<vector<int>>& Matriz){
    int tam_fila = Matriz.size();
    int tam_columna = Matriz[0].size();

    vector<vector<int>> Matriz_Traspuesta(tam_columna, vector<int>(tam_fila, 0));

    for(int i = 0; i < tam_fila; i++){
        for(int j = 0; j < tam_columna; j++){
            Matriz_Traspuesta[j][i] = Matriz[i][j];
        }

    }
    return Matriz_Traspuesta;
}

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

void imprimirMatriz(const std::vector<std::vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
}

int main() {

    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> B = {
        {7, 8, 9},
        {9, 10, 1},
        {11, 12, 2}
    };

    std::vector<std::vector<int>> MB = Transponer_Matriz(B);
    cout << "Matriz resultante traspuesta es:" << endl;
    imprimirMatriz(MB);

    vector<vector<int>> C =MultiplicarMatrices(A, MB);
    cout << "Matriz resultante C es:" << endl;
    imprimirMatriz(C);

    return 0;
}
