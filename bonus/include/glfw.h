/*
** gtk.h for dante in /home/onehandedpenguin/Dev/AI_2016/dante/bonus/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May 11 18:49:32 2017 Paul Laffitte
** Last update Mon May 15 19:21:58 2017 Arthur Chaloin
*/

#ifndef GLFW_H_
# define GLFW_H_

#include <GLFW/glfw3.h>

int		open_window();
void		center_mouse(GLFWwindow *window,
			     int *x_offset_buffer,
			     int *y_offset_buffer);
int		handle_events(GLFWwindow *);
void		quit();

#endif /* !GLFW_H_ */
