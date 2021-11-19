#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
//Se escribe la funcion
double f(double x, double y){
	return 3*pow(y,1/2);
}

int main(void){

	double h;
	double x0;
	double y0;
	int cant;
	double x;
	double y;
	double result;
	double k1,k2,k3,k4;
	int op;
	
	cout << endl <<"Ingrese x0 (condicion inicial)= ";
	cin >> x0;
	cout << endl <<"Ingrese y0 (condicion inicial)= ";
	cin >> y0;
	cout << endl <<"Ingrese h=";
	cin >> h;
	
	x=x0;
	y=y0;
	
	cout << endl <<" Metodos";
	cout << endl << "1. Metodo de Euler";
	cout << endl << "2. Metodo Punto Medio";
	cout << endl << "3. Metodo de Heum";
	cout << endl << "4. Metodo de Runge-Kutta de Cuarto Orden";
	cout << endl << "Ingrese el metodo para resolver la ecuacion diferencial: ";
	cin >> op;
	
	do{
		//Me pueden pedir cambiar el k, la pendiente.
		k1=f(x,y);
		k2=f(x+0.5*h,y+0.5*k1*h);
		k3=f(x+0.5*h,y+0.5*k2*h);
		k4=f(x+h,y+k3*h);
		
		switch(op)
		{
			case 1: 
				cout << endl << "Metodo de Euler" << endl; //el metodo menos mejor
				result=y+h*k1; //k1 es mi pendiente.
				x=x+h;
				printf("En [%lf;%lf] es: %lf", x,result,f(x,result));
		
				cout << endl << endl <<"otro punto? (si=1, no=0)" << endl;
				cin >> cant;
				break;
				
			case 2:
				cout << endl << "Metodo del Punto Medio" << endl;
				result=y+h*k2;
				x=x+h;
				printf("En [%lf;%lf] es: %lf", x,result,f(x,result));
		
				cout << endl << endl <<"otro punto? (si=1, no=0)" << endl;
				cin >> cant;
				break;
				
			case 3:
			//puede cambiar el k2 .
				k2=f(x+h,y+k1*h);
				cout << endl << "Metodo de Heum" << endl;
				result=y+(h/2)*(k1+k2); //mi pendiente es ( k1 +k2 )/2
				x=x+h;
				printf("En [%lf;%lf] es: %lf",x,result,f(x,result));
		
				cout << endl << endl <<"otro punto? (si=1, no=0)" << endl;
				cin >> cant;
				break;
				
			case 4:
				cout << endl << "Metodo de RK4" << endl;
				result=y+(h/6)*(k1+2*k2+2*k3+k4);
				x=x+h;
				printf("En [%lf;%lf] es: %lf", x,result,f(x,result));
		
				cout << endl << endl << "otro punto? (si=1, no=0)" << endl;
				cin >> cant;
	
		}
		y=result;
		
	}while(cant!=0);

	
	cout << endl << endl;
	
}
