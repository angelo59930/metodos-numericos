#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void){

	#include"lectura_escritura_datos.c"
	
	double h=fabs(x[1]-x[0]);
	double aprox;
	int op,op1;
	int n=filas;
	double prueba=0;
	double resultados[n];
	
	cout << endl << "DIFERENCIACION DE UNA FUNCION CON TABLA" << endl;

	//compruebo si mis datos estan equiespaciados
	for(int i=0; i<n-1; i++){
		prueba=fabs(x[i+1]-x[i]);
		
		if(h!=prueba){
			cout << "Los puntos no son equiespaciados" << endl;
			prueba=-1;
			break;
		}
	}
	
	if(prueba == 1)
	{
		 
					cout << "OPCIONES " << endl;
					cout << "1.Derivada Primera por Derecha" << endl;
					cout << "2.Derivada Primera por izquierda" << endl;
					cout << "Opcion: " ;
					cin >> op1;
			
					switch(op1){
					
					case 1:
						cout << "Derivada primera por la DERECHA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-1; i++){
							aprox=(y[i+1]-y[i])/(fabs(x[i+1]-x[i]));
			
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
		
						cout << endl << endl << endl;
		
					/*	cout << "Derivada primera por la DERECHA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-2; i++){			
							aprox=(-y[i+2]+4*y[i+1]-3*y[i])/(2*(x[i+1]-x[i]));
			
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}*/
							break;
					
					case 2:
					
						cout << "Derivada primera POR LA IZQUIERDA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-1; i++){
							aprox=(y[i]-y[i-1])/(fabs(x[i-1]-x[i])); 
			
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
		
						cout << endl << endl << endl;
		/*
						cout << "Derivada segunda por la DERECHA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-2; i++){			
							aprox=(-y[i+3]+4*y[i+2]-5*y[i+1]+2*y[i])/pow((2*(x[i+1]-x[i]),2)); //CONSULTAR !
			
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}*/
							break;
					
				
					}
	
	
	}else{
		cout << endl << endl <<"Los puntos son equiespaciados" << endl;
		h=fabs(x[1]-x[0]);
		do{
	
			cout << endl << endl <<"Ingrese la opcion deseada: " << endl;
			cout << "1.Derivacion por derecha (hacia delante)" << endl;
			cout << "2.Derivacion centrada" << endl;
			cout << "3.Derivacion por izquierda (hacia atras)" << endl;
			cout << "0.Para salir" << endl;
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
						cout << "Derivada primera por la DERECHA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-1; i++){ //Si n=5 . i->4 . 
							aprox=(y[i+1]-y[i])/h;
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada primera por la DERECHA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-2; i++){
							aprox=(-y[i+2]+4*y[i+1]-3*y[i])/(2*h);
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
						break;
						
					case 2:
						cout << "Derivada segunda por la DERECHA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-2; i++){
							aprox=(y[i+2]-2*y[i+1]+y[i])/(pow(h,2));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada segunda por la DERECHA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-3; i++){
							aprox=(-y[i+3]+4*y[i+2]-5*y[i+1]+2*y[i])/(pow(h,2));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
						break;
						
					case 3:
						cout << "Derivada tercera por la DERECHA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-3; i++){
							aprox=(y[i+3]-3*y[i+2]+3*y[i+1]-y[i])/(pow(h,3));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada tercera por la DERECHA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-4; i++){
							aprox=(-3*y[i+4]+14*y[i+3]-24*y[i+2]+18*y[i+1]-5*y[i])/(2*pow(h,3));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
						break;
						
					case 4:
						cout << "Derivada cuarta por la DERECHA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-4; i++){
							aprox=(y[i+4]-4*y[i+3]+6*y[i+2]-4*y[i+1]+y[i])/pow(h,4);
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada cuarta por la DERECHA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=0; i<n-5; i++){
							aprox=(-2*y[i+5]+11*y[i+4]-24*y[i+3]+26*y[i+2]-14*y[i+1]+3*y[i])/pow(h,4);
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
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
						cout << "Derivada primera CENTRADA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=1; i<n-1; i++){
							aprox=(y[i+1]-y[i-1])/(2*h);
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada primera CENTRADA con un error de orden h⁴" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=2; i<n-2; i++){
							aprox=(-y[i+2]+8*y[i+1]-8*y[i-1]+y[i-2])/(12*h);
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
							break;
						
					case 2:
						cout << "Derivada segunda CENTRADA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=1; i<n-1; i++){
							aprox=(y[i+1]-2*y[i]+y[i-1])/(pow(h,2));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada segunda CENTRADA con un error de orden h⁴" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=2; i<n-2; i++){
							aprox=(-y[i+2]+16*y[i+1]-30*y[i]+16*y[i-1]-y[i-2])/(12*pow(h,2));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
						break;
						
					case 3:
						cout << "Derivada tercera CENTRADA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=2; i<n-2; i++){
							aprox=(y[i+2]-2*y[i+1]+2*y[i-1]-y[i-2])/(2*pow(h,3));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada tercera CENTRADA con un error de orden h⁴" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=3; i<n-3; i++){
							aprox=(-y[i+3]+8*y[i+2]-13*y[i+1]+13*y[i-1]-8*y[i-2]+y[i-3])/(8*pow(h,3));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
						break;
						
					case 4:
						cout << "Derivada cuarta CENTRADA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=2; i<n-2; i++){
							aprox=(y[i+2]-4*y[i+1]+6*y[i]-4*y[i-1]+y[i-2])/(pow(h,4));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada tercera CENTRADA con un error de orden h⁴" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=3; i<n-3; i++){
							aprox=(-y[i+3]+12*y[i+2]+39*y[i+1]+56*y[i]-39*y[i+1]+12*y[i-2]+y[i-3])/(6*pow(h,4));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
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
			
					switch(op1){
					
					case 1:
						cout << "Derivada primera por la IZQUIERDA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=1; i<n; i++){
							aprox=(y[i]-y[i-1])/(h);
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada primera por la IZQUIERDA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=2; i<n; i++){
							aprox=(3*y[i]-4*y[i-1]+y[i-2])/(2*h);
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
							break;
						
						
					case 2:
						cout << "Derivada segunda por la IZQUIERDA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=2; i<n; i++){
							aprox=(y[i]-2*y[i-1]+y[i-2])/(pow(h,2));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada segunda por la IZQUIERDA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=3; i<n; i++){
							aprox=(2*y[i]-5*y[i-1]+4*y[i-2]-y[i-3])/(pow(h,2));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
							break;
							
						case 3:
						cout << "Derivada tercera por la IZQUIERDA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=3; i<n; i++){
							aprox=(y[i]-3*y[i-1]+3*y[i-2]-y[i-3])/(pow(h,3));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada tercera por la IZQUIERDA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=4; i<n; i++){
							aprox=(5*y[i]-18*y[i-1]+24*y[i-2]-14*y[i-3]+3*y[i-4])/(2*pow(h,3));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
							break;
							
						case 4:
						cout << "Derivada cuarta por la IZQUIERDA con un error de orden h" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=4; i<n; i++){
							aprox=(y[i]-4*y[i-1]+6*y[i-2]-4*y[i-3]+y[i-4])/(pow(h,4));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
					
						cout << endl << endl << endl;
					
						cout << "Derivada cuarta por la IZQUIERDA con un error de orden h²" << endl;
						printf("      x\t\t\t      y\n");
						for(int i=5; i<n; i++){
							aprox=(3*y[i]-14*y[i-1]+26*y[i-2]-24*y[i-3]+11*y[i-4]-2*y[i-5])/(pow(h,4));
							printf("%d %lf\t\t%lf\n",i,x[i],aprox);
						}
							break;
					}
				case 0:
						cout << "SALIDA!" << endl;
						break;
			}
	
		}while(op!=0);
	}	
}
