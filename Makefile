CC = gcc
CFLAGS = -Wall
TARGET = biblioteca
SRCS = autor.c emprestimo.c menu.c usuario.c main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f ($TARGET)