SRC_DIR = ./src
OBJ_DIR = ./obj
OUT_DIR = ./
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -lSDL2main -lSDL2
CPPFLAGS :=
CXXFLAGS :=
CC := g++

$(OUT_DIR)/main.bin: $(OBJ_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<