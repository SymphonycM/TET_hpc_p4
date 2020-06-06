#include <iostream>
#include <fstream>
#include <omp.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]){
    double t0 = omp_get_wtime();
    ifstream infile(argv[1]);
    std::string line="";
    int length=0;
    while (infile >> line){
        length=line.length();
    }
        cout << length << endl;
        char t[length];
        strcpy(t, line.c_str());
        for(int k=0;k<length;k++){
            if(t[k]=='T'){
                t[k]='U';
            }
        }
    
    for(int j=0;j<length;j++){
    	cout << t[j];
	}
    cout << endl;
    double t1 = omp_get_wtime();
    cout << "Time: " << t1-t0 << endl;
}