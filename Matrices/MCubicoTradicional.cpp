#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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
    imprimirMatriz(A);

    cout << "a" << endl;

    vector<vector<int>> B;
    B = leer_y_llenar_M2 ();
    imprimirMatriz(B);

    vector<vector<int>> C =MultiplicarMatrices(A, B);
    cout << "Matriz resultante C es:" << endl;
    imprimirMatriz(C);

    return 0;
}