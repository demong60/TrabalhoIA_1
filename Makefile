output: Main.o Game.o Util.o
	g++ -Ofast Game.o Main.o Util.o -Wall -o out

Main.o: Main.cpp
	g++ -Ofast -c Main.cpp

Game.o: Game.cpp Game.h
	g++ -Ofast -c Game.cpp 

Util.o: Util.cpp Util.h
	g++ -Ofast -c Util.cpp

clean:
	rm *.o out