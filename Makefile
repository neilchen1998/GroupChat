# compiler
CXX = g++

# preprocessors
CPPFLAGS = -I./interfaces -I./includes

# flags
CXXFLAGS = -pedantic -Wall -Wextra -ansi -std=c++20

# source directory
SRCS_DIR := src

# build directory
BUILD_DIR = build

# app directory
APP_DIR := app

# target binary
TARGET = $(BUILD_DIR)/group_chat

# source files
SRCS := $(wildcard $(SRCS_DIR)/*.cc)

# header files
HDRS := $(interfaces/*.hpp)
HDRS += $(includes/*.hpp)

# object files
# $(patsubst pattern,replacement,text)
# % is replaced by the text
OBJS = $(patsubst $(SRCS_DIR)/%.cc,$(BUILD_DIR)/objs/%.o,$(SRCS))

# default target
# NOTE: the build directory needs to be created
all : $(TARGET) $(BUILD_DIR)

# links object files to create the binary
# NOTE: the build directory needs to be created
$(TARGET) : $(BUILD_DIR)/objs/main.o $(OBJS) $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJS) $(BUILD_DIR)/objs/main.o

# compiles the app
$(BUILD_DIR)/objs/main.o: $(APP_DIR)/main.cc $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# compiles source files to object files
$(BUILD_DIR)/objs/%.o: $(SRCS_DIR)/%.cc $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)/objs

run: $(TARGET)
	@./$(TARGET)

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(OBJS) $(TARGET)
