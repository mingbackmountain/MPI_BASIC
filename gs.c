#include<stdio.h>
#include<mpi.h>

#define MAXPROCS 10


int main(int argc, char *argv[]) {
    int i,myid,numprocs;
    int ids[MAXPROCS];
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Gather(&myid,1,MPI_INT,ids,1,MPI_INT,0,MPI_COMM_WORLD);
    if(myid == 0) {
        for(i=0;i<numprocs;i++) {
            printf("%d\n",ids[i]);
        }
    }
    MPI_Finalize();
    return 0;
}