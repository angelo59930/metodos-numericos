/*
 * Estos metodos son buenos cuando la funcion f(x)
 * a analizar se encuentra con el dominio acotado en [A,B]
 * o si conocemos en que parte de la funcion se encuentra la raiz.
 *
 * ----------- DESVENTAJAS/A TENER EN CUENTA ------------
 *   . Solo puede encontrar UNA SOLA raiz.
 *   . Estamos obligados a que en el intervalo [A,B]
 *     la funcion pase por el cero, es decir, 
 *     f(A) > 0 y f(B) < 0 o al revez.
 *  -----------------------------------------------------
 * 
 * */

#include <iostream>
#include <cmath>

using namespace std;

/*
* Estas dos funciones en "esencia" hacen lo mismo
* con la diferencia que NORMALMENTE
* el metodo de Regular Falsi("puntoMedioR) es mas rapido
* */
double puntoMedioR(double a, double b);
double puntoMedioB(double a, double b);

// Aca escribiremos la funcion de la cual buscaremos las raices
double f(double x);

int main(int argc, char const *argv[]){
  double a,b,c,error,errorMin,anterior;
  
  cin >> a;
  cin >> b;
  cin >> errorMin;
 
  //Con esta condicion nos aseguramos de que el rango A y B no esten del mismo lado
  if(f(a)*f(b)>0){
    cout << "no hay raices en el intervalo o tiene raices pares" << endl;
    return 0;
  }
  // esta variabla nos ayudara a calcular el error aproximado
  anterior = 0;
  while(error > errorMin){
  
    /*
     * A partir de aca es donde comienza realmente el metodo para encontrar raices.
     * Como en lo que se diferencia cada metodo es como calcula el valor del punto medio,
     * unicamente cambiando la fucion que lo calcula ya estariamos cambiado de metodo.
     * */
    c = puntoMedioR(a,b);
    if(f(a)*f(c)>0)
      a=c;
    else if(f(b)*f(c)>0)
      b=c;
    else
      break;

    // Calculamos el error aproximado siende este el valor absoluto del punto "c" con el anterior
    error = fabs(c-anterior);
    anterior = c; 
  }

  printf("el valor de la raiz es:%f",c);
  return 0;
}

double f(double x){
  return (-3*(x*x*x)+5*(x*x)-x+7);
}

// Calculo de punto medio del met. Regula falsi
double puntoMedioR(double a, double b){ return b-((f(b)*(a-b))/(f(a)-f(b))); }

// Calculo de punto medio del met. biseccion.
double puntoMedioB(double a, double b){ return (b+a)/2; }

