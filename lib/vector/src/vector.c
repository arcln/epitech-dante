/*
** vector.c for vector in /Users/arthur/Dev/B2/IA/dante/lib/vector/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun Apr 23 19:20:47 2017 Arthur Chaloin
** Last update Sun Apr 23 19:20:51 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include "vector.h"

int	vector_init(t_vector *vector)
{
  vector->size = 0;
  vector->capacity = VECTOR_INIT_CAPACITY;
  if (!(vector->items = malloc(sizeof(void*) * vector->capacity)))
    return (-1);
  return (0);
}

int	vector_resize(t_vector *vector, int capacity)
{
  int	index;
  void	**items;

  if (!(items = malloc(sizeof(void*) * capacity)))
    return (-1);
  index = 0;
  while (index < vector->size)
    {
      items[index] = vector->items[index];
      index += 1;
    }
  vector_free(vector);
  vector->items = items;
  vector->capacity = capacity;
  return (0);
}

void	vector_foreach(t_vector *vector, void (*func)(void*, int))
{
  int	index;

  index = 0;
  while (index < vector->size)
    {
      func(vector->items[index], index);
      index += 1;
    }
}

void	vector_sort(t_vector *vector, int (*cmp)(void*, void*))
{
  void	*item;
  int	index;

  index = 0;
  while (index < vector->size - 1)
    {
      if (cmp(vector->items[index], vector->items[index + 1]))
	{
	  item = vector->items[index];
	  vector->items[index] = vector->items[index + 1];
	  vector->items[index + 1] = item;
	}
      index += 1;
    }
}

void	vector_free(t_vector *vector)
{
  free(vector->items);
}
