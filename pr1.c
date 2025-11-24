#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {

    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0) {
        int number = 12345;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent %d\n", number);
    }
    else if(rank == 1) {
        int recv_num;
        MPI_Recv(&recv_num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received %d\n", recv_num);
    }

    MPI_Finalize();
    return 0;
}

mpicc p2p.c -o p2p
mpirun -np 2 ./p2p
