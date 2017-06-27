/*
** mousec for dante in /home/onehandedpenguin/Dev/AI_2016/dante/bonus/src/gtk/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat May 13 14:00:18 2017 Paul Laffitte
** Last update Mon May 15 20:00:02 2017 Arthur Chaloin
*/

#include <GLFW/glfw3.h>
#include <SFML/Window.h>

void		center_mouse(GLFWwindow *window,
			     int *x_offset_buffer,
			     int *y_offset_buffer)
{
  double		mouseX, mouseY;
  static double		centerX = 0, centerY = 0;

  glfwGetCursorPos(window, &mouseX, &mouseY);
  *y_offset_buffer = mouseX - centerX;
  *x_offset_buffer = mouseY - centerY;
  glfwGetCursorPos(window, &centerX, &centerY);
}
