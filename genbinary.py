#!/usr/bin/python

def gen (lower, upper, eq):
    assert lower <= upper;
    if lower == upper:
        if eq:
            print "if (key != KEY (%d)) goto failure;" % lower
        print "RETURN (%d);" % lower
    else:
        middle = (lower + upper) / 2
        print "if (key <= KEY (%d)) {" % middle
        gen (lower, middle, eq)
        print "} else {"
        gen (middle + 1, upper, eq)
        print "}"

for n in range (129):
    print "static int GEN_NAME (binary_static_unrolled, %d) (const int *arr, int n, int key) {" % n
    gen (0, n, False)
    print "assert (0);"
    print "return -1;"
    print "}"

for n in range (129):
    print "static int GEN_NAME (binary_static_unrolled_eq, %d) (const int *arr, int n, int key) {" % n
    gen (0, n, True)
    print "failure:"
    print "assert (0);"
    print "return -1;"
    print "}"
