/*
** dante.c for dante in /Users/arthur/Documents/Dev/B2/IA/dante/bonus/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Apr 24 12:05:15 2017 Arthur Chaloin
** Last update Fri Jun  2 21:56:26 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dante.h"

static int	poll_events(t_video *video)
{
  while (sfRenderWindow_pollEvent(video->window, &video->event))
    {
      if (video->event.type == sfEvtClosed ||
	  (video->event.type == sfEvtKeyPressed &&
	   video->event.key.code == sfKeyEscape))
	exit(0);
      else if ((video->event.type == sfEvtKeyPressed &&
		video->event.key.code == sfKeyL))
	{
	  sfRenderWindow_close(video->window);
	  return (1);
	}
    }
  return (0);
}

static sfColor	get_color(t_dante *dante, t_maze *maze, int x, int y)
{
  sfColor	color;

  if (maze->data[y][x] == 'X')
    color = (sfColor){142, 142, 142, 255};
  else if (maze->data[y][x] == 'o')
    color = (sfColor){42, 200, 42, 255};
  else if ((*((char ***)(dante->algo.data)))[y][x] != 'X'
	   && (*((char ***)(dante->algo.data)))[y][x] != '*')
    color = (sfColor){100, 100, 200, 255};
  else
    color = (sfColor){255, 255, 255, 255};
  return (color);
}

static void	update_video(t_dante *dante, t_maze *maze)
{
  int		index;
  int		index2;

  index = -1;
  sfRenderWindow_clear(dante->video.window, sfBlack);
  memset(dante->video.fb->pixels, 0, WIDTH * HEIGHT * 4);
  while ((*((char ***)(dante->algo.data)))[++index])
    {
      index2 = -1;
      while ((*((char ***)(dante->algo.data)))[index][++index2])
	{
	    video_drawsquare(&dante->video, (t_pos) {
			     (WIDTH / maze->width),
			     (HEIGHT / maze->height),
			     }, (t_pos) {
			     (WIDTH / maze->width) * index2,
			     (HEIGHT / maze->height) * index,
			     }, get_color(dante, maze, index2, index));
	}
    }
  sfTexture_updateFromPixels(dante->video.texture, dante->video.fb->pixels,
			     WIDTH, HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(dante->video.window, dante->video.sprite, NULL);
  sfRenderWindow_display(dante->video.window);
}

int		dante_start(t_dante *dante, t_maze *maze)
{
  int		ret;

  sfRenderWindow_pollEvent(dante->video.window, &dante->video.event);
  while (!(ret = dante->algo.update(dante->algo.data)))
    {
      update_video(dante, maze);
      if (poll_events(&dante->video))
	return (0);
    }
  while (1)
    {
      update_video(dante, maze);
      if (poll_events(&dante->video))
	return (0);
    }
  return (0);
}
