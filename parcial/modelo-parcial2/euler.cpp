
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>
using namespace std;

/*double f(double x, double y)
{
  double a;
  a = x*x + y;
  return a;
}*/

int main(void)
{

  int j, N;
  double h, x[N], y[N];
  float x_min, x_max, yo;

  FILE *file;

  printf("ingrese el valor del limite inferior del intervalo de integracion\n");
  scanf("%f", &x_min);

  printf("ingrese el valor del limite superior del intervalo de integracion\n");
  scanf("%f", &x_max);

  printf("ingrese el numero de puntos\n");
  scanf("%d", &N);

  printf("x_min=%f, x_max=%f, N=%d\n", x_min, x_max, N);

  h = (x_max - x_min) / N;

  printf("h=%.12f\n", h);

  printf("ingrese el dato inicial\n");
  scanf("%f", &yo);
  printf("yo=%f\n", yo);

  x[0] = x_min;
  y[0] = yo;
  j = 0;
  /*while (x[j] != x_max && j < N)
    {
      x[j + 1] = x[j] + h;
      y[j + 1] = y[j] + h * f(x[j], y[j]);
      j++;
      if (error > errorMax)
      {
        h = h * (3 / 4); //Achicamos h.
      }
      else if (error < errorMin)
      {
        h = h * (4 / 3); //Aumentamos h.
      }
    }
*/
  for (j=1; j<=N; j++)
   x[j] = x_min + (double)j * h;
  for (j = 1; j < N; j++)
    y[j+1] = (y[j]+h*pow(x[j+1],2))/(1-h);
  

  file = fopen("datos.dat", "w");

  for (j = 0; j <= N; j++){
    printf("x[%d]=%f, y[%d]=%f\n", j, x[j], j, y[j]);

    fprintf(file, "%.12f  %.12f\n", x[j], y[j]);
  }

}
