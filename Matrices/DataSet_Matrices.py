import random

def generar_matriz(tamaño, valor_min, valor_max):
    return [[random.randint(valor_min, valor_max) for _ in range(tamaño)] for _ in range(tamaño)]

def escribir_matrices_en_archivo(matriz, archivo, tamaño):
    with open(archivo, 'w') as f:
        f.write(str(tamaño) + "\n")
        for fila in matriz:
            f.write(' '.join(map(str, fila)) + '\n')

# Configuración
tamaño_matriz1 = 512
valor_min1 = 1
valor_max1 = 512
nombre_archivo1 = "../Tarea_1/Matrices/output/Matriz1.txt"

tamaño_matriz2 = 512
valor_min2 = 1
valor_max2 = 512
nombre_archivo2 = "../Tarea_1/Matrices/output/Matriz2.txt"

matriz1 = generar_matriz(tamaño_matriz1, valor_min1, valor_max1)
matriz2 = generar_matriz(tamaño_matriz2, valor_min2, valor_max2)

escribir_matrices_en_archivo(matriz1, nombre_archivo1, tamaño_matriz1)
escribir_matrices_en_archivo(matriz2, nombre_archivo2, tamaño_matriz2)

