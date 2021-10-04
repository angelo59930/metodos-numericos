#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

double funcion(double x){
  return 3*x+sin(x)- exp(x);
}

double derivada(double x)
{

  double h = 0.01;
  return (funcion(x + h) - funcion(x - h) / (2 * h));
}

int main(){

  int pasos = 0;

  double epsilon = pow(10,-8), xp = 0, x = 1.5, error = 1;

  do
  {

    xp = (x - (funcion(x) / derivada(x)));

    if (derivada(xp) < 1)
    { //Si el resultado de la derivada esta a la izquierda pongo <, de lo contrario pongo mayor;

      pasos++;

      //error = (fabs(xp - x) / fabs(xp)); //Error absoluto

      error = pow((xp-x),2) / pow(x,2);    //Error relativo

      if (pasos == 1000)
      {
        cout << "No se ha encontrado raices, inicie con otro intervalo o un menor error" << endl;
        exit(EXIT_FAILURE);
      }

      x = xp;
    }
    else
    {

      cout << "Error de convergencia, inicie con otro epsilon mayor" << endl;
      exit(EXIT_FAILURE);
    }

  } while (error > epsilon);

  cout << " La raiz es " << x << "\n numero de pasos : " << pasos << "\n con un error : " << error << endl;

  return 0;
}
