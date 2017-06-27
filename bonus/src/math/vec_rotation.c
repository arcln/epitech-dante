/*
** vec_rotation.c for dante in /Users/arthur/Documents/Dev/Epitech/B2/IA/dante/bonus/src/math/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat May 13 20:32:06 2017 Arthur Chaloin
** Last update Sun May 14 19:29:31 2017 Paul Laffitte
*/
#include <SFML/Graphics.h>
#include <math.h>

void		rotate_xyz(float to_rotate[3],
			   float center[3],
			   float angles[3])
{
  sfVector3f	tmp;

  angles[0] *= M_PI / 180.;
  angles[1] *= M_PI / 180.;
  angles[2] *= M_PI / 180.;
  to_rotate[0] -= center[0];
  to_rotate[1] -= center[1];
  to_rotate[2] -= center[2];
  tmp.y = to_rotate[1] * cos(angles[0]) + to_rotate[2] * -sin(angles[0]);
  tmp.z = to_rotate[1] * sin(angles[0]) + to_rotate[2] * cos(angles[0]);
  to_rotate[1] = tmp.y;
  to_rotate[2] = tmp.z;
  tmp.x = to_rotate[0] * cos(angles[1]) + to_rotate[2] * sin(angles[1]);
  tmp.z = to_rotate[0] * -sin(angles[1]) + to_rotate[2] * cos(angles[1]);
  to_rotate[0] = tmp.x;
  to_rotate[2] = tmp.z;
  tmp.x = to_rotate[0] * cos(angles[2]) + to_rotate[1] * -sin(angles[2]);
  tmp.y = to_rotate[0] * sin(angles[2]) + to_rotate[1] * cos(angles[2]);
  to_rotate[0] = tmp.x;
  to_rotate[1] = tmp.y;
  to_rotate[0] += center[0];
  to_rotate[1] += center[1];
  to_rotate[2] += center[2];
}
