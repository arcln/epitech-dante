/*
** video.h for dante in /Users/arthur/Dev/B2/IA/dante/bonus/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun Apr 23 19:31:24 2017 Arthur Chaloin
** Last update Mon Apr 24 13:09:45 2017 Arthur Chaloin
*/

#ifndef VIDEO_H_
# define VIDEO_H_

# define WIDTH	1000
# define HEIGHT	1000
# define V_MODE	sfResize | sfClose

# include <SFML/Graphics.h>
# include "maze.h"

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_video_data
{
  t_my_framebuffer	*fb;
  sfRenderWindow	*window;
  sfVideoMode		mode;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfEvent		event;
}			t_video;

void	video_init(t_video *video);
void	video_drawsquare(t_video *video, t_pos size, t_pos pos, sfColor color);

#endif /* !VIDEO_H_ */
