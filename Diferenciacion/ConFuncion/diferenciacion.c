#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

double f(double x){
	return -0.1*pow(x,4)-0.15*pow(x,3)-0.5*pow(x,2)-0.25*x+1.2;
}

int main(void){

	double x;
	double h;
	double aprox;
	int op;
	int op1;
	
	cout << endl << "DIFERENCIACION DE UNA FUNCION" << endl;

	cout << "Ingrese punto derivar= ";
	cin >> x;
//0.5 ->
	cout << "Ingrese h= ";
	cin >> h;
	
	do{
		
		cout << "OPCIONES " << endl;
		cout << "1.Derivacion por derecha (hacia delante)" << endl;
		cout << "2.Derivacion centrada" << endl;
		cout << "3.Derivacion por izquierda (hacia atras)" << endl;
		cout << "0.Para salir" << endl;
		cout << "Opcion: " ;
		cin >> op;
		
		switch(op){
		
			case 1: 
					cout << "OPCIONES " << endl;
					cout << "1.Derivada Primera" << endl;
					cout << "2.Derivada Segunda" << endl;
					cout << "3.Derivada Tercera" << endl;
					cout << "4.Derivada Cuarta" << endl;
					cout << "Opcion: " ;
					cin >> op1;
			
					switch(op1){
					
					case 1:
							aprox=(f(x+h)-f(x))/h;
							printf("\n\nLa derivada primera por la DERECHA de f(%lf)=%lf, y tiene un error de orden h\n",x,aprox);
					
							aprox=(-f(x+2*h)+4*f(x+h)-3*f(x))/(2*h);
							printf("\n\nLa derivada primera por la DERECHA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
							break;
					
					case 2:
							aprox=(f(x+2*h)-2*f(x+h)+f(x))/(pow(h,2));
							printf("\n\nLa derivada segunda por la DERECHA de f(%lf)=%lf, y tiene un error de orden h\n",x,aprox);
					
							aprox=(-f(x+3*h)+4*f(x+2*h)-5*f(x+h)+2*f(x))/(pow(h,2));
							printf("\n\nLa derivada segunda por la DERECHA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
							break;
					
					case 3:
							aprox=(f(x+3*h)-3*f(x+2*h)+3*f(x+h)-f(x))/(pow(h,3));
							printf("\n\nLa derivada tercera por la DERECHA de f(%lf)=%lf, y tiene un error de orden h\n",x,aprox);
					
							aprox=(-3*f(x+4*h)+14*f(x+3*h)-24*f(x+2*h)+18*f(x+h)-5*f(x))/(2*pow(h,3));
							printf("\n\nLa derivada tercera por la DERECHA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
							break;
					
					case 4:
							aprox=(f(x+4*h)-4*f(x+3*h)+6*f(x+2*h)-4*f(x+h)+f(x))/(pow(h,4));
							printf("\n\nLa derivada cuarta por la DERECHA de f(%lf)=%lf, y tiene un error de orden h\n",x,aprox);
					
							aprox=(-2*f(x+5*h)+11*f(x+4*h)-24*f(x+3*h)+26*f(x+2*h)-14*f(x+h)+3*f(x))/(pow(h,4));
							printf("\n\nLa derivada cuarta por la DERECHA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
							break;
					
					}
			case 2:
					cout << "OPCIONES " << endl;
					cout << "1.Derivada Primera" << endl;
					cout << "2.Derivada Segunda" << endl;
					cout << "3.Derivada Tercera" << endl;
					cout << "4.Derivada Cuarta" << endl;
					cout << "Opcion: " ;
					cin >> op1;
			
					switch(op1){
			
					case 1:
						
						aprox=(f(x+h)-f(x-h))/(2*h);
						printf("\n\nLa derivada primera CENTRADA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
					
						aprox=(-f(x+2*h)+8*f(x+h)-8*f(x-h)+f(x-2*h))/(12*h);
						printf("\n\nLa derivada primera CENTRADA de f(%lf)=%lf, y tiene un error de orden h⁴\n",x,aprox);
						break;
					
					case 2:
					
						aprox=(f(x+h)-2*f(x)+f(x-h))/(pow(h,2));
						printf("\n\nLa derivada segunda CENTRADA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
					
						aprox=(-f(x+2*h)+16*f(x+h)-30*f(x)+16*f(x-h)-f(x-2*h))/(12*pow(h,2));
						printf("\n\nLa derivada segunda CENTRADA de f(%lf)=%lf, y tiene un error de orden h⁴\n",x,aprox);
						break;
					case 3:	
						aprox=(f(x+2*h)-2*f(x+h)+2*f(x-h)-f(x-2*h))/(2*pow(h,3));
						printf("\n\nLa derivada tercera CENTRADA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
					
						aprox=(-f(x+3*h)+8*f(x+2*h)-13*f(x+h)+13*f(x-h)-8*f(x-2*h)+f(x-3*h))/(8*pow(h,3));
						printf("\n\nLa derivada tercera CENTRADA de f(%lf)=%lf, y tiene un error de orden h⁴\n",x,aprox);
						break;
					case 4:
						aprox=(f(x+2*h)-4*f(x+h)+6*f(x)-4*f(x-h)+f(x-2*h))/(pow(h,4));
						printf("\n\nLa derivada primera CENTRADA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
					
						aprox=(-f(x+3*h)+12*f(x+2*h)+39*f(x+h)+56*f(x)-39*f(x-h)+12*f(x-2*h)+f(x-3*h))/(6*pow(h,4));
						printf("\n\nLa derivada primera CENTRADA de f(%lf)=%lf, y tiene un error de orden h⁴\n",x,aprox);
						break;
					}
					
					
					
			case 3:
			
					cout << "OPCIONES " << endl;
					cout << "1.Derivada Primera" << endl;
					cout << "2.Derivada Segunda" << endl;
					cout << "3.Derivada Tercera" << endl;
					cout << "4.Derivada Cuarta" << endl;
					cout << "Opcion: " ;
					cin >> op1;
					
					switch(op1)
					{
						
					case 1:
					
						aprox=(f(x)-f(x-h))/(h);
						printf("\n\nLa derivada primera por la IZQUIERDA de f(%lf)=%lf, y tiene un error de orden h\n",x,aprox);
					
						aprox=(3*f(x)-4*f(x-h)+f(x-2*h))/(2*h);
						printf("\n\nLa derivada primera por la IZQUIERDA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
						break;
			
					case 2:
					
						aprox=(f(x)-2*f(x-h)+f(x-2*h))/(pow(h,2));
						printf("\n\nLa derivada segunda por la IZQUIERDA de f(%lf)=%lf, y tiene un error de orden h\n",x,aprox);
					
						aprox=(2*f(x)-5*f(x-h)+4*f(x-2*h)-f(x-3*h))/(pow(h,2));
						printf("\n\nLa derivada segunda por la IZQUIERDA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
						break;
						
					case 3:
					
						aprox=(f(x)-3*f(x-h)+3*f(x-2*h)-f(x-3*h))/(pow(x,3));
						printf("\n\nLa derivada tercera por la IZQUIERDA de f(%lf)=%lf, y tiene un error de orden h\n",x,aprox);
					
						aprox=(5*f(x)-18*f(x-h)+24*f(x-2*h)-14*f(x-3*h)+3*f(x-4*h))/(2*pow(h,3));
						printf("\n\nLa derivada tercera por la IZQUIERDA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
						break;
					case 4:
					
						aprox=(f(x)-4*f(x-h)+6*f(x-2*h)-4*f(x-3*h)+f(x-4*h))/(pow(h,4));
						printf("\n\nLa derivada cuarta por la IZQUIERDA de f(%lf)=%lf, y tiene un error de orden h\n",x,aprox);
					
						aprox=(3*f(x)-14*f(x-h)+26*f(x-2*h)-24*f(x-3*h)+11*f(x-4*h)-2*f(x-5*h))/(pow(h,4));
						printf("\n\nLa derivada cuarta por la IZQUIERDA de f(%lf)=%lf, y tiene un error de orden h²\n",x,aprox);
						break;
					}
			case 0:
					cout << "SALIDA!" << endl;
					break;
		
		}
	
	}while(op!=0);
	
}
