#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void){

	#include"lectura_escritura_datos.c"
	//Puntos deben estar ordenados! 
	cout << endl <<"SPLINE CUBICA NATURAL" << endl;

	int n=filas;
	
	//Error real: valor real - valor del metodo
	//Error relativo: (valor real - valor del metodo) / valor real
	//Error porcentual : idem del de arriba, pero multiplicarlo por 100.
	
	//tengo 4(n-1) incognitas
	int N=4*(n-1)+1; // N total
	double m[N][N];
	double b[N];
	double aux;
	double valor; //valor buscado
	double resultado; // solucion!!

	cout << endl << "Cantidad de puntos: " << n << endl;
	
	//inicializo mis matrices en cero
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
				m[i][j]=0;
		b[i]=0;	
	}
	
	
	//Polinomios
	for(int i=1; i<n; i++)
	{
		m[i*2-1][i*4-3]=1;
		m[i*2-1][i*4-2]=x[i-1];
		m[i*2-1][i*4-1]=pow(x[i-1],2);
		m[i*2-1][i*4]=pow(x[i-1],3);
		b[i*2-1]=y[i-1];
	
		m[i*2][i*4-3]=1;
		m[i*2][i*4-2]=x[i+1-1];
		m[i*2][i*4-1]=pow(x[i+1-1],2);
		m[i*2][i*4]=pow(x[i+1-1],3);
		b[i*2]=y[i+1-1];
	}


	//Derivadas Primeras
	j=2*(n-1);
	for(int i=2; i<=n-1; i++)
	{
		m[j+i-1][(i-1)*4-3]=0;
		m[j+i-1][(i-1)*4-2]=1;
		m[j+i-1][(i-1)*4-1]=2*x[i-1];
		m[j+i-1][(i-1)*4]=3*pow(x[i-1],2);

		m[j+i-1][(i-1)*4+1]=0;
		m[j+i-1][(i-1)*4+2]=-1;
		m[j+i-1][(i-1)*4+3]=-2*x[i-1];
		m[j+i-1][(i-1)*4+4]=-3*pow(x[i-1],2);
	} 



	// Derivadas Segundas
	j=2*(n-1)+(n-2);
	for(int i=2; i<=n-1; i++)
	{
		m[j+i-1][(i-1)*4-3]=0;
		m[j+i-1][(i-1)*4-2]=0;
		m[j+i-1][(i-1)*4-1]=2;
		m[j+i-1][(i-1)*4]=6*x[i-1];

		m[j+i-1][(i-1)*4+1]=0;
		m[j+i-1][(i-1)*4+2]=0;
		m[j+i-1][(i-1)*4+3]=-2;
		m[j+i-1][(i-1)*4+4]=-6*x[i-1];
	} 
	
	//Condicion de Splain natural (se puede cambiar!! OJO) (recordar que aca lo estoy igualando a la derivada
	// segunda =0!! 
	j=2*(n-1)+(n-2)+(n-2);
	m[j+1][1]=0;
	m[j+1][2]=0;
	m[j+1][3]=2;
	m[j+1][4]=6*x[0];
	b[j+1]=0;

	m[j+2][N-4]=0;
	m[j+2][N-3]=0;
	m[j+2][N-2]=2;
	m[j+2][N-1]=6*x[n-1];
	b[j+2]=0;

	// muevo la matriz un indice!! 
	for(int i=1; i<N; i++)
	{
		for(j=1; j<N; j++)
		{
			m[i-1][j-1]=m[i][j];
		}	
		b[i-1]=b[i];
	}

	
	//Imprimo mi matriz
	for(int i = 0; i<N-1; i++){
		for(j = 0; j < N-1; j++){
			cout << m[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}

	//redefino mi N
	int Nnuevo=N-1;
	double errorMinimo=1e-6;
	double f;

	cout << Nnuevo << "N" << endl;
	//triangulacion superior
	for(int i=0; i < Nnuevo-1; i++)
	{
		//pivoteo
		int cambio =0;
		if (fabs(m[i][i])<errorMinimo)
		{
			for(int j=i+1; j<=Nnuevo-1; j++)
			{
				if(fabs(m[j][i])>errorMinimo)
				{
					for (int k=i;k<=Nnuevo-1;k++)
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
				cout << "El Sistema es singular! no se puede resolver: " << i << "------m: " << m[i][i]<< endl;
				return 0;
			}
		}
	//***********************FIN PIVOTEO********************************
		for(int j=i+1; j <= Nnuevo-1; j++)
		{
			f=(-m[j][i])/(m[i][i]);
			for (int k=i; k <= Nnuevo-1; k++)
				m[j][k]=m[j][k]+f*m[i][k];
			b[j]=b[j]+f*b[i];
		} 
	}

	//imprime la matriz como quedo!! 
	cout << endl << "La Matriz triangular superior quedo: " << endl;

	for(int i = 0; i<Nnuevo; i++){
		for(int j = 0; j < Nnuevo; j++){
			cout << m[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}


	//sustitucion regresiva
	double suma;
	double a[Nnuevo]; //vector de soluciones

	//valor de la ultima variable 
	a[Nnuevo-1] = b[Nnuevo-1] / m[Nnuevo-1][Nnuevo-1];
	cout << endl << "----- Soluciones -----" << endl;
	cout << endl << "a["<< Nnuevo-1 << "]= " << a[Nnuevo-1];

	for (int i=Nnuevo-2; i>=0; i--)
	{
		suma = b[i];
		for(int j=i+1; j<=Nnuevo-1; j++)
		{
			suma-=m[i][j]*a[j];
		} 
		a[i]=(suma)/m[i][i];
		cout << endl << "a["<< i << "]= " << a[i];
	}

	cout << endl;


	cout << "Ingrese el valor que desea interpolar: ";
	cin >> valor;

	cout<< endl;
	cout<< "X :          Y: "<<endl;


		for(int i=0; i< n-1; i++)
		{
			if(x[i]<=valor && valor<=x[i+1])
			{
				j=i*4;
				resultado=a[j]+a[j+1]*valor+a[j+2]*pow(valor,2)+a[j+3]*pow(valor,3);
			//cout << "i" << i << endl;		
			break;
			}
		}
		
		printf("%lf %lf", valor, resultado);
		cout << endl;
		

}

