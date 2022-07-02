#include <stdlib.h>
#include <stdio.h>

typedef void *(t_segop)(void *, void *);

typedef struct s_segtree
{
	int		size;
	void	**A;
	t_segop	*op;
}	t_segtree;

void	segtree_init_rec(t_segtree *t, int p)
{
	if (p >= t->size - 1)
		return ;
	segtree_init_rec(t, (p + 1) * 2 - 1);
	segtree_init_rec(t, (p + 1) * 2);
	t->A[p] = t->op(t->A[(p + 1) * 2 - 1], t->A[(p + 1) * 2]);
}

t_segtree	*segtree_create(int size, void **init, t_segop op, void *zero)
{
	t_segtree	*t;
	int			n;
	int			i;

	n = 1;
	while (n < size)
		n *= 2;
	t = malloc(sizeof(t_segtree));
	t->size = n;
	t->A = malloc(sizeof(void *) * t->size * 2);
	t->op = op;
	i = -1;
	while (++i < size)
		t->A[i + (t->size - 1)] = init[i];
	i--;
	while (++i < t->size)
		t->A[i + (t->size - 1)] = zero;
	segtree_init_rec(t, 0);
	return (t);
}

void	segtree_set(t_segtree *t, int i, void *value)
{
	if (t->A[t->size - 1 + i] == value)
		return ;
	t->A[t->size - 1 + i] = value;
	while (i > 0)
	{
		if (i % 2 == 0)
			i = i / 2 - 1;
		else
			i = i / 2;
		t->A[i] = t->op(t->A[(i + 1) * 2 - 1], t->A[(i + 1) * 2]);
	}
}

void	*segtree_get(t_segtree *t, int i)
{
	return (t->A[i + t->size - 1]);
}

void	*segtree_get_range_rec(t_segtree *t, int l, int r, int p, int pl, int pr)
{
	int	mid;

	if (l == pl && r == pr)
		return (t->A[p]);
	mid = pl + (pr - pl) / 2;
	if (r <= mid)
		return (segtree_get_range_rec(t, l, r, (p + 1) * 2 - 1, pl, mid));
	if (mid <= l)
		return (segtree_get_range_rec(t, l, r, (p + 1) * 2, mid, pr));
	return (t->op(segtree_get_range_rec(t, l, mid, (p + 1) * 2 - 1, pl, mid),
		segtree_get_range_rec(t, mid, r, (p + 1) * 2, mid, pr)));
}

// l : include
// r : exclude
// 0 <= l < r <= t->size
void	*segtree_get_range(t_segtree *t, int l, int r)
{
	return (segtree_get_range_rec(t, l, r, 0, 0, t->size));
}


void	*sum(void *a, void *b)
{
	int	*p;

	p = malloc(sizeof(int));
	*p = *(int *)a + *(int *)b;
	return (p);
}

int main(void)
{}

