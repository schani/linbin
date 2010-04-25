searchtest : searchtest.c linear.h linear-loop.h linear-sentinel.h linear-sentinel-loop.h binary.h binary-step.h binary-unrolled.h Makefile
	gcc -Wall -O2 -fno-inline -o searchtest searchtest.c
