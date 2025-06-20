build:
	g++ -std=c++20 main.cpp lib/*.cpp -o myapp -Wall

clean:
	rm -f myapp

run:
	./myapp
