/*
** vector.h for vector in /home/arbona/libs/vector
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Feb 27 19:44:11 2017 Thomas ARBONA
** Last update Sun Apr 23 19:24:55 2017 Arthur Chaloin
*/
#ifndef VECTOR_H_
# define VECTOR_H_

typedef struct	s_vector
{
  void		**items;
  int		capacity;
  int		size;
}		t_vector;

int	vector_init(t_vector*);
int	vector_resize(t_vector*, int);
void	vector_free(t_vector*);
int	vector_getsize(t_vector*);
void	vector_delete(t_vector*, int);
void	vector_foreach(t_vector*, void (*)(void*, int));
void	vector_sort(t_vector*, int (*)(void*, void*));
void	_vector_set(t_vector*, int, void*);
void	*_vector_get(t_vector*, int);
void	_vector_push(t_vector*, void*);
void	vector_prepend(t_vector *v, void *elem);

# define VECTOR_INIT_CAPACITY	4

# define VECTOR_SET(v, i, item)	(_vector_set(v, i, (void*)item))
# define VECTOR_GET(v, i, type)	((type*)_vector_get(v, i))
# define VECTOR_PUSH(v, item)	(_vector_push(v, (void*)item))

#endif /* !VECTOR_H_ */
