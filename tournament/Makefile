##
## Makefile for dante in /home/onehandedpenguin/Dev/IA_2016/dante/astar/
##
## Made by Paul Laffitte
## Login   <paul.laffitte@epitech.eu>
##
## Started on  Wed Apr 12 00:16:47 2017 Paul Laffitte
## Last update Tue Apr 25 15:09:29 2017 Arthur Chaloin
##

NAME		=	solver

CC		=	gcc

RM		=	rm -f

SRCS		=	src/main.c	\
			src/solve.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I./include -I../include -I../lib/vector/include -Ofast

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L../lib/vector -lvector -Ofast

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -pg
debug:		re

fast:		CFLAGS += -Ofast
fast:		re

.PHONY:	all clean fclean re debug
