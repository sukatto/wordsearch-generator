all: wsgen
	mkdir puzzles/

wsgen: main.cpp
	g++ main.cpp -o wsgen

clean:
	rm wsgen
	rm -r puzzles/
