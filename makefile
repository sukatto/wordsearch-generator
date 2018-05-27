all: wsgen

wsgen: main.cpp
	g++ main.cpp -o wsgen

clean:
	rm wsgen
