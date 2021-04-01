all:
	clang -I. -I kremlib/dist/minimal -Wall -Wextra *.c && ./a.out
ccomp:
	rm -rf mike.c
	cat *.c > mike.c
clean:
	rm -rf *.o *.out mike.*
