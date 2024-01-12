# Makefile for my_program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall


# Source files
SRCS = main.cpp \
       src/DAG.cpp \
       src/Scheduler.cpp \
       src/SchedulingUtils.cpp \
       src/TopologicalSort.cpp

# Include directories
INC = -Iinclude

# Executable
TARGET = my_program

# Build directory
BUILD_DIR = bin

# Create bin directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# Link
$(BUILD_DIR)/$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$(TARGET) $(SRCS) $(INC)

# Clean
clean:
	rm -rf $(BUILD_DIR)

# Default target
all: $(BUILD_DIR)/$(TARGET)

.PHONY: all clean
