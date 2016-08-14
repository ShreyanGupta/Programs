out : main.o Connect4.o
	g++ main.o Connect4.o -o out

main.o : main.cpp Connect4.h
	g++ -c main.cpp

Connect4.o : Connect4.cpp Connect4.h
	g++ -c Connect4.cpp

clean :
	rm *.o

run : out
	./out