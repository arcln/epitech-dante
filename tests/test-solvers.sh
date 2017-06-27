#!/bin/bash

test_passed()
{
    echo -n "0"
    echo ":$2:dante.$1"
}

test_failed()
{
    echo -n "1"
    echo ":$2:dante.$1"
}

test_crashed()
{
    echo -n "2"
    echo ":$2:dante.$1"
}

add_trace_header()
{
    echo "$1" >> trace.txt
}

add_trace()
{
    echo "$1" >> .trace_tmp
}

test_solver()
{
    solver="$1"
    maze="$2"
    solver_path="$3"
    maze_kind="$4"

    timeout="3s"
    if [ $maze = "maze2.mz" ]
    then
	timeout="20s"
    fi
    valgrind --log-file=.valgrind ./$solver_path$solver/solver ../mazes/$maze_kind"_mazes"/$maze > .output_$solver & sleep $timeout ; kill $! > /dev/null 2>&1
    crash_return=$?
    grep "SIGSEGV" .valgrind > /dev/null 2>&1
    has_sigsegv=$?
    if [ $crash_return = 0 ]
    then
        test_crashed $solver $maze
        add_trace "$solver timed out on $maze after $timeout seconds (with valgrind)"
        return 1
    fi
    if [ $has_sigsegv = 0 ]
    then
        test_crashed $solver $maze
        add_trace "$solver sigsegv on $maze"
        return 1
    fi

    ./check_result.py ../mazes/$maze_kind"_mazes"/$maze .output_$solver $maze_kind 2> .tmp
    check_return=$?
    if [ $check_return = 1 ]
    then
        add_trace "$solver $maze: `cat .tmp`"
        test_failed $solver $maze
        return 1
    else
        if [ $check_return = -1 ]
        then
            echo >&2 "check_result.py had an internal error"
            return -1
        fi
        test_passed $solver $maze
    fi
    rm -f .output_$solver
    return 0
}

start_tests()
{
    solver_path=$1
    maze_kind=$2
    solvers=$3
    add_trace_header "Tests results for $maze_kind mazes:"
    add_trace "Tests logs for $maze_kind mazes:"
    for solver in "${solvers[@]}"
    do
        solver_ratio=0
        for maze in `ls ../mazes/$maze_kind"_mazes"`
        do
            test_solver $solver $maze $solver_path $maze_kind
            test_status=$?
            if [ $test_status = 0 ]
            then
                solver_ratio=$(($solver_ratio+1))
            elif [ $test_status = -1 ]
            then
                echo >&2 "Aborting tests"
                return -1
            fi
        done
        add_trace_header "$solver: $solver_ratio / `ls ../mazes/$maze_kind"_mazes" | wc -w`"
    done
    add_trace_header ""
    add_trace ""
    return 0
}

rm -f trace.txt
rm -f .trace_tmp

solver_path="../"
if [ $# = 1 ] && [ $1 = "--server" ]
then
    solver_path="./"
fi

solvers=("astar" "breadth" "depth")

start_tests "$solver_path" "broken"   $solvers
start_tests "$solver_path" "solvable" $solvers
cat .trace_tmp >> trace.txt

rm -f .trace_tmp
rm -f .valgrind
rm -f .tmp
