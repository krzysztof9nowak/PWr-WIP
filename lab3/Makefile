CC=clang
CFLAGS=-Wextra -pedantic -std=c17 #-g
LDFLAGS=-lm #-g

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, build/%.o, ${SRC}}
DEPS = ${wildcard *.h}

build/%.o: %.c $(DEPS)
	mkdir -p build
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf build main