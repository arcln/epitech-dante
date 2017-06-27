/*
** rotation.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/bonus/src/math/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat May 13 03:37:22 2017 Paul Laffitte
** Last update Sat May 13 17:43:39 2017 Paul Laffitte
*/

#include <math.h>
#include "math_gl.h"

static void	get_rotation_x(float rotation, float buffer[4][4])
{
  mat_identity(buffer);
  rotation = RAD(rotation);
  buffer[1][1] = cos(rotation);
  buffer[2][1] = -sin(rotation);
  buffer[1][2] = sin(rotation);
  buffer[2][2] = cos(rotation);
}

static void	get_rotation_y(float rotation, float buffer[4][4])
{
  mat_identity(buffer);
  rotation = RAD(rotation);
  buffer[0][0] = cos(rotation);
  buffer[2][0] = sin(rotation);
  buffer[0][2] = -sin(rotation);
  buffer[2][2] = cos(rotation);
}

static void	get_rotation_z(float rotation, float buffer[4][4])
{
  mat_identity(buffer);
  rotation = RAD(rotation);
  buffer[0][0] = cos(rotation);
  buffer[1][0] = -sin(rotation);
  buffer[0][1] = sin(rotation);
  buffer[1][1] = cos(rotation);
}

void		get_rotation(float rotation[3], float buffer[4][4])
{
  float		tmp[4][4];

  mat_identity(buffer);
  get_rotation_x(rotation[0], tmp);
  mat_product(buffer, tmp);
  get_rotation_y(rotation[1], tmp);
  mat_product(buffer, tmp);
  get_rotation_z(rotation[2], tmp);
  mat_product(buffer, tmp);
}

void		mat_rotate(float transform[4][4], float rotation[3])
{
  float		mat_rotation[4][4];

  get_rotation(rotation, mat_rotation);
  mat_product(transform, mat_rotation);
}
