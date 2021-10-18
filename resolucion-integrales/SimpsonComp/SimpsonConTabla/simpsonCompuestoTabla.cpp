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
	double sumImp=0; //suma los valores internos impares
	double sumPar=0; //suma los valores internos pares

	//controlar q esta equiespaciada!!! =)
	h=x[1]-x[0];

	if(n%2==0){
		cout << "No se puede aplicar el metodo de Simpson! Usar Trapecio!! o interpolar para buscar mas puntos!" << endl;
		exit(0);	
	}

	for(int i=1; i <= n-2; i++){
		sumImp+=y[i];
		i++;
	}
	
	for(int i=2; i <= n-3; i++){
		sumPar+=y[i];
		i++;
	}
	
	aprox=(h/3)*((y[0] + y[n-1])+(4*sumImp)+(2*sumPar));
	
	printf("La integral f(x) en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],aprox);
	cout << endl << endl;
	
}
