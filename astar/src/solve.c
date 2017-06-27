/*
** solve.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/astar/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Apr 14 21:50:24 2017 Paul Laffitte
** Last update Fri May  5 17:11:14 2017 Paul Laffitte
*/

#include <stdlib.h>
#include "vector.h"
#include "astar.h"

static void	move_head(t_astar *astar, t_solver *parent, t_solver *solver)
{
  t_solver	*iterator;
  int		i;

  i = 0;
  while ((iterator = VECTOR_GET(&astar->heads, i, t_solver))
	 && iterator != parent)
    ++i;
  if (iterator)
    VECTOR_SET(&astar->heads, i, solver);
}

int		add_children(t_astar *astar, t_solver *parent, t_pos pos,
			     int nb_children)
{
  t_solver	*solver;

  if ((!parent->parent
       || pos.x != parent->parent->pos.x || pos.y != parent->parent->pos.y)
      && IS_IN_MAZE(astar->maze->height, astar->maze->width, pos)
      && !IS_WALL(astar->source, pos))
    {
      solver = graph_set(astar, parent, pos.x, pos.y);
      if (nb_children != 0)
	VECTOR_PUSH(&astar->heads, solver);
      else
	move_head(astar, parent, solver);
      astar->source[pos.y][pos.x] = '.';
    }
  else
    return (0);
  return (1);
}

int		choose_children(t_astar *astar)
{
  t_solver	*parent;
  int		nb_children;

  parent = astar->head;
  nb_children = 0;
  nb_children += add_children(astar, parent,
			   POS(parent->pos.x + 1, parent->pos.y), nb_children);
  nb_children += add_children(astar, parent,
			   POS(parent->pos.x, parent->pos.y + 1), nb_children);
  nb_children += add_children(astar, parent,
			   POS(parent->pos.x - 1, parent->pos.y), nb_children);
  nb_children += add_children(astar, parent,
			   POS(parent->pos.x, parent->pos.y - 1), nb_children);
  return (nb_children != 0 ? 0 : -1);
}
