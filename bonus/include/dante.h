/*
** dante.h for dante in /Users/arthur/Documents/Dev/B2/IA/dante/bonus/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Apr 24 11:52:05 2017 Arthur Chaloin
** Last update Sun May 14 16:21:43 2017 Arthur Chaloin
*/

#ifndef DANTE_H_
# define DANTE_H_

# include "video.h"
# include "breadth.h"
# include "depth.h"
# include "astar.h"

#ifndef NCURSES_SPEED
# define NCURSES_SPEED 42
#endif

typedef struct	s_algo
{
  void		*data;
  int		(*init)(void *, t_maze *);
  int		(*update)(void *);
}		t_algo;

typedef struct	s_dante
{
  t_video	video;
  t_algo	algo;
  t_maze	maze;
}		t_dante;

int	dante_start(t_dante *dante, t_maze *maze);
int	curses_start(t_dante *dante, t_maze *maze);

#endif /* !DANTE_H_ */
