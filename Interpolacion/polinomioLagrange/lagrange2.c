#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define N 100000
using namespace std;

int main(void){

	#include"lectura_escritura_datos.c"

	int n=filas;
	double errorMinimo = 1e-6;//ponemos el error minimo que queremos
	double px;	/*COORDENADA X DE UN PAR [x,y]*/
	double py;	/*COORDENADA Y DE UN PAR [x,y]*/
	double m[filas][filas],b[filas];	
	double aux, f; 

	for(int i=0;i<=n-1;i++) //Guardo la matriz 'virtualmente'
	{
		m[i][0] = 1.;
		for(int j=1;j<=n-1;j++)
			{
				m[i][j] = pow(x[i],j);
			}
		b[i] = y[i];
	}
	
	//triangulacion superior
	for(int i=0; i < n-1; i++)
	{
		//pivoteo
		int cambio =0;
		if (fabs(m[i][i])<errorMinimo)
		{
			for(int j=i+1; j<=n-1; j++)
			{
				if(fabs(m[j][i])>errorMinimo)
				{
					for (int k=i;k<n-1;k++)
					{
						aux=m[i][k];
						m[i][k]=m[j][k];
						m[j][k]=aux;			
					}
					aux=b[i];
					b[i]=b[j];
					b[j]=aux;
					cambio=1;
					break;
				}
			}
			if(cambio==0){
				cout << "El Sistema es singular! no se puede resolver" << endl;
				return 0;
			}
		}
	//***********************FIN PIVOTEO********************************
		for(int j=i+1; j <= n-1; j++)
		{
			f=(-m[j][i])/(m[i][i]);
			for (int k=i; k <= n-1; k++)
				m[j][k]=m[j][k]+f*m[i][k];
			b[j]=b[j]+f*b[i];
		} 
	}

	//imprime la matriz como quedo!! 
	cout << endl << "La Matriz triangular superior quedo: " << endl;

	for(int i = 0; i<filas; i++){
		for(int j = 0; j < filas; j++){
			cout << m[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}

	
	//sustitucion regresiva
	double suma;
	double a[filas]; //vector de soluciones

	//valor de la ultima variable 
	a[filas-1] = b[filas-1] / m[filas-1][filas-1];
	cout << endl << "----- Soluciones -----" << endl;
	cout << endl << "a["<< filas-1 << "]= " << a[filas-1];

	for (int i=filas-2; i>=0; i--)
	{
		suma = b[i];
		for(int j=i+1; j<=n-1; j++)
		{
			suma-=m[i][j]*a[j];
		} 
		a[i]=(suma)/m[i][i];
		cout << endl << "a["<< i << "]= " << a[i];
	}
	cout << endl;

	cout << endl;

	//Imprimo el polinomio final:
	cout << "P = " ;
	for(int i=0,j=0;i<n;i++,j++)
	{
		if(j==0)
			cout << a[i] << " + ";
		else
			cout << a[i] << " " << "X^" << j << " ";
		
	}
	
	cout << "\n";

	double valorX;
	double resultado = 0;

	cout << "Ingrese el valor de X : ";
	cin >> valorX;
	
	for(int i=0,j=0;i<n;i++,j++)
	{
			resultado+= a[i] * pow(valorX,j);
		
	}

	cout << "El resultado es : " << resultado << endl;


}
