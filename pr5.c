#include <stdio.h>
#include <omp.h>

int main() {
    int N = 10;
    int sum = 0;
    int i;

    #pragma omp parallel for private(i) reduction(+:sum)
    for(i = 1; i <= N; i++) {
        sum += i;
    }

    printf("Sum of first %d integers = %d\n", N, sum);
    return 0;
}
gcc pr5.c -fopenmp -o sum_n
./sum_n
