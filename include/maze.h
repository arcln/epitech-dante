/*
** maze.h for dante in /home/onehandedpenguin/Dev/AI_2016/dante/generator/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Apr 12 15:31:44 2017 Paul Laffitte
** Last update Fri May  5 16:58:31 2017 Paul Laffitte
*/

#ifndef MAZE_H_
# define MAZE_H_

# ifndef POS
#  define POS(x, y) (t_pos){x, y}
# endif

# ifndef IS_WALL
#  define IS_WALL(maze, p) (maze[p.y][p.x] != '*')
# endif

# ifndef IS_IN_MAZE
#  define IS_IN_MAZE(h, w, p) (p.x >= 0 && p.y >= 0 && p.x < w && p.y < h)
# endif

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_maze
{
  char		**data;
  int		width;
  int		height;
}		t_maze;

void		show_maze(char **maze);
char		**get_maze(char *filename);

#endif /* !MAZE_H_ */
