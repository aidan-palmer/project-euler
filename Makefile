CC = g++
FLAGS = -g -Wall -Wextra -Wunused-variable -Wuninitialized
TARGET = Main

# Use "export SRC=program.cc" to set source file in environment,
# then simply enter "make" to compile and run the program.

$(TARGET): $(SRC)
	$(CC) $(FLAGS) -o $(TARGET) $(SRC)
	./Main

clean:
	rm -f $(TARGET)