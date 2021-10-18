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
// funcion original
double f(double x)
{
  return 3 * x + sin(x) - exp(x);
}
// despeje
double g(double x)
{
  return -(sin(x)-exp(x))/3;
}
// derivada
double derivada(double x)
{
  double h = 0.01;
  return (g(x + h) - g(x)) / h;
}
