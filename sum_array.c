#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]) {
    int rank,size;
    int A[4][4];
    int B[4];
    MPI_Status status;
    int i,j;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(rank == 0) {
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                A[i][j] = i;
            }
        }
        for(i=1;i<=4;i++){
            MPI_Send(&A[i-1][0],4,MPI_INT,i,12345,MPI_COMM_WORLD);
        }
    } else {
        MPI_Recv(&B,4,MPI_INT,0,12345,MPI_COMM_WORLD,&status);
        printf("Rank %d: ",rank);
        for(i = 0;i<4;i++){
            printf("%d",B[i]);
        }
        printf("\n");

    }
    MPI_Finalize();
}