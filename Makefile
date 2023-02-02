List: main.o LinkedList.o
	g++ main.o LinkedList.o -o List

main.o: main.cpp
	g++ -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Node.h
	g++ -c LinkedList.cpp

clean:
	rm *.o List