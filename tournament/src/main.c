/*
** main.c for dante in /Users/arthur/Documents/Dev/B2/IA/dante/new_depth/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Apr 24 16:04:11 2017 Arthur Chaloin
** Last update Mon Apr 24 20:59:25 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "depth.h"

static int	get_maze(t_depth *core, const char *path)
{
  int		index;
  FILE		*file;
  struct stat	info;

  if (stat(path, &info) < 0 ||
      !(core->maze = malloc(sizeof(char) * info.st_size)) ||
      !(core->source = malloc(sizeof(unsigned int) * info.st_size)) ||
      !(core->stack = malloc(sizeof(unsigned int) * info.st_size)))
    return (1);
  core->stack[0] = 0;
  core->len = 0;
  if (!(file = fopen(path, "r")) ||
      !fread(core->maze, info.st_size, 1, file))
    return (1);
  index = -1;
  while (core->maze[++index] && core->maze[index] != '\n');
  core->width = index + 1;
  core->height = info.st_size / core->width;
  core->capacity = info.st_size;
  fclose(file);
  memset(core->source, -1, info.st_size * 4);
  return (0);
}

int		main(int ac, char **av)
{
  t_depth	core;

  if (ac < 2)
    {
      fprintf(stderr, "Usage: %s <maze.mz>\n", av[0]);
      return (84);
    }
  if (get_maze(&core, av[1]))
    {
      fprintf(stderr, "Failed to load the maze.\n");
      return (84);
    }
  if (solve_maze(&core))
    write(1, core.maze, core.capacity);
  else
    write(1, "no solution found\n", 18);
  free(core.maze);
  free(core.source);
  free(core.stack);
  return (0);
}
