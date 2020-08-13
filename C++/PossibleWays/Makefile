main: countOfPossibleWayBuilding.o  main.o
	g++ countOfPossibleWayBuilding.o  main.o -o main

graph.o: countOfPossibleWayBuilding.cpp countOfPossibleWayBuilding.h
	g++ -c countOfPossibleWayBuilding.cpp -o countOfPossibleWayBuilding.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

.PHONY : clean
clean :
	rm *.o main

.PHONY : run
run:
	./main