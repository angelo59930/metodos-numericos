#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void){

	#include"lectura_escritura_datos.c"

	int n=filas;
	double h;
	double aprox;
	double sum=0; //suma los valores internos 

	//controlar q esta equiespaciada!!! =)
	h=x[1]-x[0];

	for(int i=1; i <= n-2; i++){
		sum+=y[i];
	}
	
	aprox=(h/2)*((y[0] + y[n-1])+2*sum);
	
	printf("La integral f(x) con puntos EQUIDISTANTES en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],aprox);
	cout << endl << endl;
	
}
