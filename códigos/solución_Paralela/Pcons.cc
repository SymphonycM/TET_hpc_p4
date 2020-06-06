#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <omp.h>
#include <mpi.h>
using namespace std;


int main(int argc, char *argv[]){
  double t0 = omp_get_wtime();

  ifstream infile("in2.txt");
    
  int number_of_lines = 0;
  int i=0;
  int j=0;
  string line="";
  int count=0;
  char ** S;
  while(infile >> line){
    if(number_of_lines==0){
      j=boost::lexical_cast<int>(line);
    }else{
      if(number_of_lines==1){
        i=boost::lexical_cast<int>(line);
        S = new char*[j];
        for(int k = 0; k < j; k++){
          S[k] = new char[i];
        }
      }else{
        strcpy(S[count], line.c_str());
        count++;
      }
    }
  number_of_lines++;
  }
  infile.close();
  cout << "Matriz S lista" << endl;


  MPI_Init(&argc, &argv);
  int rank, size, namelen;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(rank==0){

  char P[4][i+1];

  P[0][0]='A';
  P[1][0]='C';
  P[2][0]='G';
  P[3][0]='T';

   
  for(int col=0;col<i;col++){
    int countA=0;
    int countC=0;
    int countG=0;
    int countT=0;
    #pragma omp simd
    for(int row=0;row<j;row++){
      switch (S[row][col]){
      case 'A':
        countA++;
        break;
      case 'C':
        countC++;
        break;
      case 'G':
        countG++;
        break;
      case 'T':
        countT++;
        break;
      default:
        break;
      }
    }
    P[0][col+1]=boost::lexical_cast<char>(countA);
    P[1][col+1]=boost::lexical_cast<char>(countC);
    P[2][col+1]=boost::lexical_cast<char>(countG);
    P[3][col+1]=boost::lexical_cast<char>(countT);
    countA=0;
    countC=0;
    countG=0;
    countT=0;
  }
    
  cout << "Matriz P:" << endl;
  for(int row=0;row<4;row++){
    for(int col=0;col<i+1;col++){
      cout << P[row][col] << " ";
    }
    cout << endl;
  }
    cout << "Ejecutado en el proceso 0"     << endl;
}else{
  std::string consensus="";
  int comparing=0;
  
  for(int col=0;col<i;col++){
    int countA=0;
    int countC=0;
    int countG=0;
    int countT=0;
    for(int row=0;row<j;row++){
      switch (S[row][col]){
      case 'A':
        countA++;
        break;
      case 'C':
        countC++;
        break;
      case 'G':
        countG++;
        break;
      case 'T':
        countT++;
        break;
      default:
        break;
      }
    }
    comparing=std::max(std::max(std::max(countG,countT), countC), countA);
    if(comparing==countA){
      consensus.append("A");
    }else{
      if(comparing==countC){
        consensus.append("C");
      }else{
        if(comparing==countG){
          consensus.append("G");
        }else{
          consensus.append("T");
        }
      }
    }
    countA=0;
    countC=0;
    countG=0;
    countT=0;
  }
  cout << consensus << endl;
    cout << "Ejecutado en el proceso 1" << endl;

}
MPI_Finalize();

  double t1 = omp_get_wtime();

cout << "Código paralelo ejecutado en Xeon Phi" << endl;

cout << "Time: " << t1-t0 << endl;

cout << "comm size: " << size << endl;
}
