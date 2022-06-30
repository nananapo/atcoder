#include <stdlib.h>
#include <stdio.h>

typedef int (*segop)(int, int);

typedef struct s_segtree
{
	int		size;
	int		*A;
	segop	op;
}	t_segtree;

static void	segtree_init_rec(t_segtree *t, int p)
{
	if (t->size - 1 <= p)
		return ;
	segtree_init_rec(t, (p + 1) * 2 - 1);
	segtree_init_rec(t, (p + 1) * 2);
	t->A[p] = t->op(t->A[(p + 1) * 2 - 1], t->A[(p + 1) * 2]);
}

t_segtree	*segtree_create(int size, int *init, segop op, int zero)
{
	int			i;
	int			n;
	t_segtree	*t;

	n = 1;
	while (n < size)
		n *= 2;
	t = malloc(sizeof(t_segtree));
	t->size = n;
	t->op = op;
	t->A = malloc((n * 2) * sizeof(int));
	i = -1;
	while (++i < size)
		t->A[i + t->size - 1] = init[i];
	while (i++ < t->size)
		t->A[i + t->size - 1] = zero;
	segtree_init_rec(t, 0);
	return (t);
}

static int	segtree_get_rec(t_segtree *t, int l, int r, int p, int pl, int pr)
{
	int	mid;

	if (l == pl && r == pr)
		return (t->A[p]);
	mid = pl + (pr - pl) / 2;
	if (mid >= r)
		return (segtree_get_rec(t, l, r, (p + 1) * 2 - 1, pl, mid));
	if (mid <= l)
		return (segtree_get_rec(t, l, r, (p + 1) * 2, mid, pr));
	return (segtree_get_rec(t, l, mid, (p + 1) * 2 - 1, pl, mid)
		+ segtree_get_rec(t, mid, r, (p + 1) * 2, mid, pr));
}

// l : include
// r : exclude
// 0 <= l < r <= t->size
int	segtree_get_range(t_segtree *t, int l, int r)
{
	return segtree_get_rec(t, l, r, 0, 0, t->size);
}

int	segtree_get(t_segtree *t, int p)
{
	return (t->A[p + t->size - 1]);
}

void	segtree_set(t_segtree *t, int p, int value)
{
	p = p + t->size - 1;
	if (t->A[p] == value)
		return ;
	t->A[p] = value;
	while (p != 0)
	{
		if (p % 2 == 0)
			p = p / 2 - 1;
		else
			p = p / 2;
		t->A[p] = t->op(t->A[(p + 1) * 2 - 1], t->A[(p + 1) * 2]);
	}
}

int	sum(int a, int b)
{
	return (a + b);
}

int	main(void)
{
	t_segtree	*t;
	int			init[] = {0,1,2,3,4,5,6,7,8,9};
	int			i;

	t = segtree_create(10, init, sum, 0);
	i = -1;
	while (++i < t->size)
	{
		printf("res1 %d\n", segtree_get_range(t, 0, i + 1));
		printf("res2 %d\n", segtree_get_range(t, i, t->size));
	}
	segtree_set(t, 11, 10);
	i = -1;
	while (++i < t->size)
	{
		printf("res3 %d\n", segtree_get_range(t, 0, i + 1));
		printf("res4 %d\n", segtree_get_range(t, i, t->size));
	}
}
