all: stack test
	./test >temp.txt
	./stack

stack: Stack-A.o StackA-Try.o
	g++ -o stack Stack-A.o StackA-Try.o

test: Stack-A.o Test.o StackTest.o
	g++ -o test Stack-A.o Test.o StackTest.o

Stack-A.o: Stack-A.cpp
	g++ -c Stack-A.cpp

StackA-Try.o: StackA-Try.cpp
	g++ -c StackA-Try.cpp

Test.o: Test.cpp
	g++ -c Test.cpp

StackTest.o: StackTest.cpp
	g++ -c StackTest.cpp

clean:
	rm -rf *.o stack test temp.txt