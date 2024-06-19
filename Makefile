CC = clang
PROJ_NAME = huff
C_SOURCE = $(wildcard *.c)
H_SOURCE = $(wildcard *.h)
OBJ = $(C_SOURCE:.c = .o)

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $(PROJ_NAME) $(OBJ)

%.o: %.c %.h
	$(CC) -o $*.o $*.c

main.o: main.c $(H_SOURCE)
	$(CC) -o main.o main.c

clean:
	rm -rf *.o $(PROJ_NAME) *~