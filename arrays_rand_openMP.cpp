#include <iostream>
#include <omp.h>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";

    float a[N], b[N], c[N];
    int i;

    // Inicializar semilla para números aleatorios
    srand(time(NULL));

    // Llenar arreglos con valores aleatorios entre 0 y 100
    for (i = 0; i < N; i++)
    {
        a[i] = static_cast<float>(rand() % 101);  // 0 a 100
        b[i] = static_cast<float>(rand() % 101);  // 0 a 100
    }

    int pedazos = chunk;

#ifdef _OPENMP
    #pragma omp parallel for \
        shared(a, b, c, pedazos) private(i) \
        schedule(static, pedazos)
#endif

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}
