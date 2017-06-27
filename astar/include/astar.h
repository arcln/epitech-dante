/*
** breadth.h for dante in /home/arthur/B2/IA/dante/breadth/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Apr 13 12:54:56 2017 Arthur Chaloin
** Last update Fri May  5 17:58:02 2017 Paul Laffitte
*/

#ifndef ASTAR_H_
# define ASTAR_H_

# include "maze.h"
# include "vector.h"

# ifndef GRAPH_INDEX
#  define GRAPH_INDEX(width, x, y) ((y) * (width) + (x))
# endif /* !GRAPH_INDEX */

typedef struct		s_solver
{
  t_pos			pos;
  struct s_solver	*parent;
}			t_solver;

typedef struct		s_astar
{
  char			**source;
  t_maze		*maze;
  t_solver		*graph;
  t_vector		heads;
  t_solver		*head;
  t_pos			end;
  char			done;
}			t_astar;

# ifndef CALC_DIST
#  define CALC_DIST(p1, p2) (p2.x - p1.x + p2.y - p1.y)
# endif /* !CALC_DIST */

typedef struct		s_closest
{
  unsigned int		id;
  unsigned int		dist;
}			t_closest;

int		choose_children(t_astar *astar);
void		clean_maze(char **maze);

char		**astar_init_source(char **tab);
int		astar_init(t_astar *astar, t_maze *maze);
int		astar_update(t_astar *astar);

t_solver	*graph_set(t_astar *astar, t_solver *parent, int x, int y);

#endif /* !ASTAR_H_ */
