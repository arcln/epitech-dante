/*
** gen_maze.h for dante in /home/onehandedpenguin/Dev/AI_2016/dante/generator/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Apr 12 16:05:30 2017 Paul Laffitte
** Last update Fri Apr 14 18:14:26 2017 Paul Laffitte
*/

#ifndef GEN_MAZE_H_
# define GEN_MAZE_H_

#include "maze.h"

int		init_maze(t_maze *maze, int width, int heigth);
int		perfect_maze(t_maze *maze, int width, int heigth);
int		imperfect_maze(t_maze *maze, int width, int heigth);

typedef enum	e_stack_action
{
  STACK, POP
}		t_stack_action;

#endif /* !GEN_MAZE_H_ */
