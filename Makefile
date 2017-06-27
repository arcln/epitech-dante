##
## Makefile for dante in /home/onehandedpenguin/Dev/IA_2016/dante/
##
## Made by Paul Laffitte
## Login   <paul.laffitte@epitech.eu>
##
## Started on  Wed Apr 12 00:14:48 2017 Paul Laffitte
## Last update Sun May 14 17:29:28 2017 Arthur Chaloin
##

all:
		make -C ./lib/vector/
		make -C ./astar/
		make -C ./breadth/
		make -C ./depth/
		make -C ./generator/
		make -C ./tournament/

clean:
		make clean -C ./lib/vector/
		make clean -C ./astar/
		make clean -C ./breadth/
		make clean -C ./depth/
		make clean -C ./generator/
		make clean -C ./tournament/

fclean:
		make fclean -C ./lib/vector/
		make fclean -C ./astar/
		make fclean -C ./breadth/
		make fclean -C ./depth/
		make fclean -C ./generator/
		make fclean -C ./tournament/

re:
		make re -C ./lib/vector/
		make re -C ./astar/
		make re -C ./breadth/
		make re -C ./depth/
		make re -C ./generator/
		make re -C ./tournament/

debug:
		make debug -C ./lib/vector/
		make debug -C ./astar/
		make debug -C ./breadth/
		make debug -C ./depth/
		make debug -C ./generator/
		make debug -C ./tournament/

bonus:
		make re -C ./lib/vector/
		make re -C ./astar/
		make re -C ./breadth/
		make re -C ./depth/
		make re -C ./generator/
		make re -C ./tournament/
		make re -C ./bonus/

.PHONY:	all clean fclean re debug bonus
