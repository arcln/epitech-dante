/*
** perfect_maze.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/generator/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Apr 12 16:04:06 2017 Paul Laffitte
** Last update Sat May  6 21:36:16 2017 Paul Laffitte
*/

#include <stdlib.h>
#include "gen_maze.h"
#include "vector.h"

static void	get_new_pos(t_pos *pos, int choice)
{
  if (choice == 0)
    pos->x += 2;
  else if (choice == 1)
    pos->x -= 2;
  else if (choice == 2)
    pos->y += 2;
  else if (choice == 3)
    pos->y -= 2;
}

static void	draw_maze(t_maze *maze, t_pos *pos, t_pos *middle)
{
  if (IS_IN_MAZE(maze->height, maze->width, (*pos)))
    maze->data[pos->y][pos->x] = '*';
  else
    *pos = *middle;
  maze->data[middle->y][middle->x] = '*';
}

static int	new_pos(t_maze *maze, t_pos *pos, int width, int height)
{
  int		direction;
  int		i;
  t_pos		middle;
  t_pos		new_pos;

  if (pos->x == maze->width - 1 && pos->y == maze->height - 1)
    return (-1);
  direction = rand() % 4;
  i = 0;
  while (i != 4)
    {
      new_pos = *pos;
      get_new_pos(&new_pos, (direction + i) % 4);
      middle = POS((pos->x + new_pos.x) / 2, (pos->y + new_pos.y) / 2);
      if (IS_IN_MAZE(height, width, new_pos)
	  && IS_WALL(maze->data, new_pos))
	break ;
      ++i;
    }
  *pos = new_pos;
  if (i == 4)
    return (-1);
  draw_maze(maze, &new_pos, &middle);
  return (0);
}

static int	handle_stack(t_stack_action action,
			     t_vector *stack, t_pos *pos)
{
  t_pos		*cpy_pos;
  int		size;

  if (action == STACK)
    {
      if (!(cpy_pos = malloc(sizeof(t_pos))))
	return (-1);
      *cpy_pos = *pos;
      VECTOR_PUSH(stack, cpy_pos);
    }
  else if (action == POP)
    {
      size = vector_getsize(stack);
      free(VECTOR_GET(stack, size - 1, t_pos));
      if (size != 0)
	vector_delete(stack, size - 1);
      if (size != 1)
	*pos = *VECTOR_GET(stack, size - 2, t_pos);
    }
  return (0);
}

int		perfect_maze(t_maze *maze, int width, int height)
{
  t_pos		pos;
  t_vector	stack;

  pos = (t_pos){0, 0};
  maze->data[0][0] = '*';
  vector_init(&stack);
  if (handle_stack(STACK, &stack, &pos) == -1)
    return (-1);
  while (1)
    {
      while (new_pos(maze, &pos, width, height) == -1
	     && vector_getsize(&stack) != 0)
	handle_stack(POP, &stack, &pos);
      if (vector_getsize(&stack) == 0)
	break ;
      if (handle_stack(STACK, &stack, &pos) == -1)
	return (-1);
    }
  vector_free(&stack);
  if (maze->height % 2 == 0)
    maze->data[maze->height - 2][maze->width - 1] = '*';
  else if (maze->width % 2 == 0)
    maze->data[maze->height - 1][maze->width - 2] = '*';
  maze->data[maze->height - 1][maze->width - 1] = '*';
  return (0);
}
