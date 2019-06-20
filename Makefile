
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17
CPP = g++


main : Makefile   csci152_student.o main.o
	$(CPP) $(Flags) -o main   csci152_student.o main.o

csci152_student.o : Makefile   csci152_student.cpp   csci152_student.h
	$(CPP) -c $(Flags) csci152_student.cpp -o  csci152_student.o


main.o : Makefile   main.cpp   csci152_student.h
	$(CPP) -c $(Flags) main.cpp -o  main.o
	