/*
** opengl.h for dante in /home/onehandedpenguin/Dev/AI_2016/dante/bonus/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May 11 18:49:32 2017 Paul Laffitte
** Last update Mon May 15 19:19:41 2017 Arthur Chaloin
*/

#ifndef OPENGL_H_
# define OPENGL_H_

# include "platform.h"
# include "dante.h"

# ifndef NEAR
#  define NEAR 0.1
# endif /* !NEAR */

# ifndef FAR
#  define FAR 1000.0
# endif /* !FAR */

# ifndef MUSIC_FOLDER
#  define MUSIC_FOLDER "./res/music/"
# endif /* !MUSIC_FOLDER */

# ifndef SHDR_SIMPLE_VERT
#  define SHDR_SIMPLE_VERT "./src/opengl/shaders/simple.vert"
# endif /* !SHDR_SIMPLE_VERT */

# ifndef SHDR_SIMPLE_FRAG
#  define SHDR_SIMPLE_FRAG "./src/opengl/shaders/simple.frag"
# endif /* !SHDR_SIMPLE_FRAG */

# ifndef CAM_SPEED
#  define CAM_SPEED 1
# endif /* !CAM_SPEED */

# ifndef CAM_SENS
#  define CAM_SENS 0.1
# endif /* !CAM_SENS */

# include <GLFW/glfw3.h>

# ifdef MACOS
#  include <OpenGL/gl.h>
# else
#  include <GL/gl.h>
# endif

typedef struct	s_cam
{
  float		pos[3];
  float		look_at[3];
  float		fov;
  float		speed;
}		t_cam;

typedef struct	s_gl
{
  GLuint	vertex_buffer;
  GLuint	shader;
  GLuint	matrix_id;
  GLuint	colorbuffer;
  t_cam		cam;
  float		mvp[4][4];
}		t_gl;

extern t_gl	g_gl;
extern GLfloat	g_color_buffer_data[3 * 36];
extern t_dante  g_dante;

void		init_gl();
void		render_gl();

GLuint		load_shaders(const char *vertex_filename,
			     const char *fragment_filename);

void		move_to(float position[3], float smooth);
void		cam_move(int axis, int dir);

void		model_mat(int index, int index2, float moy);
int		model_color(int posY, int posX, float moy);

#endif /* !OPENGL_H_ */
