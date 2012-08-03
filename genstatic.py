#!/usr/bin/python

for i in range (1025):
    print "if (__builtin_expect (!!(key <= KEY (%d)), 0)) RETURN (%d);" % (i, i)
