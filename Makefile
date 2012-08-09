DEPS = searchtest.c linear.h linear-loop.h linear-sentinel.h linear-sentinel-loop.h linear-sentinel-preload-loop.h linear-sentinel-simd.h binary.h binary-step.h binary-unrolled.h linear-static-unrolled.h linear-static-unrolled-eq.h returns.c returns.h binary-static-unrolled.h Makefile

all : searchtest.gcc searchtest.llvm

searchtest.gcc : $(DEPS)
	gcc -Wall -msse2 -flax-vector-conversions -O2 -fno-inline -o searchtest.gcc searchtest.c returns.c

searchtest.llvm : $(DEPS)
	clang -DNAME_POSTFIX='"llvm"' -Wall -msse2 -flax-vector-conversions -O2 -fno-inline -o searchtest.llvm searchtest.c returns.c

linear-static-unrolled.h : genstatic.py
	./genstatic.py >linear-static-unrolled.h

linear-static-unrolled-eq.h : genstatic-eq.py
	./genstatic-eq.py >linear-static-unrolled-eq.h

returns.c returns.h : genreturns.py
	./genreturns.py

binary-static-unrolled.h : genbinary.py
	./genbinary.py >binary-static-unrolled.h
