/*
** graph.c for dante in /home/onehandedpenguin/Dev/AI_2016/dante/astar/src/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May  4 20:34:51 2017 Paul Laffitte
** Last update Fri May  5 12:18:56 2017 Paul Laffitte
*/

#include "astar.h"

t_solver	*graph_set(t_astar *astar, t_solver *parent, int x, int y)
{
  t_solver	*solver;

  solver = &astar->graph[GRAPH_INDEX(astar->maze->width, x, y)];
  solver->pos = POS(x, y);
  solver->parent = parent;
  return (solver);
}
