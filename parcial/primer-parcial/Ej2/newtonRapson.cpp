#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

double funcion(double x)
{
  return pow(x,3)+4*x-10;
}

double derivada(double x)
{
  double h = 0.01;
  return (-funcion(x + 2 * h) + 8 * funcion(x + h) - 8 * funcion(x - h) + funcion(x - 2 * h)) / (12 * h);
}

int main()
{

  int pasos = 0;

  double epsilon = pow(10,-6), xp, x = 2, error;

 
  do
  {

    xp = (x - (funcion(x) / derivada(x)));

    if (derivada(xp) > 1)
    { //Si el resultado de la derivada esta a la izquierda pongo <, de lo contrario pongo menor;

      pasos++;

      error = (fabs(xp - x) / fabs(xp)); //Error absoluto
      // error porcentual = error exacto * 100 /raiz
      //error = pow((xp-x),2) / pow(x,2);    //Error relativo

      if (pasos == 1000)
      {
        cout << "No se ha encontrado raices, inicie con otro intervalo o un menor error" << endl;
        exit(EXIT_FAILURE);
      }

      x = xp;

      cout << "paso: " << pasos << "\n error: " << error << endl;
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