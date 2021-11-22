#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

double funcion(double x)
{

  return (2 * x + log10(x) - sin(3 * x));
}

double derivada(double x)
{

  double h = 0.01;
  return ((3 * funcion(x)) - (4 * funcion(x - h)) + (funcion(x - 2 * h))) / (2 * h);
}

int main()
{

  int pasos = 0;

  double epsilon, xp, x, error;

  cout << "Ingrese el X inicial" << endl;

  cin >> x;

  cout << "Ingrese el valor de epsilon" << endl;

  cin >> epsilon;

  do
  {

    xp = (x - (funcion(x) / derivada(x)));

    if (derivada(xp) > 1)
    { //Si el resultado de la derivada esta a la izquierda pongo <, de lo contrario pongo menor;

      pasos++;

      error = (fabs(xp - x) / fabs(xp)); //Error absoluto

      //error = pow((xp-x),2) / pow(x,2);    //Error relativo

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
