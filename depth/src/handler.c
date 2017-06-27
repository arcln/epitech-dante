/*
** handler.c for dante in /Users/arthur/Documents/Dev/B2/IA/dante/depth/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Apr 24 11:20:07 2017 Arthur Chaloin
** Last update Wed May  3 20:00:52 2017 Arthur Chaloin
*/
#include "depth.h"
#include "vector.h"

int	depth_init(t_depth *b, t_maze *maze)
{
  if (!(b->source = depth_init_source(maze->data)))
    return (-1);
  vector_init(&b->queue);
  b->pos = POS(0, 0);
  VECTOR_PUSH(&b->queue, &b->pos);
  b->source[0][0] = 42;
  b->maze = maze;
  return (0);
}

int	depth_update(t_depth *b)
{
  if (b->pos.x == b->maze->width - 1 && b->pos.y == b->maze->height - 1)
    return (depth_fill_maze(b->maze, b->source));
  if (!vector_getsize(&b->queue))
    return (-1);
  b->pos = *VECTOR_GET(&b->queue, 0, t_pos);
  vector_delete(&b->queue, 0);
  depth_explore_case(&b->queue, b->maze, &b->pos, b->source);
  return (0);
}
