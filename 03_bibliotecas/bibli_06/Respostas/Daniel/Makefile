CC = gcc
CFLAGS = -Wall
DEPS = main.h temperature_conversor.h
OBJ = main.o temperature_conversor.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

principal: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

clean: 
	rm -rf *.o principal

run:
	./principal
