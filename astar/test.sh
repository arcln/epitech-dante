while [ 1 ]
do
    ../generator/generator $1 $2 > ../mazes/maze_tmp.mz
    ./solver ../mazes/maze_tmp.mz > .soluce
    (cat .soluce | grep "o" && echo "\nSolution find !") || cat .soluce
    echo "\n"
    rm .soluce
    sleep 1
done
