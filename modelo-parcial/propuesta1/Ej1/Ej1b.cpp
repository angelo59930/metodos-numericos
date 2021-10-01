#include <iostream>
#include <cmath>

using namespace std;

double f(double x);
double g(double x);
double derivada(double x);

int main(int argc, char const *argv[])
{
  double a;
  double x1;
  double x;
  double error;
  double errorMinimo;
  int iteracion = 0;
  cout << "Ingrese el valor inicial: " << endl;
  cin >> a;
  cout << "Ingrese el valor del error esperado (e): " << endl;
  cin >> errorMinimo;
  error = errorMinimo + 1;
  x = a;
  while (error > errorMinimo)
  {
    iteracion++;
    if (fabs(derivada(x)) > 1)
    {
      printf("El metodo no converge porque la derivada de g(x) en a es mayor o igual a 1");
      return 0;
    }
    x1 = g(x);
    error = fabs(x - x1);
    x = x1;
    printf("Iteracion: %d, Error: %lf\n", iteracion, error);
  }
  cout << "La Raiz es: " << x << endl;
  return 0;
}

double f(double x)
{
  return (2 * x + log10(x) - sin(3 * x));
}

double g(double x)
{
  return (-log10(x)+sin(3*x))/2;
}

double derivada(double x)
{
  double h = 0.00001;
  return ((3 * g(x)) - (4 * g(x - h)) + (g(x - 2 * h))) / (2 * h);
}
