#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void){

	#include"lectura_escritura_datos.c"

	int n=filas;
	double h;
	double sum=0; //suma los valores internos 

	for(int i=0; i<n-1; i++){
		h=x[i+1]-x[i];
		sum+=(h/2)*(y[i] + y[i+1]);
	}
	
	printf("La integral f(x) con puntos NO EQUIDISTANTES en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],sum);
	cout << endl << endl;
	
}
