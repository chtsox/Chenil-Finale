#Makefile

CC=gcc
SRC=src/main.c src/animal.c src/fichier.c src/outils.c
OBJ=$(SRC:.c=.o)
EXEC=chenil

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

clean:
	rm -f src/*.o $(EXEC)
