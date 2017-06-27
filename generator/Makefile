##
## Makefile for dante in /home/onehandedpenguin/Dev/IA_2016/dante/astar/
##
## Made by Paul Laffitte
## Login   <paul.laffitte@epitech.eu>
##
## Started on  Wed Apr 12 00:16:47 2017 Paul Laffitte
## Last update Wed Apr 12 20:10:18 2017 Paul Laffitte
##

NAME		=	generator

CC		=	gcc

RM		=	rm -f

SRCS		=	src/main.c		\
			src/maze.c		\
			src/perfect_maze.c	\
			src/imperfect_maze.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I./include -I../include

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
