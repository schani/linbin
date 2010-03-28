searchtest : searchtest.c linear.h binary.h binary-step.h binary-unrolled.h Makefile
	gcc -Wall -O2 -fno-inline -o searchtest searchtest.c
