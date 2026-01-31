#include <iostream>
#include <omp.h>

int main() {
  #pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int n   = omp_get_num_threads();
    #pragma omp critical
    std::cout << "Hola desde hilo " << tid << " de " << n << "\n";
  }
  return 0;
}
