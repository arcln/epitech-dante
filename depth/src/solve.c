/*
** solve.c for dante in /home/arthur/B2/IA/dante/depth_/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Apr 13 12:56:45 2017 Arthur Chaloin
** Last update Sun May 14 17:02:07 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "depth.h"
#include "vector.h"

char		**depth_init_source(char **tab)
{
  int		index;
  int		len;
  char		**new;

  index = -1;
  while (tab[++index]);
  len = index;
  if (!(new = malloc(sizeof(char **) * (len + 1))))
    return (NULL);
  index = -1;
  while (tab[++index])
    {
      new[index] = strdup(tab[index]);
      memset(new[index], 'X', strlen(tab[index]));
    }
  new[index] = NULL;
  return (new);
}

int		depth_add_to_queue(t_vector *queue, int x, int y)
{
  t_pos		*new;

  if (!(new = malloc(sizeof(t_pos))))
    return (-1);
  new->x = x;
  new->y = y;
  VECTOR_PUSH(queue, new);
  return (0);
}

int		depth_fill_maze(t_maze *maze, char **source)
{
  static t_pos	pos;
  static int	call = 0;

  if (!call)
    {
      pos = POS(maze->width - 1, maze->height - 1);
      call = 1;
    }
  if (!IS_VALID(maze->height, maze->width, pos.x, pos.y))
    return (-1);
  if (source[pos.y][pos.x] == 42)
    return ((maze->data[0][0] != '*') ? -1 : (maze->data[0][0] = 'o', 1));
  if (WALL(maze, pos.x, pos.y))
    return (-1);
  maze->data[pos.y][pos.x] = 'o';
  if (source[pos.y][pos.x] == '0')
    pos.y++;
  else if (source[pos.y][pos.x] == '1')
    pos.y--;
  else if (source[pos.y][pos.x] == '2')
    pos.x--;
  else if (source[pos.y][pos.x] == '3')
    pos.x++;
  return (0);
}

void	depth_explore_case(t_vector *queue, t_maze *mz,
			   t_pos *pos, char **source)
{
  if (IS_VALID(mz->height, mz->width, pos->x, pos->y - 1) &&
      !WALL(mz, pos->x, pos->y - 1) && source[pos->y - 1][pos->x] == 'X')
    {
      source[pos->y - 1][pos->x] = '0';
      depth_add_to_queue(queue, pos->x, pos->y - 1);
    }
  if (IS_VALID(mz->height, mz->width, pos->x, pos->y + 1) &&
      !WALL(mz, pos->x, pos->y + 1) && source[pos->y + 1][pos->x] == 'X')
    {
      source[pos->y + 1][pos->x] = '1';
      depth_add_to_queue(queue, pos->x, pos->y + 1);
    }
  if (IS_VALID(mz->height, mz->width, pos->x + 1, pos->y) &&
      !WALL(mz, pos->x + 1, pos->y) && source[pos->y][pos->x + 1] == 'X')
    {
      source[pos->y][pos->x + 1] = '2';
      depth_add_to_queue(queue, pos->x + 1, pos->y);
    }
  if (IS_VALID(mz->height, mz->width, pos->x - 1, pos->y) &&
      !WALL(mz, pos->x - 1, pos->y) && source[pos->y][pos->x - 1] == 'X')
    {
      source[pos->y][pos->x - 1] = '3';
      depth_add_to_queue(queue, pos->x - 1, pos->y);
    }
}

int		depth_solve_maze(t_maze *mz)
{
  int		ret;
  t_depth	depth;

  depth_init(&depth, mz);
  while (!(ret = depth_update(&depth)));
  if (ret < 0)
    return (1);
  return (0);
}
