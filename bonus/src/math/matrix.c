/*
** mat.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/3d/math/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Mar 29 10:42:35 2017 Paul Laffitte
** Last update Sat May 13 04:01:08 2017 Paul Laffitte
*/

#include "math_gl.h"

void		mat_cpy(float src[4][4], float buffer[4][4])
{
  buffer[0][0] = src[0][0];
  buffer[0][1] = src[0][1];
  buffer[0][2] = src[0][2];
  buffer[0][3] = src[0][3];
  buffer[1][0] = src[1][0];
  buffer[1][1] = src[1][1];
  buffer[1][2] = src[1][2];
  buffer[1][3] = src[1][3];
  buffer[2][0] = src[2][0];
  buffer[2][1] = src[2][1];
  buffer[2][2] = src[2][2];
  buffer[2][3] = src[2][3];
  buffer[3][0] = src[3][0];
  buffer[3][1] = src[3][1];
  buffer[3][2] = src[3][2];
  buffer[3][3] = src[3][3];
}

void		mat_transpose(float mat[4][4])
{
  float		tmp[4][4];

  mat_cpy(mat, tmp);
  mat[0][0] = tmp[0][0];
  mat[0][1] = tmp[1][0];
  mat[0][2] = tmp[2][0];
  mat[0][3] = tmp[3][0];
  mat[1][0] = tmp[0][1];
  mat[1][1] = tmp[1][1];
  mat[1][2] = tmp[2][1];
  mat[1][3] = tmp[3][1];
  mat[2][0] = tmp[0][2];
  mat[2][1] = tmp[1][2];
  mat[2][2] = tmp[2][2];
  mat[2][3] = tmp[3][2];
  mat[3][0] = tmp[0][3];
  mat[3][1] = tmp[1][3];
  mat[3][2] = tmp[2][3];
  mat[3][3] = tmp[3][3];
}

static void	mat_get_line(float mat[4][4], int line, float buffer[4])
{
  buffer[0] = mat[0][line];
  buffer[1] = mat[1][line];
  buffer[2] = mat[2][line];
  buffer[3] = mat[3][line];
}

void		mat_product(float m1[4][4], float m2[4][4])
{
  int		x;
  int		y;
  float		vector[4];
  float		tmp[4][4];

  mat_cpy(m1, tmp);
  y = 0;
  while (y < 4)
    {
      x = 0;
      while (x < 4)
	{
	  mat_get_line(tmp, y, vector);
	  m1[x][y] = VEC_DOT4(vector, m2[x]);
	  x++;
	}
      y++;
    }
}

void		mat_identity(float mat[4][4])
{
  mat[0][0] = 1;
  mat[0][1] = 0;
  mat[0][2] = 0;
  mat[0][3] = 0;
  mat[1][0] = 0;
  mat[1][1] = 1;
  mat[1][2] = 0;
  mat[1][3] = 0;
  mat[2][0] = 0;
  mat[2][1] = 0;
  mat[2][2] = 1;
  mat[2][3] = 0;
  mat[3][0] = 0;
  mat[3][1] = 0;
  mat[3][2] = 0;
  mat[3][3] = 1;
}
