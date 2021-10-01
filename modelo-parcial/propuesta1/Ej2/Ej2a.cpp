#include <iostream>
#include <cmath>
#include <fstream>


#define N 100
using namespace std;

int main(int argc, char const *argv[]){
  double term_idem[N];
  double matriz[N][N] {};
  ofstream escritura;
  
  // Creacion de la matriz de terminos independientes
  for (int i = 0; i < N; i++){
    if(i == 0 || i == 99)
      term_idem[i] = 4.5;
    else
      term_idem[i] = 6;
  }
  

  // creacion de la matriz de datos
  for (int i = 0; i < N; i++){
    for (int j = i; j < N; j++){
      matriz[i][i] = 2;
      if(j == 0)
        matriz[i][j + 1] = 1;
      else if (matriz[i][j] == 2){
        matriz[i][j - 1] = 1;
        matriz[i][j + 1] = 1;
      }
    }
  }

  // Escritura de archivos
  escritura.open("matrizIndep.dat");
  for (int i = 0; i < N; i++){
    escritura << term_idem[i] << endl;
  }
  escritura.close();

  escritura.open("matriz.dat");
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      escritura << matriz[i][j];
      if (j != N-1)
        escritura << " ";
    }
    escritura << endl;
  }
  escritura.close();
  return 0;
}

