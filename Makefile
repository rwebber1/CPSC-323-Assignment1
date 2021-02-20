all: main.o
	g++ main.o -o main
	rm main.o

main.o:
	g++ -c main.cpp -o main.o

clean:
	rm main
