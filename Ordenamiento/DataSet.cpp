#include "iostream"
#include "fstream"
#include "cstdlib"
#include "ctime"

void Ordenados_100(){
    std :: ofstream arch("Ordenado_1.txt");

    if(!arch.is_open()){
        std::cerr << "error al abrir el archivo" << std :: endl;
    }

    for(int i = 1; i <= 100; i++){
        arch << i << std::endl;
    }

    arch.close();
}
void Desordenados_100(){
    srand(static_cast<unsigned int>(time(nullptr)));

    std:: ofstream arch("Desordenado_1.txt");
    if(!arch.is_open()){
        std::cerr << "error al abrir el archivo" << std :: endl;
    }

    for(int i = 0; i < 100; i++){
        int numero = rand() % 100 + 1;
        arch << numero << std:: endl;
    }

    arch.close();

}

void Ordenados_1000(){
    std :: ofstream arch("Ordenado_2.txt");

    if(!arch.is_open()){
        std::cerr << "error al abrir el archivo" << std :: endl;
    }

    for(int i = 1; i <= 1000; i++){
        arch << i << std::endl;
    }

    arch.close();
}
void Desordenados_1000(){
    srand(static_cast<unsigned int>(time(nullptr)));

    std:: ofstream arch("Desordenado_2.txt");
    if(!arch.is_open()){
        std::cerr << "error al abrir el archivo" << std :: endl;
    }

    for(int i = 0; i < 1000; i++){
        int numero = rand() % 1000 + 1;
        arch << numero << std:: endl;
    }

    arch.close();

}

void Ordenados_10000(){
    std :: ofstream arch("Ordenado_3.txt");

    if(!arch.is_open()){
        std::cerr << "error al abrir el archivo" << std :: endl;
    }

    for(int i = 1; i <= 10000; i++){
        arch << i << std::endl;
    }

    arch.close();
}
void Desordenados_10000(){
    srand(static_cast<unsigned int>(time(nullptr)));

    std:: ofstream arch("Desordenado_3.txt");
    if(!arch.is_open()){
        std::cerr << "error al abrir el archivo" << std :: endl;
    }

    for(int i = 0; i < 10000; i++){
        int numero = rand() % 10000 + 1;
        arch << numero << std:: endl;
    }

    arch.close();

}

int main(){
    Ordenados_100();
    Desordenados_100();

    Ordenados_1000();
    Desordenados_1000();

    Ordenados_10000();
    Desordenados_10000();
    
    return 0;
}