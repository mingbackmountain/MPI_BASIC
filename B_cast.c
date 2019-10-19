#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
    int i,myid,numprocs;
    int buffer[4];

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    if(myid == 0) {
        for(i=0;i<4;i++){
            buffer[i] = i;
        }
        MPI_Bcast(buffer,4,MPI_INT,0,MPI_COMM_WORLD);
        for(i=0;i<4;i++){
            printf("%d",buffer[i]);
            printf("\n");
        }
        MPI_Finalize();
    }
}