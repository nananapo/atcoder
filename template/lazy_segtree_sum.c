#include <stdlib.h>
#include <stdio.h>

typedef struct s_lsegtree
{
	int		size;
	int		*A;
	int		*B;
}	t_lsegtree;

static void	lsegtree_create_init_rec(t_lsegtree *t, int p)
{
	if (p >= t->size - 1)
		return ;
	lsegtree_create_init_rec(t, (p + 1) * 2 - 1);
	lsegtree_create_init_rec(t, (p + 1) * 2);
	t->A[p] = t->A[(p + 1) * 2 - 1] + t->A[(p + 1) * 2];
}

t_lsegtree	*lsegtree_create(int size, int *init, int zero)
{
	int			n;
	t_lsegtree	*t;

	n = 1;
	while (n < size)
		n *= 2;
	t = malloc(sizeof(t_lsegtree));
	t->size = n;
	t->A = calloc(sizeof(int), t->size * 2);
	t->B = calloc(sizeof(int), t->size * 2);
	n = -1;
	while (++n < size)
		t->A[n + (t->size - 1)] = init[n];
	n--;
	while (++n < t->size)
		t->A[n + (t->size - 1)] = zero;
	lsegtree_create_init_rec(t, 0);
	return (t);
}

static void	lsegtree_update(t_lsegtree *t, int p)
{
	if (t->B[p] != 0)
	{
		t->A[p] += t->B[p];
		if (p < t->size - 1)
		{
			t->B[(p + 1) * 2 - 1] += t->B[p] / 2;
			t->B[(p + 1) * 2] += t->B[p] / 2;
		}
		t->B[p] = 0;
	}
}

int	lsegtree_get_range_rec(t_lsegtree *t, int l, int r, int p, int pl, int pr)
{
	int	mid;

	lsegtree_update(t, p);
	if (l == pl && r == pr)
		return (t->A[p]);
	mid = pl + (pr - pl) / 2;
	printf("g %d %d %d %d %d %d\n", l, r, p, pl, pr, mid);

	if (r <= mid)
		return (lsegtree_get_range_rec(t, l, r, (p + 1) * 2 - 1, pl, mid));
	if (mid <= l)
		return (lsegtree_get_range_rec(t, l, r, (p + 1) * 2, mid, pr));
	return (lsegtree_get_range_rec(t, l, mid, (p + 1) * 2 - 1, pl, mid)
		+ lsegtree_get_range_rec(t, mid, r, (p + 1) * 2, mid, pr));
}

int	lsegtree_get_range(t_lsegtree *t, int l, int r)
{
	return (lsegtree_get_range_rec(t, l, r, 0, 0, t->size));
}

void	lsegtree_add_range_rec(t_lsegtree *t, int l, int r, int x, int p, int pl, int pr)
{
	int	mid;

	lsegtree_update(t, p);

	if (l == pl && r == pr)
	{
		t->B[p] += (pr - pl) * x;
		lsegtree_update(t, p);
		return ;
	}
	mid = pl + (pr - pl) / 2;
	if (r <= mid)
		lsegtree_add_range_rec(t, l, r, x, (p + 1) * 2 - 1, pl, mid);
	else if (mid <= l)
		lsegtree_add_range_rec(t, l, r, x, (p + 1) * 2, mid, pr);
	else
	{
		lsegtree_add_range_rec(t, l, mid, x, (p + 1) * 2 - 1, pl, mid);
		lsegtree_add_range_rec(t, mid, r, x, (p + 1) * 2, mid, pr);
	}
	t->A[p] = t->A[(p + 1) * 2 - 1] + t->A[(p + 1) * 2];
}

void	lsegtree_add_range(t_lsegtree *t, int l, int r, int x)
{
	lsegtree_add_range_rec(t, l, r, x, 0, 0, t->size);
}

int main()
{
	t_lsegtree	*t;
	int			init[] = {0,1,2,3,4,5,6,7,8,9};
	int			i;
	
	t = lsegtree_create(10, init, 0);
	i = 0;
	lsegtree_add_range(t, 0, 3, 1);
	lsegtree_add_range(t, 3, 8, 1);
	lsegtree_add_range(t, 8, 10, 1);
	while (++i <= 10)
	{
		printf("r %d\n", lsegtree_get_range(t, 0, i));
	}
}
