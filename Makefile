searchtest : searchtest.c Makefile
	gcc -Wall -O3 -fno-inline -o searchtest searchtest.c
