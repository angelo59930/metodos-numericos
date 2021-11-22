#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]){

  #include "lectura_escritura_datos.c"
  double b[filas];
  #include "lectura_escritura_datos_ideptes.c"
  double epsilon = pow(10,-10);
  double e = 1;
  double xv[filas];
  double xn[filas];
  double s;
  int iteracion = 0;

  for (int i  = 0; i < filas; i++){
    double suma = 0;
    for(int j = i+1; j < filas; j++)
      suma += m[i][j];
    cout << m[i][i] << " " << suma << endl;
    if(abs(m[i][i]) < abs(suma)){
      cout << "la matriz no se puede resolver por este metodo" << endl;
      return 0;
    }
  }

  for(int i = 0; i < filas; i++){
    xv[i] = 0;
    xn[i] = 0;
  }


  while (e > epsilon){
    for (int i = 0; i < filas; i++){
      s = 0;
      for (int j = 0; j < i; j++)
        s += m[i][j] * xn[j];
      
      for (int j = i + 1; j < filas; j++)
        s += m[i][j] * xv[j];

      xn[i] = (b[i] - s)/m[i][i];    
      
      double e1 = 0, e2 = 0;
      for(int i = 0; i < filas; i++){
        e1 += pow(xn[i]-xv[i],2);
        e2 += pow(xn[i],2);
      }
      e = sqrt(e1/e2);

      for(int i = 0; i < filas; i++)
        xv[i] = xn[i];
    }

    i++;
  }

  cout << endl << "----- Soluciones -----" << endl;
  cout << "numeros de iteraciones " << i << endl;
 	for(int i =0; i<=filas-1; i++)
 		cout << endl << "x["<< i+1 << "]= " << xn[i];
 	cout << endl;

  return 0;
}

