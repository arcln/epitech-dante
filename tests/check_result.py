#!/usr/bin/env python

import sys, assertions
from utils import *
from test_clean_solution import *
from test_solution import *
from test_valid_solution import *

if __name__ == '__main__':
    argc = len(sys.argv) - 1
    argv = sys.argv
    if argc != 3:
        print "Usage: ./" + argv[0] + " maze solved_maze broken_maze"
        sys.exit(-1)
    is_solvable = argv[3] != "broken"
    solved_maze = file_to_wordtab(argv[2])
    assertions.log = ""
    test_valid_solution(file_to_wordtab(argv[1]), solved_maze, is_solvable)
    assertions.log = wordtab_to_str(test_solution(solved_maze, is_solvable)) + "\n"
    test_clean_solution(solved_maze)
