/*
** prepend.c for vector in /Users/arthur/Dev/B2/IA/dante/lib/vector/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun Apr 23 19:20:27 2017 Arthur Chaloin
** Last update Sun Apr 23 19:24:04 2017 Arthur Chaloin
*/
#include "vector.h"

void	vector_prepend(t_vector *v, void *elem)
{
  int	index;

  _vector_push(v, elem);
  index = vector_getsize(v) - 1;
  while (--index >= 0)
    v->items[index + 1] = v->items[index];
  v->items[0] = elem;
}
