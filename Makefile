all : Faust_faust

CFLAGS=-Wall

Faust_faust : input_output.o Reader.o Strcmp.o MySort.o 
	g++ $(CFLAGS) input_output.o Reader.o Strcmp.o MySort.o -o Faust_faust
input_output.o : input_output.cpp
	g++ input_output.cpp -c
Reader.o : Reader.cpp
	g++ Reader.cpp -c
Strcmp.o : Strcmp.cpp
	g++ Strcmp.cpp -c
MySort.o : MySort.cpp
	g++ MySort.cpp -c

clean:
	rm -rf *.o Faust_faust

