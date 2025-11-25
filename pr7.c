#include <stdio.h>
#include <omp.h>

int main() {
    long N = 1000000;
    double pi = 0.0;

    #pragma omp parallel for reduction(+:pi)
    for(long i = 0; i < N; i++){
        double x = (i + 0.5) / N;
        pi += 4.0 / (1 + x*x);
    }

    printf("Pi = %f\n", pi/N);
} 7th
