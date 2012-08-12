#!/usr/bin/python

import timeit
import commands
import sys
import re
from optparse import OptionParser

def runbench (compiler, runs, search, n):
    commands.getstatusoutput ('./searchtest.%s %d %s %d' % (compiler, runs, search, n))

def timebench (compiler, runs, search, n):
    return timeit.Timer ('runbench (\'%s\', %d, \'%s\', %d)' % (compiler, runs, search, n), "from __main__ import runbench").timeit (number = 1)

def timesearch (compiler, search, n, num_repeats):
    #print 'Calibrating %s' % search
    runs = 10000
    while timebench (compiler, runs, search, n) < 2.0:
        runs = runs * 2
    #print '%d runs' % runs
    for i in range (num_repeats):
        print '%s %d %d %f' % (search, runs, n, timebench (compiler, runs, search, n))
        sys.stdout.flush ()

parser = OptionParser ()
parser.add_option ("-e", "--exclude", action = "store_true", dest = "exclude", help = "Exclude based on given regular expressions")
parser.add_option ("-c", "--compiler", dest = "compiler", default = "gcc", help = "choose compiler", metavar = "COMPILER")
(options, cmdline_args) = parser.parse_args()

searches = commands.getoutput ('./searchtest.%s --list' % options.compiler).split ()
filters = cmdline_args
if len (filters) > 0:
    if options.exclude:
        searches = [s for s in searches if not any (re.search (f, s) for f in filters)]
    else:
        searches = [s for s in searches if any (re.match (f + "$", s) for f in filters)]

for search in searches:
    for n in [1, 2, 3, 4, 5, 6, 7]: #, 8, 16, 32, 64]: #[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536]:
        timesearch (options.compiler, search, n, 10)
