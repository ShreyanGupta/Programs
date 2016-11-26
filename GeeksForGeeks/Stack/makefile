out : Stack.o Stack_test.o Test.o
	g++ -std=c++11 -g -o out Stack.o Stack_test.o Test.o

Stack.o : Stack.cpp
	g++ -std=c++11 -c -g Stack.cpp

Stack_test.o : Stack_test.cpp
	g++ -std=c++11 -c -g Stack_test.cpp

Test.o : Test.cpp
	g++ -std=c++11 -c -g Test.cpp

clean :
	rm -rf *.o

run : out
	./out