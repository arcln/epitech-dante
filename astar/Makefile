##
## Makefile for dante in /home/onehandedpenguin/Dev/AI_2016/dante/astar/
##
## Made by Paul Laffitte
## Login   <paul.laffitte@epitech.eu>
##
## Started on  Wed Apr 12 20:07:27 2017 Paul Laffitte
## Last update Thu May  4 21:54:40 2017 Paul Laffitte
##

NAME		=	solver

CC		=	gcc

RM		=	rm -f

SRCS		=	../generator/src/maze.c	\
			src/main.c		\
			src/init.c		\
			src/graph.c		\
			src/handler.c		\
			src/solve.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I./include -I../include -I../breadth/include

LFLAGS		=	-L../lib/ -lvector

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re

.PHONY:	all clean fclean re debug
