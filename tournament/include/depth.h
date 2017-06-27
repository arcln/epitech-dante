/*
** depth.h for dante in /Users/arthur/Documents/Dev/B2/IA/dante/new_depth/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Apr 24 16:04:53 2017 Arthur Chaloin
** Last update Sun May 14 17:11:44 2017 Arthur Chaloin
*/

#ifndef DEPTH_H_
# define DEPTH_H_

#ifndef VALID
# define VALID(c, p) (p < c->capacity && c->maze[p] != '\n')
#endif

#ifndef WALL
# define WALL(c, p) (c->maze[p] == 'X')
#endif

typedef struct	s_depth
{
  char		*maze;
  unsigned int	width;
  unsigned int	height;
  unsigned int	*source;
  unsigned int	*stack;
  unsigned int	len;
  unsigned int	capacity;
}		t_depth;

int	solve_maze(t_depth *core);

#endif /* !DEPTH_H_ */
