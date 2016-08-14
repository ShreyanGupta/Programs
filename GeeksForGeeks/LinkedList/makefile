out : LL_Test.o LinkedList.o Test.o
	g++ LL_Test.o LinkedList.o Test.o -o out

LL_Test.o : LL_Test.cpp
	g++ -c LL_Test.cpp

LinkedList.o : LinkedList.cpp
	g++ -c LinkedList.cpp

Test.o : Test.cpp
	g++ -c Test.cpp

run : out
	./out

clean :
	rm -rf *.o