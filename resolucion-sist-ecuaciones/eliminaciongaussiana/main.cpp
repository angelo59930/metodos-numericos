#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>

/*
* Este codigo fue proporcionado por la docente de la materia
**/

using namespace std;


int main(void)
{

    #include"lectura_escritura_datos.c"
    double b[filas];
    #include"lectura_escritura_datos_ideptes.c"

	double f;
	int aux;
	float errorMinimo = 1e-10; //ACORDARSE DE CAMBIARLO!!!	

	//triangulacion superior
	int n = filas;
	for(int i=0; i < n-1; i++)
	{
		//pivoteo
		int cambio =0;
		if (fabs(m[i][i])<errorMinimo)
		{
			for(int j=i+1; j<=n-1; j++)
			{
				if(fabs(m[j][i])>errorMinimo) //Error parecido a 0.
				{
					for (int k=i;k<=n-1;k++)
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
			}else
				cout<< "Se hizo pivoteo ! "<<endl;
		}
	//***********************FIN PIVOTEO********************************
		for(int j=i+1; j <= n-1; j++)
		{
			f=(-m[j][i])/(m[i][i]);
			for (int k=i; k <= n-1; k++) //k arranca desde la diagonal principal.. k=i.
				m[j][k]=m[j][k]+f*m[i][k];
			b[j]=b[j]+f*b[i];
		} 
	}

	//imprime la matriz como quedo!! 
	cout << endl << "La Matriz triangular superior quedo: " << endl;
	for(int i = 0; i<filas; i++){
		for(int j = 0; j < columnas; j++){
			cout << m[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}

	
	//sustitucion regresiva
	double suma;
	double x[filas]; //vector de soluciones

	//valor de la ultima variable 
	x[filas-1] = b[filas-1] / m[filas-1][filas-1];

	for (int i=filas-2; i>=0; i--)
	{
		suma = b[i];
		for(int j=i+1; j<=n-1; j++)
		{
			suma-=m[i][j]*x[j];
		} 
		x[i]=(suma)/m[i][i];
	}
	cout << endl;
	
	cout << endl << "----- Soluciones -----" << endl;
 	for(int i =0; i<=n-1; i++)
 		cout << endl << "x["<< i+1 << "]= " << x[i];
 	cout << endl;
 		
 		
}
