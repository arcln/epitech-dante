/*
** main.c for dante in /Users/arthur/Dev/B2/IA/dante/bonus/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun Apr 23 19:30:43 2017 Arthur Chaloin
** Last update Mon May 15 19:11:17 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "dante.h"
#include "music.h"
#include "glfw.h"

t_dante			g_dante;

const struct option	opt_list[] = {
  {"algo", required_argument, NULL, 'a'},
  {"graphic", required_argument, NULL, 'g'},
  {NULL, 0, NULL, 0}
};

static int	print_usage(char *binary_name)
{
  fprintf(stderr, "Usage: %s --algo -a \"algorithm name\"\
 --graphic -g \"graphic manager name\"\n", binary_name);
  return (EXIT_FAILURE);
}

static int	tablen(char **tab)
{
  int		index;

  index = -1;
  while (tab[++index]);
  return (index);
}

static int	map_maze(t_maze *mz, const char *filename)
{
  int		index;
  FILE		*file;
  size_t	size_line, size;
  char		*line, **m;

  line = NULL;
  size_line = 0;
  size = 1;
  if (!(file = fopen(filename, "r")) || !(m = malloc(sizeof(char *) * size)))
    return (1);
  index = 0;
  while (getline(&line, &size_line, file) != -1)
    {
      m[index] = strdup(line);
      if (m[index][strlen(m[index]) - 1] == '\n')
	m[index][strlen(m[index]) - 1] = 0;
      if (!(m = realloc(m, sizeof(char *) * ++size)))
	return (1);
      index++;
    }
  m[size - 1] = NULL;
  mz->data = m;
  mz->height = tablen(m);
  mz->width = strlen(m[0]);
  return (0);
}

static int	algo_init(t_algo *algo, char *raw)
{
  if (!strcmp(raw, "breadth"))
    {
      algo->init = (int (*)(void *, t_maze *))&breadth_init;
      algo->update = (int (*)(void *))&breadth_update;
      algo->data = malloc(sizeof(t_breadth));
    }
  else if (!strcmp(raw, "depth"))
    {
      algo->init = (int (*)(void *, t_maze *))&depth_init;
      algo->update = (int (*)(void *))&depth_update;
      algo->data = malloc(sizeof(t_depth));
    }
  else if (!strcmp(raw, "astar"))
    {
      algo->init = (int (*)(void *, t_maze *))&astar_init;
      algo->update = (int (*)(void *))&astar_update;
      algo->data = malloc(sizeof(t_astar));
    }
  else
    {
      fprintf(stderr, "Unknown algorithm '%s'\n", raw);
      return (1);
    }
  return (!(algo->data));
}

static int	start_graphic(char *graphic)
{
  int		actual;

  video_init(&g_dante.video);
  if (strcmp(graphic, "sfml") == 0)
    actual = 0;
  else if (strcmp(graphic, "ncurses") == 0)
    actual = 1;
  else if (strcmp(graphic, "opengl") == 0)
    actual = 2;
  else
    {
      dprintf(2, "%s: Unknown graphic manager\n", graphic);
      return (-1);
    }
  while (1)
    {
      if (actual == 0)
	dante_start(&g_dante, &g_dante.maze);
      else if (actual == 1)
	curses_start(&g_dante, &g_dante.maze);
      else if (actual == 2)
  	open_window();
      actual = (actual < 3) ? actual + 1 : 0;
    }
  return (0);
}

int		main(int ac, char *av[])
{
  char		opt;
  char		*algo;
  char		*graphic;
  char		state;

  algo = NULL;
  graphic = NULL;
  while ((opt = getopt_long(ac, av, ":a:g:", opt_list, NULL)) != -1)
    {
      if (opt == 'a')
	algo = optarg;
      else if (opt == 'g')
	graphic = optarg;
      else
	return (print_usage(av[0]));
    }
  if (!algo)
    return (print_usage(av[0]));
  if (algo_init(&g_dante.algo, algo) || map_maze(&g_dante.maze, av[optind]))
    return (1);
  g_dante.algo.init(g_dante.algo.data, &g_dante.maze);
  if (!graphic || start_music() || (state = start_graphic(graphic)) == -1)
    return (print_usage(av[0]));
  return (state);
}
