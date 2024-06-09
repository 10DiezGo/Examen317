import multiprocessing

PROCESSES_COUNT = 4  # Número de procesos en el pool

series = []  # Lista para almacenar los vectores generados
M, N = 0, 0  # Variables para el número de vectores y términos

def generate_series(args):
    i, = args
    print(f"Proceso {i}: Vector {i}: ", end="")
    series[i] = [2 * (j + 1) for j in range(N)]
    print(" ".join(map(str, series[i])))

def main():
    global series, M, N
    
    M = int(input("Ingrese el número de vectores: "))
    N = int(input("Ingrese el número de términos: "))
    
    series = [[] for _ in range(M)]
    
    with multiprocessing.Pool(processes=PROCESSES_COUNT) as pool:
        pool.map(generate_series, range(M))

if __name__ == "__main__":
    main()