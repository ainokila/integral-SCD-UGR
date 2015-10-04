#include <iostream>
#include "fun_tiempos.h"
using namespace std ;




	const unsigned long muestras = 1000000 ; // numero de muestras
	const unsigned long num_hebras = 4 ; // numero de hebras
	double resultado_parcial[num_hebras]={0} ; // vector de resultados parciales



	double f( double x ) {
		 return 4.0/(1+x*x) ; 

	}



	void * funcion_hebra( void * ih_void ) {

		unsigned long ih = (unsigned long) ih_void ; // Obtengo el indice de esta hebra
		double sumap = 0.0 ;

		// calcular suma parcial en ”sumap”
	   	  
		                                      // inicializar suma
		for( unsigned long i = ih ; i < muestras  ; i=i+num_hebras ){                         // para cada i entre 0 y m − 1
			sumap += f( (i+0.5)/muestras );                                      // a˜nadir f (xi) a la suma actual
			
		}                                                
		resultado_parcial[ih] = sumap/(muestras) ; // guardar suma parcial en vector.
		
	}



	double calcular_integral_concurrente(){

		double solucion = 0.0 ; 

	// creo  n hebras:
		pthread_t id_hebra[num_hebras] ;

	//Lanzo las hebras , con funcion_hebra pasandole el indice de hebra:

		for( unsigned long i = 0 ; i < num_hebras ; i++ ){ 

			void * arg_ptr = (void *) i ; // Convierto el indice en puntero
			pthread_create( &(id_hebra[i]), NULL, funcion_hebra, arg_ptr );
		}

	// esperar (join) a que termine cada hebra

		for( unsigned i = 0 ; i < num_hebras ; i++ ){
			 pthread_join( id_hebra[i],NULL ); 
		}

	//Sumo los resultados
	
		for( unsigned i = 0 ; i < num_hebras ; i++ ){
			 solucion += resultado_parcial[i];
			cout << resultado_parcial[i] << " " ;
		}



	// devolver resultado completo

		return solucion ; 




	}

	int main(){

		double valor = 0 ; 

		struct timespec inicio = ahora() ;
		valor = calcular_integral_concurrente();
		struct timespec fin = ahora() ;

		cout << "\n\n**********************************************************************\n";
		cout << "El valor de la integral es " << valor << "\n";
		cout << "tiempo transcurrido == " << duracion( &inicio, &fin ) << " seg." << endl ;
		cout << "**********************************************************************\n";

	/*

	PRIMEROS RESULTADOS DE EJECUCION :
 
		**********************************************************************
		El valor de la integral es 3.14159
		tiempo transcurrido == 0.00679615 seg.
		**********************************************************************

	*/

}
