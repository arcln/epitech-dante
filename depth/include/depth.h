/*
** depth.h for dante in /home/arthur/B2/IA/dante/depth/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Apr 13 12:54:56 2017 Arthur Chaloin
** Last update Sun May 14 17:01:56 2017 Arthur Chaloin
*/

#ifndef DEPTH_H_
# define DEPTH_H_

# include "maze.h"
# include "vector.h"

# ifndef IS_VALID
#  define IS_VALID(h, w, x, y) (x >= 0 && y >= 0 && x < w && y < h)
# endif

# ifndef WALL
#  define WALL(m, x, y) (m->data[y][x] != '*')
# endif

typedef struct	s_depth
{
  char		**source;
  t_pos		pos;
  t_vector	queue;
  t_maze	*maze;
}		t_depth;

int	depth_init(t_depth *b, t_maze *mz);
int	depth_update(t_depth *b);
int	depth_solve_maze(t_maze *maze);
char	**depth_init_source(char **tab);
int	depth_add_to_queue(t_vector *queue, int x, int y);
int	depth_fill_maze(t_maze *maze, char **source);
void	depth_explore_case(t_vector *queue, t_maze *mz,
			   t_pos *pos, char **source);

#endif /* !DEPTH_H_ */
