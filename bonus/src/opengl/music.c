/*
** music.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/bonus/src/opengl/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May 11 19:36:16 2017 Paul Laffitte
** Last update Sun May 14 22:51:27 2017 Paul Laffitte
*/

#define _GNU_SOURCE
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <fmod.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "opengl.h"
#include "vector.h"
#include "music.h"

t_music		g_music;

static char	*get_next_music(t_vector *files)
{
  char		*choice;
  int		vector_size;

  if ((vector_size = vector_getsize(files)) < 3)
    return (NULL);
  asprintf(&choice, "%s%s", MUSIC_FOLDER,
	   (VECTOR_GET(files, rand() % vector_size,
		       struct dirent))->d_name);
  return (choice);
}

static char	*get_music()
{
  DIR		*dir;
  struct dirent	*file;
  t_vector	files;
  char		*choice;

  vector_init(&files);
  if (!(dir = opendir(MUSIC_FOLDER)))
    return (NULL);
  while ((file = readdir(dir)))
    VECTOR_PUSH(&files, (void *)file);
  while ((choice = get_next_music(&files))
	 && choice[strlen(MUSIC_FOLDER)] == '.');
  return (choice);
}

int	start_music()
{
  char	*music;

  if (!(music = get_music()))
    return (1);
  FMOD_System_Create(&(g_music.system));
  FMOD_System_Init(g_music.system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(g_music.system, music,
			  FMOD_2D | FMOD_CREATESTREAM, 0, &(g_music.song));
  FMOD_System_PlaySound(g_music.system, g_music.song, 0, 0, NULL);
  FMOD_System_GetMasterChannelGroup(g_music.system, &(g_music.channel));
  FMOD_System_CreateDSPByType(g_music.system,
			      FMOD_DSP_TYPE_FFT, &(g_music.dsp));
  return (0);
}

float				get_spectrum(int index)
{
  FMOD_DSP_PARAMETER_FFT	*fft;

  FMOD_ChannelGroup_AddDSP(g_music.channel, 0, g_music.dsp);
  FMOD_DSP_GetParameterData(g_music.dsp, FMOD_DSP_FFT_SPECTRUMDATA,
			    (void *)&fft, 0, 0, 0);
  return ((fft->length > g_dante.maze.width)
	  ? fft->spectrum[0][index % (g_dante.maze.width)] * 25. : 0.);
}
