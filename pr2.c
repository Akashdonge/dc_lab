#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int rank, size;
    int data[4] = {10, 20, 30, 40};
    int recv_value;
    int gathered[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Scatter(data, 1, MPI_INT,
                &recv_value, 1, MPI_INT,
                0, MPI_COMM_WORLD);

    printf("Process %d received %d\n", rank, recv_value);

    MPI_Gather(&recv_value, 1, MPI_INT,
               gathered, 1, MPI_INT,
               0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("Gathered: ");
        for(int i = 0; i < size; i++)
            printf("%d ", gathered[i]);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
mpicc scatter_gather.c -o sg
mpirun -np 4 ./sg
