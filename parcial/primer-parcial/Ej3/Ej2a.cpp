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
  term_idem[0] = 1;
  for (int i = 1; i < N; i++){
    term_idem[i] = 4;
  }
  
  matriz[0][0] = 1;
  matriz[N-1][N-1] = 1;

  // creacion de la matriz de datos
  // creacion de la matriz de datos
  for (int i = 1; i < N-1; i++)
  {
    for (int j = i; j < N-1; j++)
    {
      matriz[i][i] = 2;
     if (matriz[i][j] == 2)
      {
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

