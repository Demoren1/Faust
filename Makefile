all : Faust_faust

Faust_faust : input_output.o Reader.o Strcmp.o 
	g++ input_output.o Reader.o Strcmp.o -o Faust_faust
input_output.o : input_output.cpp
	g++ input_output.cpp -c
Reader.o : Reader.cpp
	g++ Reader.cpp -c
Strcmp.o : Strcmp.cpp
	g++ Strcmp.cpp -c

clean:
	rm -rf *.o Faust_faust

