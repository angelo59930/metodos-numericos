#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
//Se cambia.
double f(double x)
{
  return (2 - (pow(x, 3))) * pow((x - 3), 2);
}
//No se toca
double g(double x, double a, double b)
{
  return f((((b - a) / 2) * x) + (b + a) / 2);
}

int main(void)
{

  double a;
  double b;
  int n;
  double w[6];
  double x[6];
  double aprox; // tiene la solucion!! =)
  double dx;

  cout << "Valor inferior del intervalo: ";
  cin >> a;
  cout << "Valor superior del intervalo: ";
  cin >> b;

  dx = (b - a) / 2;
  do
  {
    cout << "Cantidad de puntos [o 0 (cero) para salir] =";
    cin >> n;

    switch (n)
    {

    case 0:
      cout << endl
           << "Salida";
      break;

    case 2:

      cout << endl
           << "Cuadratura de Gauss con 2 puntos" << endl;
      //Factor de ponderacion
      w[0] = 1; //Puede cambiar
      w[1] = 1; //Puede cambiar
      //Argumentos de la funcion
      x[0] = -sqrt((double)1 / 3); //valor de sigma 1 NO CAMBIA
      x[1] = sqrt((double)1 / 3);  //valor de sigma 2  IDEM

      aprox = ((w[0] * g(x[0], a, b)) + (w[1] * g(x[1], a, b))) * dx;

      printf("\nLa integral f(x) en el intervalo [%lf;%lf] es: %lf\n", a, b, aprox);

      break;

    case 3:
      cout << endl
           << "Cuadratura de Gauss con 3 puntos" << endl;
      //Factor de ponderacion
      w[0] = (double)5 / 9;
      w[1] = (double)8 / 9;
      w[2] = (double)5 / 9;
      //Argumentos de la funcion
      x[0] = -sqrt((double)3 / 5);
      x[1] = 0;
      x[2] = sqrt((double)3 / 5);

      aprox = ((w[0] * g(x[0], a, b)) + (w[1] * g(x[1], a, b)) + (w[2] * g(x[2], a, b))) * dx;

      printf("\nLa integral f(x) en el intervalo [%lf;%lf] es: %lf\n", a, b, aprox);

      break;

    case 4:
      cout << endl
           << "Cuadratura de Gauss con 4 puntos" << endl;
      //Factor de ponderacion
      w[0] = (18 - sqrt((double)30)) / 36;
      w[1] = (18 + sqrt((double)30)) / 36;
      w[2] = (18 + sqrt((double)30)) / 36;
      w[3] = (18 - sqrt((double)30)) / 36;
      //Argumentos de la funcion
      x[0] = -sqrt((double)(3 + 2 * sqrt((double)6 / 5)) / 7);
      x[1] = -sqrt((double)(3 - 2 * sqrt((double)6 / 5)) / 7);
      x[2] = sqrt((double)(3 - 2 * sqrt((double)6 / 5)) / 7);
      x[3] = sqrt((double)(3 + 2 * sqrt((double)6 / 5)) / 7);

      aprox = ((w[0] * g(x[0], a, b)) + (w[1] * g(x[1], a, b)) + (w[2] * g(x[2], a, b)) + (w[3] * g(x[3], a, b))) * dx;

      printf("\nLa integral f(x) en el intervalo [%lf;%lf] es: %lf\n", a, b, aprox);

      break;

    case 5:
      cout << endl
           << "Cuadratura de Gauss con 5 puntos" << endl;
      //Factor de ponderacion
      w[0] = (double)(322 - 13 * sqrt((double)70)) / 900;
      w[1] = (double)(322 + 13 * sqrt((double)70)) / 900;
      w[2] = (double)128 / 225;
      w[3] = (double)(322 + 13 * sqrt((double)70)) / 900;
      w[4] = (double)(322 - 13 * sqrt((double)70)) / 900;
      //Argumentos de la funcion
      x[0] = -0.906179846;
      x[1] = -0.538469310;
      x[2] = 0;
      x[3] = 0.538469310;
      x[4] = 0.906179846;

      aprox = ((w[0] * g(x[0], a, b)) + (w[1] * g(x[1], a, b)) + (w[2] * g(x[2], a, b)) + (w[3] * g(x[3], a, b)) + (w[4] * g(x[4], a, b))) * dx;

      printf("\nLa integral f(x) en el intervalo [%lf;%lf] es: %lf\n", a, b, aprox);

      break;

    case 6:
      cout << endl
           << "Cuadratura de Gauss con 6 puntos" << endl;
      //Factor de ponderacion
      w[0] = 0.1713244924;
      w[1] = 0.3607615730;
      w[2] = 0.4679139346;
      w[3] = 0.4679139346;
      w[4] = 0.3607615730;
      w[5] = 0.1713244924;
      //Argumentos de la funcion
      x[0] = -0.9324695142;
      x[1] = -0.6612093865;
      x[2] = -0.2386191861;
      x[3] = 0.2386191861;
      x[4] = 0.6612093865;
      x[5] = 0.9324695142;

      aprox = ((w[0] * g(x[0], a, b)) + (w[1] * g(x[1], a, b)) + (w[2] * g(x[2], a, b)) + (w[3] * g(x[3], a, b)) + (w[4] * g(x[4], a, b)) + (w[5] * g(x[5], a, b))) * dx;
      printf("\nLa integral f(x) en el intervalo [%lf;%lf] es: %lf\n", a, b, aprox);
      break;
    }
  } while (n != 0);

  cout << endl
       << endl;
}
