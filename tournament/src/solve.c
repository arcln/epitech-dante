/*
** solve.c for dante in /Users/arthur/Documents/Dev/B2/IA/dante/new_depth/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Apr 24 16:45:45 2017 Arthur Chaloin
** Last update Sun May 14 17:21:04 2017 Arthur Chaloin
*/
#include "depth.h"

static int	fill_maze(t_depth *core)
{
  unsigned	p;

  p = core->capacity - 1;
  while (p)
    {
      core->maze[p] = 'o';
      p = core->source[p];
    }
  core->maze[p] = 'o';
  return (1);
}

static void	add_to_stack(t_depth *core, unsigned p, unsigned tmp)
{
  core->len += 1;
  core->stack[core->len] = tmp;
  core->source[tmp] = p;
}

int		solve_maze(t_depth *core)
{
  unsigned	p;
  unsigned	tmp;

  while ((p = core->stack[core->len]) != core->capacity - 1)
    {
      core->len -= 1;
      if (VALID(core, (tmp = p + 1)) && !WALL(core, tmp) &&
	  core->source[tmp] > core->capacity)
	add_to_stack(core, p, tmp);
      if (VALID(core, (tmp = p + core->width)) && !WALL(core, tmp) &&
	  core->source[tmp] > core->capacity)
	add_to_stack(core, p, tmp);
      if (VALID(core, (tmp = p - 1)) && !WALL(core, tmp) &&
	  core->source[tmp] > core->capacity)
	add_to_stack(core, p, tmp);
      if (VALID(core, (tmp = p - core->width)) && !WALL(core, tmp) &&
	  core->source[tmp] > core->capacity)
	add_to_stack(core, p, tmp);
      if (core->len > core->capacity)
  	return (0);
    }
  return (fill_maze(core));
}
