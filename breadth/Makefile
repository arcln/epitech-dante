##
## Makefile for dante in /home/onehandedpenguin/Dev/IA_2016/dante/astar/
##
## Made by Paul Laffitte
## Login   <paul.laffitte@epitech.eu>
##
## Started on  Wed Apr 12 00:16:47 2017 Paul Laffitte
## Last update Mon Apr 24 12:03:27 2017 Arthur Chaloin
##

NAME		=	solver

CC		=	gcc

RM		=	rm -f

SRCS		=	src/main.c	\
			src/solve.c	\
			src/handler.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I./include -I../include -I../lib/vector/include

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L../lib/vector -lvector

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re

.PHONY:	all clean fclean re debug
