/*
** render_gl.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/bonus/src/opengl/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May 11 19:54:15 2017 Paul Laffitte
** Last update Mon May 15 19:21:19 2017 Arthur Chaloin
*/

#include "platform.h"
#ifdef MACOS
# include <GL/glew.h>
# include <OpenGL/gl.h>
#else
# include <GL/glew.h>
# include <GL/gl.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <SFML/Window.h>
#include "lib/math_3d.hh"
#include "glfw.h"
#include "opengl.h"
#include "math_gl.h"
#include "music.h"

static void	mat_perspective(float ratio)
{
  static int	call = 0;
  static mat4_t proj;

  if (!call)
    {
      proj = m4_perspective(g_gl.cam.fov, ratio, 1, FAR);
      call = 1;
    }
  memcpy(g_gl.mvp, &proj, sizeof(float) * 4 * 4);
}

static void	mat_view()
{
  mat4_t view;

  view = m4_look_at((vec3_t) {
		    g_gl.cam.pos[0], g_gl.cam.pos[1], g_gl.cam.pos[2]
		    }, (vec3_t) {
		    g_gl.cam.look_at[0], g_gl.cam.look_at[1], g_gl.cam.look_at[2]
		    }, (vec3_t) {
		    0, 1, 0
		    });
  mat_product(g_gl.mvp, view.m);
}

static void	handle_cube(int index, int index2)
{
  float		moy;

  moy = (get_spectrum(index * g_dante.maze.width + index2) / 3) + 1;
  if (model_color(index, index2, moy))
    {
      mat_perspective(1850. / 1080.);
      mat_view();
      model_mat(index, index2, moy);
      glUniformMatrix4fv(g_gl.matrix_id, 1, GL_FALSE, (float *)g_gl.mvp);
      glBindBuffer(GL_ARRAY_BUFFER, g_gl.vertex_buffer);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
      glBindBuffer(GL_ARRAY_BUFFER, g_gl.colorbuffer);
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
      glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
    }
}

void		render_gl()
{
  int		index;
  int		index2;
  static int	ret = 0;

  if (!ret)
    ret = g_dante.algo.update(g_dante.algo.data);
  index = -1;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  index = -1;
  while (++index < g_dante.maze.height)
    {
      index2 = -1;
      while (++index2 < g_dante.maze.width)
	handle_cube(index, index2);
    }
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}
