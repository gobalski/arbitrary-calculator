# -*- Makefile -*-
a_calc: arb-calc.o Controler.o Viewer.o
	g++ -o a_calc arb-calc.o Controler.o Viewer.o
arb-calc.o: arb-calc.cpp
	g++ arb-calc.cpp -c
Controler.o: Controler.cpp
	g++ Controler.cpp -c
Viewer.o: Viewer.cpp
	g++ Viewer.cpp -c