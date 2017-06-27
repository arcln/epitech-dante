/*
** music.h for dante in /home/onehandedpenguin/Dev/AI_2016/dante/bonus/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May 11 19:46:33 2017 Paul Laffitte
** Last update Sun May 14 16:47:37 2017 Arthur Chaloin
*/

#ifndef MUSIC_H
#define MUSIC_H

# include <fmod.h>
# include "vector.h"

typedef struct		s_music
{
  t_vector		songs;
  FMOD_SYSTEM		*system;
  FMOD_SOUND		*song;
  FMOD_DSP		*dsp;
  FMOD_CHANNELGROUP	*channel;
}			t_music;

extern t_music		g_music;

float			get_spectrum();
int			start_music();

#endif /* !MUSIC_H */
