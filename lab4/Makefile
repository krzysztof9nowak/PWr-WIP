CC=clang
CFLAGS=-Wextra -pedantic -std=c17 -g
LDFLAGS=-lm -g #-static -g

SRCS=$(wildcard *.c)
PROGS=$(basename $(SRCS))

all: $(PROGS)

analiza:
	@echo
	@echo "*****************************************"
	@echo "**  Analiza statyczna programem clang  **"
	@echo "*****************************************"
	@echo
	clang --analyze *.c

check:
	@echo
	@echo "********************************************"
	@echo "**  Analiza statyczna programem cppcheck  **"
	@echo "********************************************"
	@echo
	cppcheck --enable=all --std=c11 *.c

clean:
	rm -f $(PROGS) *.o *.plist *~