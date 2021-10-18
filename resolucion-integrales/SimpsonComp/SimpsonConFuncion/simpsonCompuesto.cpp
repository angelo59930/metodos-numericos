#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

double f(double x){
//integrate pow(4x-5,3) between -3,5 -> wolfram.
	return pow((4*x-5),3);
}

int main(void){

	double a;
	double b;
	int n;
	double h;
	double aprox;
	double x;
	double sumImp=0; //suma los valores internos impares
	double sumPar=0; //suma los valores internos pares

	cout << "Valor inferior del intervalo: ";
	cin >> a;
	cout << "Valor superior del intervalo: ";
	cin >> b;
	do{
		cout << "Cantidad de intervalos/segmentos: ";
		cin >> n;
	}while(n%2 != 0);

	h=(b-a)/n;
	
	for(int i=1; i <= n-1; i++){
		x=a+i*h;
		sumImp+=f(x);
		i++;
	}
	
	for(int i=2; i <= n-2; i++){
		x=a+i*h;
		sumPar+=f(x);
		i++;
	}
	
	aprox=(h/3)*((f(a) + f(b))+(4*sumImp)+(2*sumPar));
	
	printf("La integral f(x) en el intervalo [%lf;%lf] es: %lf", a,b,aprox);
	cout << endl << endl;
	
}
