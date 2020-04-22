CXX      := -g++
CXXFLAGS := -w -Wall -Wextra -Werror -pedantic-errors -fpermissive -pthread
LDFLAGS  := -L/usr/lib -lstdc++ -lm -lSDL2 -lSDL2_ttf -lSDL2_image
TARGET   := goodboy
INCLUDE  := -Iinclude/

BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/app
SRC      :=                  \
   $(wildcard src/system/util/*.cpp)  \
   $(wildcard src/system/*.cpp)  \
   $(wildcard src/*.cpp)         \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_BUILD    := ./build/test
TEST_OBJ_DIR  := $(TEST_BUILD)/objects
TEST_APP_DIR  := $(TEST_BUILD)/app
TEST_SRC      :=                  \
   $(wildcard src/system/*.cpp)   \
   $(wildcard test/system/*.cpp)  \
   $(wildcard test/*.cpp)         \

TEST_OBJECTS  := $(TEST_SRC:%.cpp=$(TEST_OBJ_DIR)/%.o)

# detect MacOS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	CXXFLAGS += -std=c++1z -fms-extensions -Wno-gnu-anonymous-struct -Wno-nested-anon-types -Wwritable-strings
endif

all: clean
all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

test: testclean
test: testbuild $(TEST_APP_DIR)/$(TARGET)

$(TEST_OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(TEST_APP_DIR)/$(TARGET): $(TEST_OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(TEST_APP_DIR)/$(TARGET) $^ $(LDFLAGS)

.PHONY: all build clean debug release test testbuild testclean

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -g
debug: clean
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

testclean:
	-@rm -rvf $(TEST_OBJ_DIR)/*
	-@rm -rvf $(TEST_APP_DIR)/*

testbuild:
	@mkdir -p $(TEST_APP_DIR)
	@mkdir -p $(TEST_OBJ_DIR)
