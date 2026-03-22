CC = C:/gcc-15.2.0/bin/gcc.exe
CFLAGS = -Wall -Wextra -std=c11

TARGET = bubble_sort
SRC = bubble_sort.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET).exe $(TARGET)
