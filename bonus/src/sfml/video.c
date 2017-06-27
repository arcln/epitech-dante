/*
** video.c for wolf3d in /home/arthur/Documents/B1-C_Graph_Prog/wolf3d/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Dec 12 09:26:23 2016 Arthur Chaloin
** Last update Fri Jun  2 21:52:24 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "video.h"

static inline void	put_pixel(t_my_framebuffer *fb,
		          int x, int y, sfColor color)
{
  unsigned int	*pixel;

  if (x < 0 || y < 0 || x >= fb->width || y >= fb->height)
    return;
  pixel = (void *)&(fb->pixels[(fb->width * y + x) * 4]);
  *pixel = (color.a << 24) + (color.b << 16) + (color.g << 8) + color.r;
}

static t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			cursor;
  t_my_framebuffer	*buffer;

  if (!(buffer = malloc(sizeof(t_my_framebuffer))) ||
      !(buffer->pixels = malloc(sizeof(sfUint8) * (width * height * 4))))
    return (NULL);
  buffer->width = width;
  buffer->height = height;
  cursor = 0;
  while (cursor < width * height * 4)
    {
      buffer->pixels[cursor] = 0;
      cursor++;
    }
  return (buffer);
}

void		video_init(t_video *video)
{
  video->mode.width = WIDTH;
  video->mode.height = HEIGHT;
  video->mode.bitsPerPixel = 32;
  video->fb = my_framebuffer_create(video->mode.width, video->mode.height);
  video->texture = sfTexture_create(WIDTH, HEIGHT);
  video->sprite = sfSprite_create();
  sfSprite_setTexture(video->sprite, video->texture, sfTrue);
}
