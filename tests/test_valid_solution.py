#!/usr/bin/env python

import sys, assertions
from utils import *

def check_height(maze, solved_maze):
    len_maze = len(maze)
    len_solved_maze = len(solved_maze)
    assertions.TestAssertion.Assert(len_maze != len_solved_maze,
    "The solution and the maze don't have the same height. Maze: " + str(len_maze) + " Solution: " + str(len_solved_maze))

def check_width(line, solved_line):
    len_line = len(line)
    len_solved_line = len(solved_line)
    assertions.TestAssertion.Assert(len_line != len_solved_line,
    "The solution and the maze don't have the same width. Maze:" + str(len_line) + " Solution: " + str(len_solved_line))

def check_wall_removed(char, solved_char):
    assertions.TestAssertion.Assert(char == 'X' and solved_char != 'X',
    "A wall was removed in the solution")

def check_wall_added(char, solved_char):
    assertions.TestAssertion.Assert(solved_char == 'X' and char != 'X',
    "A wall was added in the solution")

def check_unknow_character(char, solved_char):
    assertions.TestAssertion.Assert(solved_char != 'X' and solved_char != '.' and solved_char != 'o' and solved_char != char,
    "Unknown character in the solution : '" + solved_char + "'")

def check_no_solution(solved_maze):
    output = wordtab_to_str(solved_maze)
    if not assertions.TestAssertion.Assert(output != "no solution found\n",
           "Was expected: 'no solution found\\n'"):
       sys.exit(0)

def check_solution(solved_maze):
    output = wordtab_to_str(solved_maze)
    assertions.TestAssertion.Assert(output == "no solution found\n",
    "Solver didn't find the solution")


def test_valid_solution(maze, solved_maze, is_solvable):
    if is_solvable:
        check_solution(solved_maze)
        check_height(maze, solved_maze)
        if len(maze) != 0:
            check_width(maze[0], solved_maze[0])
        for line, solved_line in zip(maze, solved_maze):
            for char, solved_char in zip(line, solved_line):
                check_wall_removed(char, solved_char)
                check_wall_added(char, solved_char)
                check_unknow_character(char, solved_char)
                check_wall_added(char, solved_char)
                check_unknow_character(char, solved_char)
    else:
        check_no_solution(solved_maze)
