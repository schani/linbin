#!/usr/bin/python

import sys
import matplotlib.pyplot as plt
import math
from optparse import OptionParser

def linear (x):
    return x

def log2 (x):
    return math.log (x, 2)

def log10 (x):
    return math.log (x, 10)

parser = OptionParser ()
parser.add_option ("-l", "--linear-x", action = "store_true", dest = "linear_x", help = "Use a linear, not a logarithmic x-axis")
parser.add_option ("-L", "--log-y", action = "store_true", dest = "log_y", help = "Use a logarithmic, not a linear y-axis")
parser.add_option ("-m", "--min", dest = "min", help = "Minimum N")
parser.add_option ("-M", "--max", dest = "max", help = "Maximum N")
parser.add_option ("-e", "--error-bars", action = "store_true", dest = "error_bars", help = "Draw error bars")
(options, cmdline_args) = parser.parse_args()

if options.linear_x:
    scale_x = linear
else:
    scale_x = log2

if options.log_y:
    scale_y = log10
else:
    scale_y = linear

if options.error_bars:
    error_bars = True
else:
    error_bars = False

if len (cmdline_args) == 0:
    search_set = set (["all"])
else:
    search_set = set (cmdline_args)

def show_search (s):
    if "all" in search_set:
        return True
    return s in search_set

def show_n (n):
    if options.min and n < int (options.min):
        return False
    if options.max and n > int (options.max):
        return False
    return True

table = {}

for line in sys.stdin.readlines ():
    [search, runs, n, time] = line.split ()
    [runs, n, time] = [int (runs), int (n), float (time)]
    if show_search (search) and show_n (n):
        if search not in table:
            table [search] = {}
        if n not in table [search]:
            table [search] [n] = []
        table [search] [n].append (time / runs)

plots = []
searches = table.keys ()
for search in searches:
    xs = []
    ys = []
    yerrs = []
    ns = table [search].keys ()
    ns.sort ()
    for n in ns:
        xs.append (scale_x (n))
        times = table [search] [n]
        times.sort ()
        times = times [2 : -2]
        avg = sum (times) / len (times)
        ys.append (scale_y (avg))
        yerrs.append (scale_y (times [-1]) - scale_y (avg))
    if error_bars:
        plots.append (plt.errorbar (xs, ys, yerrs) [0])
    else:
        plots.append (plt.plot (xs, ys))
plt.legend (plots, searches, loc = "upper left")
plt.show ()
