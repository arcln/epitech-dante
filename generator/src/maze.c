/*
** main.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/generator/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Apr 12 00:29:26 2017 Paul Laffitte
** Last update Fri May  5 18:43:46 2017 Paul Laffitte
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "maze.h"

void		show_maze(char **maze)
{
  while (*maze != NULL)
    {
      printf("%s", *maze);
      if (maze[1] != NULL)
	printf("\n");
      maze++;
    }
}

char		**get_maze(char *filename)
{
  FILE		*file;
  size_t	size_line;
  char		*line;
  char		**maze;

  maze = NULL;
  size_line = 0;
  if ((file = fopen(filename, "r")) != NULL)
    {
      while (getline(&line, &size_line, file) != -1)
	{
	  printf("%s", line);
	}
    }
  else
    dprintf(2, "Impossible to open the maze '%s'\n", filename);
  return (maze);
}

int		init_maze(t_maze *maze, int width, int height)
{
  int		i;

  if (width < 1 || height < 1)
    return (-1);
  if (!(maze->data = malloc(sizeof(char*) * (height + 1))))
    return (-1);
  i = 0;
  while (i != height)
    {
      if (!(maze->data[i] = malloc(sizeof(char) * (width + 1))))
	return (-1);
      memset(maze->data[i], 'X', width);
      maze->data[i][width] = '\0';
      ++i;
    }
  maze->data[i] = NULL;
  maze->width = width;
  maze->height = height;
  return (0);
}
