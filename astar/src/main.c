/*
** main.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/breadth/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Apr 12 00:29:32 2017 Paul Laffitte
** Last update Fri May  5 16:57:19 2017 Paul Laffitte
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "astar.h"

static char	**load_maze(FILE *file, char **maze)
{
  int		index;
  size_t	size_line;
  size_t	size;
  char		*line;

  line = NULL;
  size_line = 0;
  size = 1;
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
  return (maze);
}

static char	**map_maze(const char *filename)
{
  FILE		*file;
  char		**maze;

  maze = NULL;
  if ((file = fopen(filename, "r")))
    {
      if (!(maze = malloc(sizeof(char*)))
	  || !(maze = load_maze(file, maze)))
	return (NULL);
    }
  else
    dprintf(2, "Impossible to open the maze '%s'\n", filename);
  return (maze);
}

static void	calc_size(t_maze *maze)
{
  maze->width = -1;
  while (maze->data[0][++maze->width]);
  maze->height = -1;
  while (maze->data[++maze->height]);
}

int		main(int ac, char **av)
{
  t_astar	astar;
  t_maze	maze;
  int		i;
  int		ret;

  if (ac < 2)
    {
      dprintf(2, "Usage: %s <maze.mz>\n", av[0]);
      return (84);
    }
  if (!(maze.data = map_maze(av[1])))
    return (84);
  calc_size(&maze);
  astar_init(&astar, &maze);
  while (!(ret = astar_update(&astar)));
  if (ret < 0)
    printf("no solution found\n");
  else
    show_maze(maze.data);
  i = -1;
  while (maze.data[++i])
    free(maze.data[i]);
  free(maze.data);
  return (0);
}
