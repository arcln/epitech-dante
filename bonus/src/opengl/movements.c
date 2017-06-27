/*
** load_shader.c for g_corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/3d/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Mon Mar 27 17:41:17 2017 Paul Laffitte
** Last update Sun May 14 23:45:46 2017 Paul Laffitte
*/

#include <stdlib.h>
#include "opengl.h"
#include "math_gl.h"

void		move_to(float position[3], float smooth)
{
  smooth *= smooth;
  g_gl.cam.pos[0] = (smooth * g_gl.cam.pos[0] + position[0]) / (smooth + 1);
  g_gl.cam.pos[1] = (smooth * g_gl.cam.pos[1] + position[1]) / (smooth + 1);
  g_gl.cam.pos[2] = (smooth * g_gl.cam.pos[2] + position[2]) / (smooth + 1);
}

void		cam_move(int axis, int dir)
{
  float		vec_speed[3];
  float		euler[3];
  float		len;

  vec_cpy(g_gl.cam.look_at, euler);
  if (axis == 0)
    rotate_xyz(euler, g_gl.cam.pos, (float [3]) {0, 90, 0});
  vec_speed[0] = euler[0] - g_gl.cam.pos[0];
  vec_speed[1] = 0;
  vec_speed[2] = euler[2] - g_gl.cam.pos[2];
  len = sqrt(SQUARE(vec_speed[0])
	     + SQUARE(vec_speed[1]) + SQUARE(vec_speed[2]));
  vec_speed[0] /= len;
  vec_speed[1] /= len;
  vec_speed[2] /= len;
  g_gl.cam.pos[0] += g_gl.cam.speed * vec_speed[0] * dir;
  g_gl.cam.pos[1] += g_gl.cam.speed * vec_speed[1] * dir;
  g_gl.cam.pos[2] += g_gl.cam.speed * vec_speed[2] * dir;
  g_gl.cam.look_at[0] += g_gl.cam.speed * vec_speed[0] * dir;
  g_gl.cam.look_at[1] += g_gl.cam.speed * vec_speed[1] * dir;
  g_gl.cam.look_at[2] += g_gl.cam.speed * vec_speed[2] * dir;
}
