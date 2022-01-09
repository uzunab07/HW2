#include        <stdio.h>
#include        <mpi.h>

int main(int argc, char *argv[])
{
  int rank,numpro;

  /* Initialize MPI */
  MPI_Init(&argc, &argv);
  
  /* Find out my rank in the global communicator MPI_COMM_WORLD*/
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &numpro);

  if (rank==0){
    double hi =45;
    MPI_Send(&hi,1,MPI_DOUBLE,1,0,MPI_COMM_WORLD);
    printf("ProdID %d sent %lf to ProcID 1",rank,hi );

  }else{
    double msg;
    MPI_Status status;
    MPI_Recv(&msg,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);
     printf("ProdID %d received %lf from ProcID 0",rank,msg);
  }
  /* Exit and finalize MPI */
  MPI_Finalize();

}/* End Main */
