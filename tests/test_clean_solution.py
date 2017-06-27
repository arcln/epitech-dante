#!/usr/bin/env python

import assertions
from utils import *

def check_solution_is_not_clean(char):
    assertions.TestAssertion.Assert(char == 'o',
    "The solution have at least one 'o' character outside of the path")

def test_clean_solution(solved_maze):
    for line in solved_maze:
        for char in line:
            check_solution_is_not_clean(char)
