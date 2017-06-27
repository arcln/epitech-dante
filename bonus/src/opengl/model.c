/*
** model.c for g_corewar in /home/arthur/B2/CPE/CPE_2016_corewar/bbw/src/3d/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Mar 29 21:43:17 2017 Arthur Chaloin
** Last update Sun May 14 22:57:52 2017 Paul Laffitte
*/
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include "opengl.h"
#include "math_gl.h"

const float	colors[][3] = {
  {0.21, 0.21, 0.21},
  {0.84, 0.10, 0.10},
  {0.10, 0.84, 0.10},
  {0., 0., 0.},
};

void		model_mat(int index, int index2, float moy)
{
  float		transform[4][4];

  moy = (moy > 1.65) ? 1.65 : moy;
  moy = (-(1 / (moy / 2.2)) / 1.8 + 2) / 3;
  mat_identity(transform);
  glBindBuffer(GL_ARRAY_BUFFER, g_gl.colorbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data),
        g_color_buffer_data, GL_STATIC_DRAW);
  transform[3][0] = g_dante.maze.width - (index2 * 2);
  transform[3][1] = -30. + (10. * moy);
  transform[3][2] = g_dante.maze.height - (index * 2);
  mat_product(g_gl.mvp, transform);
}

static float	get_color(int top, float progress, int posX, int posY)
{
  int		color;

  if (g_dante.maze.data[posY][posX] == 'X')
    color = 0;
  else if (g_dante.maze.data[posY][posX] == 'o')
    color = 1;
  else if ((*((char ***)(g_dante.algo.data)))[posY][posX] != 'X'
	   && (*((char ***)(g_dante.algo.data)))[posY][posX] != '*')
    color = 2;
  else
    color = 3;
  return ((color != 3) ? colors[color][top] +
	  ((1 - colors[color][top]) * progress) : 0.);
}

static void	init_model(float **progress, float **last)
{
  if (!(*progress = malloc(sizeof(float) *
			  (g_dante.maze.width * g_dante.maze.height))) ||
      !(*last = malloc(sizeof(float) * (g_dante.maze.width *
			     g_dante.maze.height))))
    exit(84);
  memset(*progress, -1, sizeof(float) *
	 (g_dante.maze.width * g_dante.maze.height));
  memset(*last, -1, sizeof(float) *
	 (g_dante.maze.width * g_dante.maze.height));
}

static void	set_color(float color[3], float moy, int posY)
{
  int		i;

  i = 0;
  while (i < 3 * 36)
    {
      g_color_buffer_data[i] = color[0] + (moy - 1) * 0.65
	  * posY / g_dante.maze.height;
      g_color_buffer_data[i + 1] = color[1];
      g_color_buffer_data[i + 2] = color[2] * moy * 1.2;
      i += 3;
    }
}

int		model_color(int posY, int posX, float moy)
{
  int		pos;
  static float	*progress = NULL;
  static float	*last = NULL;
  float		color[3];

  pos = posY * g_dante.maze.width + posX;
  if (!progress)
    init_model(&progress, &last);
  if (last[pos] < 0 ||
      last[pos] != (*((char ***)(g_dante.algo.data)))[posY][posX])
    {
      last[pos] = (*((char ***)(g_dante.algo.data)))[posY][posX];
      progress[pos] = 1.;
    }
  progress[pos] = (progress[pos] <= 0) ? 0 : progress[pos] - 0.03;
  if (rand() % 1500 == 0)
    progress[pos] += 0.3;
  if (!(color[0] = get_color(0, progress[pos], posX, posY)))
      return (0);
  color[1] = get_color(1, progress[pos], posX, posY);
  color[2] = get_color(2, progress[pos], posX, posY);
  set_color(color, moy, posY);
  return (1);
}
