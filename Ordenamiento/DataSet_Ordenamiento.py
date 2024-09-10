import random
import numpy as np

def SemiOrdenados():
    elementos = 1000
    valor_minimo = 1
    valor_maximo = 1000

    ordenados = sorted([random.randint(valor_minimo, valor_maximo) for _ in range(elementos // 2)])
    Desordenados = random.sample(range(valor_minimo, valor_maximo + 1), elementos // 2)
    SemiOrdenados = ordenados + Desordenados

    with open("../Tarea_1/Ordenamiento/output/SemiOrdenados.txt", "w") as arch:
        for num in SemiOrdenados:
            arch.write(str(num) + "\n")

def Ordenados():
    elementos = 1000
    with open("../Tarea_1/Ordenamiento/output/Ordenados.txt", "w") as arch:
        for num in range(100):
            arch.write(str(num)+ '\n')

def Desordenados():
    elementos = 1000
    with open("../Tarea_1/Ordenamiento/output/Desordenados.txt", "w") as arch:
        for _ in range(elementos):
            num = random.randint(1, elementos)
            arch.write(str(num)+ '\n')

SemiOrdenados()
Ordenados()
Desordenados()
