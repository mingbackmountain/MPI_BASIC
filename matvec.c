#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv[]) {
    int numprocs,rank,chunk_size,i,j;
    int A[800][800];
    int x[800];
    int y[800];
    int local_A[800][800];
    int local_y[800];
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    chunk_size = 800/numprocs;
    if(rank == 0) {
        for(i=0;i<800;i++) {
            x[i] = i;
            for(j=0;j<800;j++) {
                A[i][j] = i+j;
            }
        }
    }
    MPI_Bcast(x,800,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(A,800*chunk_size,MPI_INT,local_A,800*chunk_size,MPI_INT,0,MPI_COMM_WORLD);
    for(i=0;i<chunk_size;i++) {
        local_y[i] = 0;
        for(j=0;j<800;j++) {
            local_y[i] += local_A[i][j]*x[j];
        }
    }
    MPI_Gather(local_y,chunk_size,MPI_INT,y,chunk_size,MPI_INT,0,MPI_COMM_WORLD);
    if(rank == 0) {
        for(i=0;i<800;i++) {
            printf("%d\t",y[i]);
        }
    }
    MPI_Finalize();
    return 0;
}