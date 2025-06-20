build:
	g++ -std=c++20 main.cpp lib/*.cpp -o myapp

clean:
	rm -f myapp

run:
	./myapp
