# -*- Makefile -*-
a_calc: arb-calc.o Controler.o Viewer.o Command.o GreatBin.o
	g++ -o a_calc arb-calc.o Controler.o Viewer.o Command.o GreatBin.o
arb-calc.o: arb-calc.cpp
	g++ arb-calc.cpp -c
Controler.o: Controler.cpp
	g++ Controler.cpp -c
Viewer.o: Viewer.cpp
	g++ Viewer.cpp -c
Command.o: Command.cpp
	g++ Command.cpp -c
GreatBin.o: GB_lib/GreatBin.cpp
	g++ GB_lib/GreatBin.cpp -c
