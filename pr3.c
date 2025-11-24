#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int rank, data;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0) {
        data = 100;
        printf("Root broadcasting %d\n", data);
    }

    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received %d\n", rank, data);

    MPI_Finalize();
    return 0;
}
mpicc broadcast.c -o bcast
mpirun -np 4 ./bcast
