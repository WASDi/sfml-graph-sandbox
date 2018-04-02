LIBS=-lsfml-graphics -lsfml-window -lsfml-system
OUT=dist/Debug/GNU-Linux/testingsfml

all:
	@echo "** Building the game"
	g++ -c src/Vertex.cpp -o out/Vertex.o
	g++ -c src/main.cpp -o out/main.o
	g++ out/main.o out/Vertex.o -o $(OUT) $(LIBS)