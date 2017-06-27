/*
** inputs.c for g_corewar in /home/onehandedpenguin/Dev/CPE_2016/CPE_2016_corewar/bbw/src/gui/events/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Mar 21 20:31:03 2017 Paul Laffitte
** Last update Mon May 15 19:29:41 2017 Arthur Chaloin
*/

#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <SFML/Window.h>
#include "glfw.h"
#include "opengl.h"
#include "math_gl.h"

void		quit()
{
  glfwTerminate();
  exit(0);
}

static int	handle_keyboard()
{

  g_gl.cam.speed = ((sfKeyboard_isKeyPressed(sfKeyLShift)
		    || sfKeyboard_isKeyPressed(sfKeyRShift)) ? 3 : 1)
                    * CAM_SPEED;
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    cam_move(2, 1);
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    cam_move(0, 1);
  if (sfKeyboard_isKeyPressed(sfKeyS))
    cam_move(2, -1);
  if (sfKeyboard_isKeyPressed(sfKeyD))
    cam_move(0, -1);
  if (sfKeyboard_isKeyPressed(sfKeyL))
    {
      glfwTerminate();
      return (1);
    }
  if (sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      glfwTerminate();
      exit(0);
    }
  if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeySpace))
    {
      g_gl.cam.pos[1] += g_gl.cam.speed;
      g_gl.cam.look_at[1] += g_gl.cam.speed;
    }
  if (sfKeyboard_isKeyPressed(sfKeyDown)
      || sfKeyboard_isKeyPressed(sfKeyX)
      || sfKeyboard_isKeyPressed(sfKeyRControl)
      || sfKeyboard_isKeyPressed(sfKeyLControl))
    {
      g_gl.cam.pos[1] -= g_gl.cam.speed;
      g_gl.cam.look_at[1] -= g_gl.cam.speed;
    }
  return (0);
}

static void	handle_mouse(GLFWwindow *window)
{
  int		x_offset;
  int		y_offset;
  float		rotation[3];

  center_mouse(window, &x_offset, &y_offset);
  rotation[1] = -y_offset * CAM_SENS;
  rotation[0] = x_offset * CAM_SENS / 2
      * ((g_gl.cam.look_at[2] - g_gl.cam.pos[2] > 0) ? 1 : -1);
  rotation[2] = -x_offset * CAM_SENS / 2
      * ((g_gl.cam.look_at[0] - g_gl.cam.pos[0] > 0) ? 1 : -1);
  rotate_xyz(g_gl.cam.look_at, g_gl.cam.pos, rotation);
}

int		handle_events(GLFWwindow *window)
{
  if (handle_keyboard())
    return (1);
  handle_mouse(window);
  return (0);
}
