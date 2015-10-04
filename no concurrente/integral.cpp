#include <iostream>
#include "fun_tiempos.h"
using namespace std ;





	unsigned long m = 1000000 ; // n´umero de muestras

	double f( double x ) { 
	
		return 4.0/(1+x*x) ; // f (x) = 4/(1 + x2)
	}

	double calcular_integral_secuencial( ){
	 
		double suma = 0.0 ; // inicializar suma

		for( unsigned long i = 0 ; i < m ; i++ ) // para cada i entre 0 y m − 1
			suma += f( (i+0.5)/m ); // a˜nadir f (xi) a la suma actual
		return suma/m ; // devolver valor promedio de f
	}

int main(){

	double valor = 0 ; 

	struct timespec inicio = ahora() ;
	valor = calcular_integral_secuencial();
	struct timespec fin = ahora() ;


	cout << "\n\n**********************************************************************\n";
	cout << "El valor de la integral es " << valor << "\n";
	cout << "tiempo transcurrido == " << duracion( &inicio, &fin ) << " seg." << endl ;
	cout << "**********************************************************************\n";

	/*

	PRIMEROS RESULTADOS DE EJECUCION : 
		El valor de la integral es 3.1416
		tiempo transcurrido == 6.648e-06 seg.
	*/

}
