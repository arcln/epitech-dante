/*
** ncurses.c for dante in /Users/arthur/Documents/Dev/Epitech/B2/IA/dante/bonus/src/ncurses/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun May 14 15:53:16 2017 Arthur Chaloin
** Last update Sun May 14 17:24:14 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "dante.h"

static int	poll_events()
{
  char		c;

  c = getch();
  if (c == 'l')
    {
      endwin();
      return (1);
    }
  else if (c == 27)
    {
      endwin();
      exit(0);
    }
  return (0);
}

static void	set_color(t_dante *dante, t_maze *maze, int x, int y)
{
  int		color;

  if (maze->data[y][x] == 'X')
    color = 1;
  else if (maze->data[y][x] == 'o')
    color = 2;
  else if ((*((char ***)(dante->algo.data)))[y][x] != 'X'
	   && (*((char ***)(dante->algo.data)))[y][x] != '*')
    color = 3;
  else
    color = 4;
  attron(COLOR_PAIR(color));
}

static void	update_video(t_dante *dante, t_maze *maze)
{
  int		index;
  int		index2;
  int		size[2];

  index = -1;
  erase();
  getmaxyx(stdscr, size[1], size[0]);
  while ((*((char ***)(dante->algo.data)))[++index])
    {
      index2 = -1;
      while ((*((char ***)(dante->algo.data)))[index][++index2])
	{
	  set_color(dante, maze, index2, index);
	  mvprintw((size[1] / 2) - (maze->height / 2) + index,
		   (size[0] / 2) - maze->width + index2 * 2, "  ");
	  attron(COLOR_PAIR(0));
	}
    }
  refresh();
}

int		curses_start(t_dante *dante, t_maze *maze)
{
  int		ret;

  initscr();
  timeout(NCURSES_SPEED);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_GREEN);
  init_pair(3, COLOR_WHITE, COLOR_BLUE);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  while (!(ret = dante->algo.update(dante->algo.data)))
    {
      update_video(dante, maze);
      if (poll_events())
	return (0);
    }
  while (1)
    {
      update_video(dante, maze);
      if (poll_events())
	return (0);
    }
  return (endwin());
}
