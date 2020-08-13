main: graph.o  main.o
	g++ graph.o  main.o -o main

graph.o: graph.cpp graph.h
	g++ -c graph.cpp -o graph.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

.PHONY : clean
clean :
	rm *.o main

.PHONY : run
run:
	./main