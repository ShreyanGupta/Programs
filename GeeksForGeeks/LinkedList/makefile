out : LL_Test.o LinkedList.o Test.o
	g++ -g LL_Test.o LinkedList.o Test.o -o out

LL_Test.o : LL_Test.cpp
	g++ -g -c LL_Test.cpp

LinkedList.o : LinkedList.cpp
	g++ -g -c LinkedList.cpp

Test.o : Test.cpp
	g++ -g -c Test.cpp

run : out
	./out

clean :
	rm -rf *.o