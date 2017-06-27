/*
** handler.c for dante in /Users/arthur/Documents/Dev/B2/IA/dante/breadth/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Apr 24 11:20:07 2017 Arthur Chaloin
** Last update Mon Apr 24 15:06:43 2017 Arthur Chaloin
*/
#include "breadth.h"
#include "vector.h"

int	breadth_init(t_breadth *b, t_maze *maze)
{
  if (!(b->source = init_source(maze->data)))
    return (-1);
  vector_init(&b->queue);
  b->pos = POS(0, 0);
  VECTOR_PUSH(&b->queue, &b->pos);
  b->source[0][0] = 42;
  b->maze = maze;
  return (0);
}

int	breadth_update(t_breadth *b)
{
  if (b->pos.x == b->maze->width - 1 && b->pos.y == b->maze->height - 1)
    return (fill_maze(b->maze, b->source));
  if (!vector_getsize(&b->queue))
    return (-1);
  b->pos = *VECTOR_GET(&b->queue, 0, t_pos);
  vector_delete(&b->queue, 0);
  explore_case(&b->queue, b->maze, &b->pos, b->source);
  return (0);
}
