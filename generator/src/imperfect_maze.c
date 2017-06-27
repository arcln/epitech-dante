/*
** imperfect_maze.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/generator/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Apr 12 16:04:06 2017 Paul Laffitte
** Last update Sun May 14 19:00:17 2017 Paul Laffitte
*/

#include <stdlib.h>
#include "gen_maze.h"

int		imperfect_maze(t_maze *maze, int width, int heigth)
{
  int		limit;
  int		x;
  int		y;
  int		i;

  if (perfect_maze(maze, width, heigth) == -1)
    return (-1);
  limit = (width + heigth) / 2;
  i = 0;
  while (i != limit)
  {
      x = rand() % width;
      y = rand() % heigth;
      if (maze->data[y][x] == 'X')
	maze->data[y][x] = '*';
      ++i;
    }
  return (0);
}
