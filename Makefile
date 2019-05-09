movie.gif: intento.dat graficador.py
	python -W ignore graficador.py

intento.dat : a.out
	./a.out

a.out: SantiagoBeltran_Ejercicio30.cpp
	g++ SantiagoBeltran_Ejercicio30.cpp
    
clean:
	rm -rf *.out *.dat *.png *.gif
