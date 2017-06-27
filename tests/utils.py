#!/usr/bin/env python

def file_to_wordtab(filename):
    file_ = open(filename, "r")
    wt = []
    for line in file_:
        wt.append(list(line))
    return (wt)

def wordtab_to_str(wt):
    string = ""
    for lines in wt:
        for char in lines:
            string += char
    return string
