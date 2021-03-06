#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <mpi.h>

int main(int argc,char *argv[]){
    int i, myid, nproc;
    int *buf;
    int bufsize;
    
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&nproc);

    bufsize = 100 / nproc;
    assert(bufsize * nproc == 100);
    buf = (int *) malloc(bufsize * sizeof(int));
    for (int i=0; i < bufsize; i++)
      buf[i] = myid + i * nproc;

    MPI_File fp;

     /* Open an MPI I/O file for writing */

    /* Create the file view */
    MPI_Datatype filetype;
    MPI_Offset disp;
    disp = myid * sizeof(int);
    
    /* Write the data collectively*/

    /* Free the filetype */
    
    /* Close the file */

    MPI_Finalize();
}
