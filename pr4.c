#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int rank, size;
    int value, result;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    value = rank + 1;   // each process has a simple value

    // SUM
    MPI_Reduce(&value, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(rank == 0) printf("SUM using Reduce = %d\n", result);

    MPI_Allreduce(&value, &result, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    printf("Process %d: SUM using Allreduce = %d\n", rank, result);

    // MAX
    MPI_Reduce(&value, &result, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    if(rank == 0) printf("MAX using Reduce = %d\n", result);

    // MIN
    MPI_Reduce(&value, &result, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    if(rank == 0) printf("MIN using Reduce = %d\n", result);

    // PRODUCT
    MPI_Reduce(&value, &result, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    if(rank == 0) printf("PRODUCT using Reduce = %d\n", result);

    MPI_Finalize();
    return 0;
}
mpicc reduce_allreduce.c -o red
mpirun -np 4 ./red
