#!/usr/bin/python

import timeit
import commands

def runbench (runs, search, n):
    commands.getstatusoutput ('./searchtest %d %s %d' % (runs, search, n))

def timebench (runs, search, n):
    return timeit.Timer ('runbench (%d, \'%s\', %d)' % (runs, search, n), "from __main__ import runbench").timeit (number = 1)

n = 16

for search in ['linear', 'linear_2', 'linear_4', 'linear_32', 'binary', 'binary_cmov', 'binary_cmov_lin1', 'binary_cmov_lin2', 'binary_cmov_lin4', 'binary_cmov_lin8', 'binary_cmov_lin16', 'binary_cmov_lin32']:
    #print 'Calibrating %s' % search
    runs = 1000000
    while timebench (runs, search, n) < 2.0:
        runs = runs * 2
    #print '%d runs' % runs
    for n in [1, 2, 4, 8, 16, 32, 64, 128]:
        for i in range (10):
            print '%s %d %d %f' % (search, runs, n, timebench (runs, search, n))
