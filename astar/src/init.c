/*
** init.c for dante in /home/onehandedpenguin/dante/astar/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May  4 17:46:11 2017 Paul Laffitte
** Last update Fri May  5 12:36:00 2017 Paul Laffitte
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char		**astar_init_source(char **tab)
{
  int		index;
  int		len;
  char		**new;

  index = -1;
  while (tab[++index]);
  len = index;
  if (!(new = malloc(sizeof(char **) * (len + 1))))
    return (NULL);
  index = -1;
  while (tab[++index])
    new[index] = strdup(tab[index]);
  new[index] = NULL;
  return (new);
}
