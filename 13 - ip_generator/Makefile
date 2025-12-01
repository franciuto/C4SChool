# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS = 

# Target executable
TARGET = ip_generator

# Source files
SRCS = main.c ip_generator.c ip_utils.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Header files (for dependencies)
HEADERS = ip_utils.h ip_generator.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets (not actual files)
.PHONY: all clean rebuild run
