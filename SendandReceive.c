#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    int rank, size;
    int msgtag;
    int x;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    msgtag = 1234;
    if (rank == 0)
    {
        x = 5768;
        MPI_Send(&x, 1, MPI_INT, 1, msgtag, MPI_COMM_WORLD);
        printf("processor %d sent %d\n", rank, x);
    }
    if (rank == 1)
    {
        MPI_Recv(&x, 1, MPI_INT, 0, msgtag, MPI_COMM_WORLD, &status);
        printf("processor %d got %d\n", rank, x);
    }
    MPI_Finalize();
}