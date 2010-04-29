searchtest : searchtest.c linear.h linear-loop.h linear-sentinel.h linear-sentinel-loop.h linear-sentinel-preload-loop.h linear-sentinel-simd.h binary.h binary-step.h binary-unrolled.h Makefile
	gcc -Wall -msse2 -flax-vector-conversions -O2 -fno-inline -o searchtest searchtest.c
