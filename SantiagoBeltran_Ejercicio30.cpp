#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;

void AdvecLax(string filename);
const int m=100;
const float dx=0.01;
const float dt=0.01;
const float c=1.0;
const float beta=c*dt/dx;
const float pi=4*atan(1);
const int n=200;

int main(){
  AdvecLax("intento.dat");
  return 0;
}

void AdvecLax(string filename){
    float U[m+1][n+1]={0};
    
    ofstream outfile;
    outfile.open(filename);
    float x;
    for(int i=0; i<m+1;i++){
        for(int j=0; j<n+1; j++){
            U[i][j]=0.0;
        }
    }
    for (int i=0; i<m+1;i++){
        x=i*dx;
        U[i][0]=0.05*sin(4*M_PI*x);
        }
    for(int j=0; j<m+1; j++){
            outfile << U[j][0] << " ";
            if(j==m){outfile<<endl;}
        }
    
    for(int j=0; j<n;j++){
        for(int i=1;i<m;i++){
            U[i][j+1]=U[i][j]-(beta/4)*(U[i+1][j]*U[i+1][j]-U[i-1][j]*U[i-1][j])+(beta*beta/8)*((U[i+1][j]+U[i][j])*(U[i+1][j]*U[i+1][j]-U[i][j]*U[i][j]))-(U[i][j]+U[i-1][j])*(U[i][j]*U[i][j]-U[i-1][j]*U[i-1][j]);
        }
    }
    for(int j=1; j<n+1; j++){
            for(int i=0; i<m+1; i++){
            outfile << U[i][j] << " ";
            if(i==m){outfile<<endl;}
        }
        }
}
