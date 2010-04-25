#!/usr/bin/python

import timeit
import commands
import sys

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

for search in ['linear', 'linear_2', 'linear_4', 'linear_42', 'linear_84', 'binary', 'binary_cmov', 'binary_cmov_unrolled', 'binary_cmov_unrolled_linear', 'linear_sentinel', 'linear_sentinel_2', 'linear_sentinel_4', 'linear_sentinel_8', 'linear_sentinel_16', 'linear_sentinel_32', 'binary_cmov_lin1', 'binary_cmov_lin2', 'binary_cmov_lin4', 'binary_cmov_lin8', 'binary_cmov_lin16', 'binary_cmov_lin32']:
    for n in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536]:
        timesearch (search, n, 10)
