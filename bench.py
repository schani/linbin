#!/usr/bin/python

import timeit
import commands
import sys
import re

def some (pred, list):
    for x in list:
        res = pred (x)
        if res:
            return res
    return False

def runbench (runs, search, n):
    commands.getstatusoutput ('./searchtest %d %s %d' % (runs, search, n))

def timebench (runs, search, n):
    return timeit.Timer ('runbench (%d, \'%s\', %d)' % (runs, search, n), "from __main__ import runbench").timeit (number = 1)

def timesearch (search, n, num_repeats):
    #print 'Calibrating %s' % search
    runs = 10000
    while timebench (runs, search, n) < 2.0:
        runs = runs * 2
    #print '%d runs' % runs
    for i in range (num_repeats):
        print '%s %d %d %f' % (search, runs, n, timebench (runs, search, n))
        sys.stdout.flush ()

searches = commands.getoutput ('./searchtest --list').split ()
filters = sys.argv [1:]
if len (filters) > 0:
    searches = [s for s in searches if some (lambda f: re.match (f + "$", s), filters)]

for search in searches:
    for n in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536]:
        timesearch (search, n, 10)
