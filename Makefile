LIBS=-lsfml-graphics -lsfml-window -lsfml-system
OUT=dist/Debug/GNU-Linux/graphsandbox

SRC_DIR := src
OBJ_DIR := out
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: compile_all_the_things
	
compile_all_the_things: $(OBJ_FILES)
	g++ $(OBJ_FILES) -o $(OUT) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -c $< -o $@
	
how_i_compiled_before_learning_make:
	@echo "** Building all the things"
	g++ -c src/Vertex.cpp -o out/Vertex.o
	g++ -c src/Edge.cpp -o out/Edge.o
	g++ -c src/Util.cpp -o out/Util.o
	g++ -c src/main.cpp -o out/main.o
	g++ out/* -o $(OUT) $(LIBS)
