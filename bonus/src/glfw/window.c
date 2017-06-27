/*
** window.c for dante in /Users/arthur/Documents/Dev/Epitech/B2/IA/dante/bonus/src/glfw/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon May 15 18:22:41 2017 Arthur Chaloin
** Last update Mon May 15 19:41:42 2017 Arthur Chaloin
*/

#include <GLFW/glfw3.h>
#include "glfw.h"
#include "opengl.h"
#include "music.h"

int		open_window()
{
  GLFWwindow	*window;

  if (!glfwInit())
    return (1);
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  window = glfwCreateWindow(1920, 1080, "Dante", NULL, NULL);
  if (!window)
    {
      glfwTerminate();
      return (1);
    }
  glfwMakeContextCurrent(window);
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  init_gl();
  while (1)
    {
      if (handle_events(window))
	return (0);
      render_gl();
      glfwSwapBuffers(window);
    }
  return (0);
}
