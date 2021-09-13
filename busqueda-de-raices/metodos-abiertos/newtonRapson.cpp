#include <stdio.h>
#include <math.h>
double funcion(double x)
{
  return x*x-2;
}
void grafica(double a, double b)
{
  FILE *graf;
  double x, delta;
  int n;
  graf = popen("gnuplot -persit", "w");
  if (graf != NULL)
  {
    fprintf(graf, "set style data line\n");
    fprintf(graf, "set grid\n");
    fprintf(graf, "plot '-' notitle, 0 notitle\n");
    x = a;
    delta = (b - a) / 480;
    for (n = 0; n < 480; n++)
    {
      fprintf(graf, "%e %e\n", x, funcion(x));
      x = a + delta * n;
    }
    fprintf(graf, "e\n");
    pclose(graf);
  }
}
int main(void)
{
  double a, b, m, fa, fm, anterior;
  double error = 0.0001;
  m = a = 0; //cambiar limite superior
  b = 5; // cambiar limite inferior
  grafica(a, b);
  if ((funcion(a) * funcion(b)) < 0)
  {
    do
    {
      anterior = m;
      m = (a + b) / 2;
      fa = funcion(a);
      fm = funcion(m);
      printf("a=%11.4e\tb=%11.4e\tm=%11.4e\t", a, b, m);
      if ((fa * fm) < 0)
      {
        b = m;
        printf("sigue b=m=%11.4e\n", m);
      }
      else
      {
        a = m;
        printf("sigue a=m=%11.4e\n", m);
      }
    } while (fabs((m - anterior) / m) > error);
    printf("La raiz es %e (f(%e)=%e)\n", m, m, fm);
  }
  else
    printf("No se puede aplicar el método en el intervalo indicado.\n");
}