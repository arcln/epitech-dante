/*
** breadth.h for dante in /home/arthur/B2/IA/dante/breadth/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Apr 13 12:54:56 2017 Arthur Chaloin
** Last update Mon Apr 24 12:51:15 2017 Arthur Chaloin
*/

#ifndef BREADTH_H_
# define BREADTH_H_

# include "maze.h"
# include "vector.h"

# ifndef IS_VALID
#  define IS_VALID(h, w, x, y) (x >= 0 && y >= 0 && x < w && y < h)
# endif

# ifndef WALL
#  define WALL(m, x, y) (m->data[y][x] != '*')
# endif

typedef struct	s_breadth
{
  char		**source;
  t_pos		pos;
  t_vector	queue;
  t_maze	*maze;
}		t_breadth;

int	breadth_init(t_breadth *b, t_maze *mz);
int	breadth_update(t_breadth *b);
int	solve_maze(t_maze *maze);
char	**init_source(char **tab);
int	add_to_queue(t_vector *queue, int x, int y);
int	fill_maze(t_maze *maze, char **source);
void	explore_case(t_vector *queue, t_maze *mz, t_pos *pos, char **source);

#endif /* !BREADTH_H_ */
