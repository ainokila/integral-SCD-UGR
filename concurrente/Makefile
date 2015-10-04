## ---------------------------------------------------------------------
## SCD. Makefile para la integral.
## ---------------------------------------------------------------------

.PHONY: 1, 2, 3, pi, msg, clean, todo
.SUFFIXES:

params_comp:= -c -g -Wall -I. 
libs:=        -lpthread -lrt  

## ---------------------------------------------------------------------

integral: integral	
	./integral

integral: integral.o fun_tiempos.o
	g++ -o integral integral.o fun_tiempos.o $(libs)

integral.o: integral.cpp fun_tiempos.h
	g++ $(params_comp) -o integral.o integral.cpp

fun_tiempos.o: fun_tiempos.c fun_tiempos.h
	g++ $(params_comp) -o fun_tiempos.o fun_tiempos.c

clean:
	rm -rf *.o integral
