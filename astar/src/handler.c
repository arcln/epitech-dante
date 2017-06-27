/*
** init_astar.c for dante in /tmp/dante/astar/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed May  3 19:47:40 2017 Paul Laffitte
** Last update Sun May 14 16:44:19 2017 Arthur Chaloin
*/

#include <stdlib.h>
#include <limits.h>
#include "astar.h"
#include "breadth.h"

int		astar_init(t_astar *astar, t_maze *maze)
{
  astar->graph = NULL;
  maze->data[0][0] = '.';
  if (!(astar->source = astar_init_source(maze->data))
      || !(astar->graph = malloc(sizeof(t_solver)
				 * maze->width * maze->height)))
    return (-1);
  astar->maze = maze;
  astar->head = graph_set(astar, NULL, 0, 0);
  astar->end = POS(astar->maze->width - 1, astar->maze->height - 1);
  astar->done = 0;
  vector_init(&astar->heads);
  VECTOR_PUSH(&astar->heads, astar->head);
  return (0);
}

static int	astar_done(t_astar *astar, int state)
{
  astar->done = 1;
  if (astar->head)
    {
      astar->maze->data[astar->head->pos.y][astar->head->pos.x] = 'o';
      astar->head = astar->head->parent;
    }
  return (state == 1 ? astar->head == NULL : state);
}

int		astar_update(t_astar *astar)
{
  t_closest	closest;
  unsigned int	i;
  unsigned int	dist;

  if (astar->done)
    return (astar_done(astar, 1));
  closest.dist = UINT_MAX;
  closest.id = -1;
  i = -1;
  while ((astar->head = VECTOR_GET(&astar->heads, ++i, t_solver)))
    {
      if ((dist = CALC_DIST(astar->head->pos, astar->end)) < closest.dist)
	closest = (t_closest){i, dist};
    }
  if ((astar->head = VECTOR_GET(&astar->heads, closest.id, t_solver)))
    {
      if (astar->head->pos.x == astar->end.x
	  && astar->head->pos.y == astar->end.y)
	return (astar_done(astar, 1));
      else if (choose_children(astar) == -1)
	vector_delete(&astar->heads, closest.id);
    }
  else
    return (astar_done(astar, -1));
  return (0);
}
