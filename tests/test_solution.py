#!/usr/bin/env python

import sys, random, assertions
from utils import *

def append_choice(solved_maze, positions, x, y, condition):
    if condition and solved_maze[y][x] == 'o':
        positions.append([x, y])
    return (positions)

def choose_next(solved_maze, x, y, width, height, have_solution):

    positions = []
    tmp = x - 1
    positions = append_choice(solved_maze, positions, tmp, y, tmp >= 0)
    tmp = x + 1
    positions = append_choice(solved_maze, positions, tmp, y, tmp < width)
    tmp = y - 1
    positions = append_choice(solved_maze, positions, x, tmp, tmp >= 0)
    tmp = y + 1
    positions = append_choice(solved_maze, positions, x, tmp, tmp < height)
    if have_solution:
        check_solution_not_found(len(positions) == 0)
    else:
        return [width - 1, height - 1]
    return (random.choice(positions))

def check_solution_not_found(condition):
    assertions.TestAssertion.Assert(condition,
    "The solution wasn't found whereas the maze have one")

def test_solution(solved_maze, have_solution):
    check_solution_not_found(have_solution == True and solved_maze[0][0] != 'o')
    width = len(solved_maze[0]) - 1
    height = len(solved_maze)
    x = 0
    y = 0
    solved_maze[y][x] = '!'
    while x != width - 1 or y != height - 1:
        next_pos = choose_next(solved_maze, x, y, width, height, have_solution)
        x = next_pos[0]
        y = next_pos[1]
        solved_maze[y][x] = '!'
    solved_maze[height - 1][width - 1] = '!'
    return (solved_maze)
