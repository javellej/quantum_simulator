CXX      	 := -g++
CXXFLAGS 	 := -Wall -Wextra -Werror -Wno-psabi
LDFLAGS  	 := -L/usr/lib -lstdc++
BUILD        := ./build
OBJ_DIR      := $(BUILD)/objects
TARGET 		 := run_sim
TEST   	     := unit
INCLUDE 	 := -Imain/simulator/ -Iexternal/
SRC_MAIN     := main/main.cpp
SRC          := $(wildcard main/simulator/*.cpp)
SRC_TEST     := $(wildcard unit/*.cpp)

OBJECT_MAIN  := $(SRC_MAIN:%.cpp=$(OBJ_DIR)/%.o)
OBJECTS      := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJECTS_TEST := $(SRC_TEST:%.cpp=$(OBJ_DIR)/%.o)

all: build $(BUILD)/$(TARGET) $(BUILD)/$(TEST)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(BUILD)/$(TARGET): $(OBJECT_MAIN) $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(BUILD)/$(TARGET) $(OBJECT_MAIN) $(OBJECTS)

$(BUILD)/$(TEST): $(OBJECTS_TEST)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(BUILD)/$(TEST) $(OBJECTS) $(OBJECTS_TEST)

.PHONY: all build clean debug release

build:
	@mkdir -p $(BUILD)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2 -flto
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(BUILD)/*
