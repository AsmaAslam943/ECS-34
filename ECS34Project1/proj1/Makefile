BIN_DIR = bin #created the bin and object directories 
OBJ_DIR = obj
TARGET = $(BIN_DIR)/teststrutils

GTEST_FLAGS = -I/opt/homebrew/opt/googletest/include -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -pthread 
#created the google test pathway 
SRC = StringUtils.cpp StringUtilsTest.cpp #linked src to the cpp files 
OBJ = $(SRC:.cpp=.o) #object directory holds .o 

all: directories $(TARGET) runtests #ran runtests

StringUtils.o: /users/asmaaslam/ECS34Project1/proj1/include/StringUtils.h ./src/StringUtils.cpp #formed both StringUtils.o 
	g++ -c -std=c++17 -I /users/asmaaslam/ECS34Project1/proj1/include ./src/StringUtils.cpp 
StringUtilsTest.o: /users/asmaaslam/ECS34Project1/proj1/include/StringUtils.h ./testsrc/StringUtilsTest.cpp #and StringUtilsTest.o 
	g++ -c -std=c++17 -I /users/asmaaslam/ECS34Project1/proj1/include ./testsrc/StringUtilsTest.cpp $(GTEST_FLAGS)
$(TARGET): $(OBJ) #we set up a target point 
		g++ $(OBJ) -o $(TARGET) -std=c++17 $(GTEST_FLAGS) 

runtests: $(TARGET) #we ran make runtests 
		$(TARGET)

directories: #we made the directories 
		mkdir -p $(BIN_DIR)
		mkdir -p $(OBJ_DIR)

clean: #and we also made clean 
		rm -rf $(BIN_DIR)
		rm -rf $(OBJ_DIR)