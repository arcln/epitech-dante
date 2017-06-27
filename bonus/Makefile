##
## Makefile for dante in /home/onehandedpenguin/Dev/IA_2016/dante/astar/
##
## Made by Paul Laffitte
## Login   <paul.laffitte@epitech.eu>
##
## Started on  Wed Apr 12 00:16:47 2017 Paul Laffitte
## Last update Mon May 15 19:26:42 2017 Arthur Chaloin
##

NAME		=	dante

CC		=	gcc

RM		=	rm -f

SRCS		=	src/main.c			\
			src/sfml/dante.c		\
			src/sfml/video.c		\
			src/opengl/init_gl.c		\
			src/opengl/load_shader.c	\
			src/opengl/model.c		\
			src/opengl/movements.c		\
			src/opengl/music.c		\
			src/opengl/render_gl.c		\
			src/math/matrix.c		\
			src/math/rotation.c		\
			src/math/vec_rotation.c		\
			src/math/translation.c		\
			src/math/vector.c		\
			src/glfw/window.c		\
			src/glfw/mouse.c		\
			src/glfw/inputs.c		\
			src/ncurses/ncurses.c		\
			../astar/src/init.c		\
			../astar/src/solve.c		\
			../astar/src/handler.c		\
			../astar/src/graph.c		\
			../breadth/src/solve.c		\
			../breadth/src/handler.c	\
			../depth/src/solve.c		\
			../depth/src/handler.c		\
			../generator/src/maze.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -Wextra
CFLAGS		+=	-I./include
CFLAGS		+=	-I../include
CFLAGS		+=	-I../lib/vector/include
CFLAGS		+=	-I../breadth/include/
CFLAGS		+=	-I../depth/include/
CFLAGS		+=	-I../astar/include/
CFLAGS		+=	`pkg-config --cflags gtk+-3.0`

LDFLAGS		=	-L../lib/vector/
LDFLAGS		+=	-lm
LDFLAGS		+=	-lfmod
LDFLAGS		+=	-lvector
LDFLAGS		+=	-lglfw
LDFLAGS		+=	-lncurses
LDFLAGS		+=	-lcsfml-graphics -lcsfml-window -lcsfml-system
LDFLAGS		+=	-lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS		+=	`pkg-config --libs glew`
LDFLAGS		+=	-framework opengl

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re

.PHONY:	all clean fclean re debug
