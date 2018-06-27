hw2partb : main.o board.o organism.o ant.o doodlebug.o
	g++ -o hw2partb main.o board.o organism.o ant.o doodlebug.o
main.o : main.cpp
	g++ -c main.cpp
board.o : board.cpp board.h
	g++ -c -std=c++11 board.cpp
organism.o : organism.cpp organism.h
	g++ -c organism.cpp
ant.o : ant.cpp ant.h
	g++ -c ant.cpp
doodlebug.o : doodlebug.cpp doodlebug.h
	g++ -c doodlebug.cpp
clean:
	rm -f core hw2partb main.o board.o organism.o ant.o doodlebug.o