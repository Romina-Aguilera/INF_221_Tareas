import random
import numpy as np

#Función que genera numeros semiordenados en base a los parametros definidos al inicio
def SemiOrdenados():
    #Cambiar estos valores si se quieren probar otros casos
    elementos = 100
    valor_minimo = 1
    valor_maximo = 100

    ordenados = sorted([random.randint(valor_minimo, valor_maximo) for _ in range(elementos // 2)])
    Desordenados = random.sample(range(valor_minimo, valor_maximo + 1), elementos // 2)
    SemiOrdenados = ordenados + Desordenados

    with open("../Tarea_1/Ordenamiento/output/SemiOrdenados.txt", "w") as arch:
        for num in SemiOrdenados:
            arch.write(str(num) + "\n")

#Función que genera numeros ordenados en base a los parametros definidos al inicio
def Ordenados():
    elementos = 100 #Cambiar este valor si se quiere probsr otro caso
    with open("../Tarea_1/Ordenamiento/output/Ordenados.txt", "w") as arch:
        for num in range(elementos):
            arch.write(str(num)+ '\n')

#Función que genera numeros desordenados en base a los parametros definidos al inicio
def Desordenados():
    elementos = 100 #Cambiar este valor si se quiere probsr otro caso
    with open("../Tarea_1/Ordenamiento/output/Desordenados.txt", "w") as arch:
        for _ in range(elementos):
            num = random.randint(1, elementos)
            arch.write(str(num)+ '\n')

SemiOrdenados()
Ordenados()
Desordenados()
