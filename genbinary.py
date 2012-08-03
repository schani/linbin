#!/usr/bin/python

def gen (lower, upper):
    assert lower <= upper;
    if lower == upper:
        print "RETURN (%d);" % lower
    else:
        middle = (lower + upper) / 2
        print "if (key <= KEY (%d)) {" % middle
        gen (lower, middle)
        print "} else {"
        gen (middle + 1, upper)
        print "}"

for n in range (129):
    print "static int GEN_NAME (binary_static_unrolled, %d) (const int *arr, int n, int key) {" % n
    gen (0, n)
    print "assert (0);"
    print "return -1;"
    print "}"
