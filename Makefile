# -*- Makefile -*-
a_calc: arb-calc.o Controler.o Viewer.o Command.o GB_math.o Model.o GreatBin.o GreatBinExp.o
	g++ -o a_calc arb-calc.o Controler.o Viewer.o Command.o GB_math.o Model.o GreatBin.o GreatBinExp.o
arb-calc.o: arb-calc.cpp
	g++ arb-calc.cpp -c
Controler.o: Controler.cpp
	g++ Controler.cpp -c
Viewer.o: Viewer.cpp
	g++ Viewer.cpp -c
Model.o: Model.cpp
	g++ Model.cpp -c
Command.o: Command.cpp
	g++ Command.cpp -c
GB_math.o: GB_lib/GB_math.cpp
	g++ GB_lib/GB_math.cpp -c
GreatBin.o: GB_lib/GreatBin.cpp
	g++ GB_lib/GreatBin.cpp -c
GreatBinExp.o: GB_lib/GreatBinExp.cpp
	g++ GB_lib/GreatBinExp.cpp -c
