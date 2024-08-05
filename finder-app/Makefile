# Makefile for building the writer application

# Compiler and tools
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra -Werror

# Targets and files
TARGET := writer
OBJECTS := writer.o

# Default target
all: $(TARGET)

# Build the writer application
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -f $(TARGET) $(OBJECTS)

# Phony targets
.PHONY: all clean

