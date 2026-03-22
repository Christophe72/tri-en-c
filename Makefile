CC = C:/gcc-15.2.0/bin/gcc.exe
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

TARGET = bubble_sort
SRC = src/main.c src/bubble_sort.c src/saisie.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET).exe $(TARGET)
