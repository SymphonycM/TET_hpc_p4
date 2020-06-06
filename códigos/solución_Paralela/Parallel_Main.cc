#include <iostream>
#include <fstream>
#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>
using namespace std;
int main(int argc, char *argv[]){
    
    MPI_Init(&argc, &argv);
    int myRank, nRanks;

    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
    MPI_Comm_size(MPI_COMM_WORLD, &nRanks);

    
    double t0 = omp_get_wtime();
    ifstream infile(argv[1]);
    std::string line="";
    int length=0;
    while (infile >> line){
        length=line.length();
    }
    const int stepsPerProcess= double((length-1))/double(nRanks);
    const int iStart=int(stepsPerProcess*myRank);
    const int iEnd = int(stepsPerProcess*(myRank + 1));  
        char t[length];
        strcpy(t, line.c_str());
        for(int k=iStart;k<iEnd;k++){
            if(t[k]=='T'){
                t[k]='U';}
        }

    double t1 = omp_get_wtime();
    
        for(int v=iStart;v<iEnd;v++){
            cout << t[v];
        }
            cout << endl;
    
    cout << "Time: " << t1-t0 << endl;


    
    MPI_Finalize();
}