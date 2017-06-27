/*
** translation.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/bonus/src/math/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat May 13 03:37:16 2017 Paul Laffitte
** Last update Sat May 13 14:14:32 2017 Paul Laffitte
*/

#include "math_gl.h"

void	get_translation(float translation[3], float buffer[4][4])
{
  mat_identity(buffer);
  buffer[0][3] = translation[0];
  buffer[1][3] = translation[1];
  buffer[2][3] = translation[2];
}

void	mat_translate(float matrix[4][4], float translation[3])
{
  float	translation_matrix[4][4];

  get_translation(translation, translation_matrix);
  mat_product(matrix, translation_matrix);
}
