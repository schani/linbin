searchtest : searchtest.c Makefile
	gcc -Wall -O2 -fno-inline -o searchtest searchtest.c
