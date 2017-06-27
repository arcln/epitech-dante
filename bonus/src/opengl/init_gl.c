/*
** init_gl.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/3d/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sun Mar 26 21:51:56 2017 Paul Laffitte
** Last update Mon May 15 19:17:06 2017 Arthur Chaloin
*/

#include <stdio.h>
#include <GL/glew.h>
#include "glfw.h"
#include "opengl.h"
#include "math_gl.h"

t_gl	g_gl;
GLfloat	g_vertex_buffer_data[] = {
  -1.0f, -1.0f, -1.0f,
  -1.0f, -1.0f, 1.0f,
  -1.0f, 1.0f, 1.0f,
  1.0f, 1.0f, -1.0f,
  -1.0f, -1.0f, -1.0f,
  -1.0f, 1.0f, -1.0f,
  1.0f, -1.0f, 1.0f,
  -1.0f, -1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,
  1.0f, 1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,
  -1.0f, -1.0f, -1.0f,
  -1.0f, -1.0f, -1.0f,
  -1.0f, 1.0f, 1.0f,
  -1.0f, 1.0f, -1.0f,
  1.0f, -1.0f, 1.0f,
  -1.0f, -1.0f, 1.0f,
  -1.0f, -1.0f, -1.0f,
  -1.0f, 1.0f, 1.0f,
  -1.0f, -1.0f, 1.0f,
  1.0f, -1.0f, 1.0f,
  1.0f, 1.0f, 1.0f,
  1.0f, -1.0f, -1.0f,
  1.0f, 1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,
  1.0f, 1.0f, 1.0f,
  1.0f, -1.0f, 1.0f,
  1.0f, 1.0f, 1.0f,
  1.0f, 1.0f, -1.0f,
  -1.0f, 1.0f, -1.0f,
  1.0f, 1.0f, 1.0f,
  -1.0f, 1.0f, -1.0f,
  -1.0f, 1.0f, 1.0f,
  1.0f, 1.0f, 1.0f,
  -1.0f, 1.0f, 1.0f,
  1.0f, -1.0f, 1.0f
};
GLfloat	g_color_buffer_data[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
};

void		init_camera()
{
  g_gl.cam.pos[0] = 0;
  g_gl.cam.pos[1] = 0;
  g_gl.cam.pos[2] = -30;
  g_gl.cam.look_at[0] = 0;
  g_gl.cam.look_at[1] = -20;
  g_gl.cam.look_at[2] = 0;
  g_gl.cam.fov = 60.0f;
}

static int	init_aux()
{
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK || (g_gl.shader
	       = load_shaders(SHDR_SIMPLE_VERT, SHDR_SIMPLE_FRAG)) == 0)
    {
      dprintf(2, "Failed to init OpenGL.\n");
      return (-1);
    }
  init_camera();
  g_gl.matrix_id = glGetUniformLocation(g_gl.shader, "MVP");
  g_gl.vertex_buffer = 0;
  return (0);
}

void		init_gl()
{
  GLuint	vertex_array_id;
  static int	call = 0;

  if (init_aux() || call)
    return;
  glGenVertexArrays(1, &vertex_array_id);
  glBindVertexArray(vertex_array_id);
  glGenBuffers(1, &g_gl.colorbuffer);
  glGenBuffers(1, &g_gl.vertex_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, g_gl.vertex_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
	       g_vertex_buffer_data, GL_STATIC_DRAW);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glClearColor(0, 0, 0, 1);
  glUseProgram(g_gl.shader);
  call = 1;
}
