#!/usr/bin/python

f = open ('returns.h', 'w')
for i in range (1025):
    f.write ("extern int return_%d (void);\n" % i)
f.close ()

f = open ('returns.c', 'w')
for i in range (1025):
    f.write ("int return_%d (void) { return %d; }\n" % (i, i))
f.close ()
