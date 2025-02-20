CC = gcc
CFLAGS = -Wall -Wextra -g -pedantic -std=c11
OBJ = template.o template.o
TARGET = template_test

# Default target
all: $(TARGET)

run: $(TARGET)
	./$(TARGET)



$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


template.o: template.c template.h
	$(CC) $(CFLAGS) -c template.c







clean:
	rm -f $(OBJ) $(OBJ_ll) $(TARGET)



rebuild: clean all
