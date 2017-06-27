/*
** main.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/breadth/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Apr 12 00:29:32 2017 Paul Laffitte
** Last update Sun Apr 23 19:03:28 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "breadth.h"
#include "maze.h"

static int	tablen(char **tab)
{
  int		index;

  index = -1;
  while (tab[++index]);
  return (index);
}

void	print_maze(char **maze)
{
  int	index;

  index = -1;
  while (maze[++index])
    printf("%s\n", maze[index]);
}

static char	**map_maze(const char *filename)
{
  int		index;
  FILE		*file;
  size_t	size_line, size;
  char		*line, **maze;

  line = NULL;
  size_line = 0;
  size = 1;
  if ((file = fopen(filename, "r")))
    {
      if (!(maze = malloc(sizeof(char *) * size)))
	return (NULL);
      index = 0;
      while (getline(&line, &size_line, file) != -1)
	{
	  maze[index] = strdup(line);
	  if (maze[index][strlen(maze[index]) - 1] == '\n')
	    maze[index][strlen(maze[index]) - 1] = 0;
	  if (!(maze = realloc(maze, sizeof(char *) * ++size)))
	    return (NULL);
	  index++;
	}
      maze[size - 1] = NULL;
    }
  return ((file) ? maze : NULL);
}

int		main(int ac, char **av)
{
  t_maze	maze;

  if (ac < 2)
    {
      dprintf(2, "Usage: %s <maze.mz>\n", av[0]);
      return (84);
    }
  if (!(maze.data = map_maze(av[1])))
    {
      fprintf(stderr, "Failed to load the maze.\n");
      return (84);
    }
  maze.height = tablen(maze.data);
  maze.width = strlen(maze.data[0]);
  if (solve_maze(&maze) != 0)
    printf("no solution found\n");
  else
    print_maze(maze.data);
  return (0);
}
