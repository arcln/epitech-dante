#!/usr/bin/env python

import sys

global log

class TestAssertion:

    @staticmethod
    def Assert(condition, message):
        global log
        if condition:
            if len(log) > 200 * 200:
                log = "Maze too big..."
            print >> sys.stderr, log + message + "\n"
            sys.exit(1)
        return condition
