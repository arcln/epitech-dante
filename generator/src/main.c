/*
** main.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/generator/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Apr 12 15:36:22 2017 Paul Laffitte
** Last update Sat May  6 21:27:02 2017 Paul Laffitte
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "maze.h"
#include "gen_maze.h"

int		gen_maze(t_maze *maze, int width, int heigth, char perfect)
{
  srand(time(NULL));
  if (init_maze(maze, width, heigth) == -1)
    return (-1);
  if (perfect && perfect_maze(maze, width, heigth) == -1)
    return (-1);
  else if (!perfect && imperfect_maze(maze, width, heigth) == -1)
    return (-1);
  return (0);
}

void		free_maze(t_maze *maze)
{
  int		i;

  i = 0;
  while (maze->data[i])
    {
      free(maze->data[i]);
      ++i;
    }
  free(maze->data);
}

int		error(char *error)
{
  dprintf(2, "%s\n", error);
  return (84);
}

int		main(int argc, char **argv)
{
  t_maze	maze;

  if (argc == 3 || argc == 4)
    {
      if (gen_maze(&maze, atoi(argv[1]), atoi(argv[2]),
		   argc == 3 || argv[3][0] != '0') == -1)
	return (error("Unable to generate a maze"));
      show_maze(maze.data);
      free_maze(&maze);
    }
  else
    return (84);
  return (0);
}
