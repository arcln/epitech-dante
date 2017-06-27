/*
** load_shader.c for corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/3d/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Mon Mar 27 17:41:17 2017 Paul Laffitte
** Last update Mon May 15 19:14:31 2017 Arthur Chaloin
*/

#include "platform.h"
#ifdef MACOS
# include <GL/glew.h>
# include <OpenGL/gl.h>
#else
# include <GL/glew.h>
# include <GL/gl.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "glfw.h"

static void	error_shader(GLuint shader_id)
{
  GLint		result;
  int		error_len;
  char		*message;

  result = GL_FALSE;
  error_len = 0;
  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
  glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &error_len);
  if (error_len > 0 && (message = malloc(sizeof(char) * (error_len + 1))))
    {
      glGetShaderInfoLog(shader_id, error_len, NULL, message);
      dprintf(2, "%s", message);
      free(message);
    }
  else if (error_len > 0)
    dprintf(2, "Shaders: An error occured with a shader\n");
}

static void	error_program(GLuint program_id)
{
  GLint		result;
  int		error_len;
  char		*message;

  result = GL_FALSE;
  error_len = 0;
  glGetShaderiv(program_id, GL_LINK_STATUS, &result);
  glGetShaderiv(program_id, GL_INFO_LOG_LENGTH, &error_len);
  if (error_len > 0 && (message = malloc(sizeof(char) * (error_len + 1))))
    {
      glGetShaderInfoLog(program_id, error_len, NULL, message);
      dprintf(2, "%s", message);
      free(message);
    }
  else if (error_len > 0)
    dprintf(2, "Shaders: An error occured with a program\n");
}

static int	load_shader(const char *filename, GLuint shader_id)
{
  int		fd;
  GLchar	*source;
  int		len;

  if ((fd = open(filename, O_RDONLY)) < 0
      || !(source = malloc(sizeof(GLchar) * 10000))
      || (len = read(fd, source, 9999)) < 0)
    return (-1);
  source[len] = '\0';
  close(fd);
  glShaderSource(shader_id, 1, (const GLchar **)&source, NULL);
  glCompileShader(shader_id);
  error_shader(shader_id);
  return (0);
}

GLuint		load_shaders(const char *vertex_file,
			     const char *fragment_file)
{
  GLuint	program_id;
  GLuint	vertex_id;
  GLuint	fragment_id;

  vertex_id = glCreateShader(GL_VERTEX_SHADER);
  fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
  program_id = glCreateProgram();
  if (load_shader(vertex_file, vertex_id) == -1)
    dprintf(2, "Could not read the vertex shader '%s'\n", vertex_file);
  if (load_shader(fragment_file, fragment_id) == -1)
    dprintf(2, "Could not read the fragment shader '%s'\n", fragment_file);
  glAttachShader(program_id, vertex_id);
  glAttachShader(program_id, fragment_id);
  glLinkProgram(program_id);
  error_program(program_id);
  glDetachShader(program_id, vertex_id);
  glDetachShader(program_id, fragment_id);
  glDeleteShader(vertex_id);
  glDeleteShader(fragment_id);
  return (program_id);
}
