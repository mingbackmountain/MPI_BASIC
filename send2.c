#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    int x, y,np,me;
    int tag=42;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &me);

    if (me == 0)
    {
        x = 5768;
        printf("processor %d sending to process 1\n", me);
        MPI_Send(&x, 1, MPI_INT, 1,tag, MPI_COMM_WORLD);
        printf("processor %d receiving from process 1\n", me);
        MPI_Recv(&y, 1, MPI_INT, 1,tag, MPI_COMM_WORLD,&status);
    }
    else
    {
       MPI_Recv(&y, 1, MPI_INT, 0,tag, MPI_COMM_WORLD,&status);
       MPI_Send(&y, 1, MPI_INT, 0,tag, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}